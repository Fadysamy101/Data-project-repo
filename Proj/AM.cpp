#include "AM.h"
#include "ES.h"
#include "ET.h"
#include <cmath>
#include "Game.h"
#include<iostream>

AM::AM(int id, int jt, int h, int p, int ac):unit(id,"Alien Monster", jt, h, p, ac)
{
}

void AM::attack() 
{
    LinkedQueue<ES*> AttES;
    LinkedQueue<ET*> AttET;
    //AM* amptr = this;
    ES* EnemyES = nullptr;
    ET* EnemyET = nullptr;

    int count1 = getgame()->getEarth()->getES().getLength();
    int count2 = getgame()->getEarth()->getET().getLength();

    int cap = getAttCap();

    bool ATTACKERENQ = false;

    for (int i = 0; i < cap; i++) {

        
            if (count1!=0&&i%2==0)
            {

                getgame()->getEarth()->removeESoldier(EnemyES);
                int UAP = ((this->getPower() * (this->getHealth() / 100.00)) / sqrt(EnemyES->getHealth()));

                EnemyES->decrementHealth(UAP);

                getSHOT()->enqueue(EnemyES->getID());
                if (!ATTACKERENQ)
                {
                    ATTACKERENQ = true;
                    getgame()->getAlien()->getAttackerList()->enqueue(this);
                }

                if (EnemyES->getTA() == 0)
                    EnemyES->setTa(getgame()->gettime());
                if (EnemyES->CheckInjured())
                    getgame()->getUML()->enqueue(EnemyES, EnemyES->getHealth());
                else if (EnemyES->CheckAlive())
                {
                    AttES.enqueue(EnemyES);
                }
                else
                {
                    EnemyES->setTD(getgame()->gettime());
                    getgame()->AddtoKilledList(EnemyES);
                }
                count1--;
            }
            else if (count2)
            {
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
                else
                {
                    EnemyET->setTD(getgame()->gettime());
                    getgame()->AddtoKilledList(EnemyET);
                }
                count2--;
            }
        
    }


    while (AttET.dequeue(EnemyET)) {
        getgame()->getEarth()->addEunit(EnemyET);
    }

    while (AttES.dequeue(EnemyES)) {
        getgame()->getEarth()->addEunit(EnemyES);
    }

};
