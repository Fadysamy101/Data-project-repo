#include "AD.h"
#include "EG.h"
#include "ET.h"
#include <cmath>
#include "Game.h"
#include<iostream>
AD::AD(int id, int jt, int h, int p, int ac) :unit(id, "Alien Drone", jt, h, p, ac)
{
}
void AD::attack() {
    LinkedQueue<ET*> AttET;
    LinkedQueue<EG*> AttEG;

    ET* EnemyET = nullptr;
    EG* EnemyEG = nullptr;

    int count1 = getgame()->getEarth()->getEG()->getLength();
    int count2 = getgame()->getEarth()->getET().getLength();

    int cap = getAttCap();

    bool ATTACKERENQ = false;

    for (int i = 0; i < cap; i++) {

        if (i % 2 == 0 || !count2) {
            if (count1) {
                int pri;
                getgame()->getEarth()->removeGunnery(EnemyEG, pri);
                int UAP = (this->getPower() * (this->getHealth() / 100.0)) / sqrt(EnemyEG->getHealth());

                EnemyEG->decrementHealth(UAP);

                getSHOT()->enqueue(EnemyEG->getID());
                if (!ATTACKERENQ)
                {
                    ATTACKERENQ = true;
                    getgame()->getAlien()->getAttackerList()->enqueue(this);
                }

                if (EnemyEG->getTA() == 0)
                    EnemyEG->setTa(getgame()->gettime());
                if (EnemyEG->CheckAlive())
                    AttEG.enqueue(EnemyEG);
                else
                {
                    EnemyEG->setTD(getgame()->gettime());
                    getgame()->AddtoKilledList(EnemyEG);
                }
                count1--;
                continue;
            }
        }
        {
            if (count2) {
                getgame()->getEarth()->removeTank(EnemyET);
                int UAP = ((this->getPower() * (this->getHealth() / 100.00)) / sqrt(EnemyET->getHealth()));

                EnemyET->decrementHealth(UAP);

                getSHOT()->enqueue(EnemyET->getID());
                if (!ATTACKERENQ)
                {
                    ATTACKERENQ = true;
                    getgame()->getAlien()->getAttackerList()->enqueue(this);
                }

                if (EnemyET->getTA() == 0)
                    EnemyET->setTa(getgame()->gettime());
                if (EnemyET->CheckInjured())
                    getgame()->getUML()->enqueue(EnemyET, 0);
                else if (EnemyET->CheckAlive())
                {
                    AttET.enqueue(EnemyET);
                }
                else {
                    EnemyET->setTD(getgame()->gettime());
                    getgame()->AddtoKilledList(EnemyET);
                    }
                count2--;
            }
        }
    }


    while (AttET.dequeue(EnemyET)) {
        getgame()->getEarth()->addEunit(EnemyET);
    }

    while (AttEG.dequeue(EnemyEG)) {
        getgame()->getEarth()->addEunit(EnemyEG);
    }
}
