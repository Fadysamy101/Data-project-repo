#pragma once
#include "EG.h"
#include"unit.h"
#include <iostream>
#include <iostream>
#include "Game.h"

EG::EG(int id, int jt, int h, int p, int ac):unit(id, "Earth Gunner", jt, h, p, ac)
{
	setP_H();
}

int EG::rndm(int n) {
    return (rand() % n);
}

int EG::getP_H()
{
	return Power_health;
}

void EG::setP_H()
{
	Power_health = (getPower() + getHealth()) / 2;
}
void EG::attack() {

    srand(time(0));

    Arr_Bag<AM*> AttAM;
    DervQueue<AD*> AttAD;

    AM* EnemyAM = nullptr;
 

    int count1 = getgame()->getAlien()->getArr().getLength();
    int count2 = getgame()->getAlien()->getAD().getLength();

    int cap = getAttCap();

    bool ATTACKERENQ = false;

    for (int i = 0; i < cap; i++) {

 
            if ((count1!=0) && (i % 2 == 0)) {
                int RR = rndm(count1);
                getgame()->getAlien()->removeMonster(EnemyAM,RR);
                int UAP = (this->getPower() * (this->getHealth() / 100.0)) / sqrt(EnemyAM->getHealth());

                EnemyAM->decrementHealth(UAP);

                getSHOT()->enqueue(EnemyAM->getID());
                if (!ATTACKERENQ)
                {
                    ATTACKERENQ = true;
                    getgame()->getEarth()->getAttackerList()->enqueue(this);
                }

                if (EnemyAM->getTA() == 0)
                    EnemyAM->setTa(getgame()->gettime());
                
                if (EnemyAM->CheckAlive())
                    AttAM.add(EnemyAM);
                else
                {
                    EnemyAM->setTD(getgame()->gettime());
                    getgame()->AddtoKilledList(EnemyAM);
                }
                count1--;
            }
        
            else if (count2 == 1)
            {
                AD* EnemyAD1 = nullptr;
                getgame()->getAlien()->remove_Frnt_Drone(EnemyAD1);
                int UAP1 = ((this->getPower() * (this->getHealth() / 100.00)) / sqrt(EnemyAD1->getHealth()));
                EnemyAD1->decrementHealth(UAP1);

                getSHOT()->enqueue(EnemyAD1->getID());
                if (!ATTACKERENQ)
                {
                    ATTACKERENQ = true;
                    getgame()->getEarth()->getAttackerList()->enqueue(this);
                }

                if (EnemyAD1->getTA() == 0)
                    EnemyAD1->setTa(getgame()->gettime());
                if (EnemyAD1->CheckAlive())
                    AttAD.enqueue(EnemyAD1);
                else if (EnemyAD1->getHealth() == 0)
                {
                    EnemyAD1->setTD(getgame()->gettime());
                    getgame()->AddtoKilledList(EnemyAD1);
                }
                count2--;
            }
            else if (count2!=1 && count2!=0) 
            {
                AD* EnemyAD1 = nullptr;
                AD* EnemyAD2 = nullptr;
                getgame()->getAlien()->remove_Frnt_Drone(EnemyAD1);
                getgame()->getAlien()->remove_Bck_Drone(EnemyAD2);

                int UAP1 = ((this->getPower() * (this->getHealth() / 100.00)) / sqrt(EnemyAD1->getHealth()));
                int UAP2= ((this->getPower() * (this->getHealth() / 100.00)) / sqrt(EnemyAD2->getHealth()));
                EnemyAD1->decrementHealth(UAP1);

                getSHOT()->enqueue(EnemyAD1->getID());
                if (!ATTACKERENQ)
                {
                    ATTACKERENQ = true;
                    getgame()->getEarth()->getAttackerList()->enqueue(this);
                }

                EnemyAD2->decrementHealth(UAP2);

                getSHOT()->enqueue(EnemyAD2->getID());
                if (!ATTACKERENQ)
                {
                    ATTACKERENQ = true;
                    getgame()->getEarth()->getAttackerList()->enqueue(this);
                }
                
                if (EnemyAD1->getTA() == 0)
                    EnemyAD1->setTa(getgame()->gettime());
                
                if (EnemyAD1->CheckAlive())
                    AttAD.enqueue(EnemyAD1);
                else if (EnemyAD1->getHealth() == 0)
                {
                    EnemyAD1->setTD(getgame()->gettime());
                    getgame()->AddtoKilledList(EnemyAD1);
                }
                
                if (EnemyAD2->getTA() == 0)
                    EnemyAD2->setTa(getgame()->gettime());

                if (EnemyAD2->CheckAlive())
                    AttAD.enqueue(EnemyAD2);
                else if (EnemyAD2->getHealth() == 0)
                {
                    EnemyAD2->setTD(getgame()->gettime());
                    getgame()->AddtoKilledList(EnemyAD2);

                }
                count2--;
                count2--;
                cap--;
            }
        
    }
    /* else if (count1 == 0 && count2) {
         getgame()->getEarth()->removeTank(EnemyET);
         int UAP = ((this->getPower() * (this->getHealth() / 100.00)) / sqrt(EnemyET->getHealth()));

         EnemyET->decrementHealth(UAP);
         if (EnemyET->CheckAlive())
             AttET.enqueue(EnemyET);
         else
             getgame()->AddtoKilledList(EnemyEG);
         count2--;
     }
     else if (count2 == 0 && count1) {
         int pri;
         getgame()->getEarth()->removeGunnery(EnemyEG, pri);
         int UAP = (this->getPower() * (this->getHealth() / 100.0)) / sqrt(EnemyEG->getHealth());

         EnemyEG->decrementHealth(UAP);
         if (EnemyEG->CheckAlive())
             AttEG.enqueue(EnemyEG);
         else
             getgame()->AddtoKilledList(EnemyEG);
         count1--;
     }
 }*/
    int c = 0;
    while (AttAM.remove(c,EnemyAM)) {
        getgame()->getAlien()->addAunit(EnemyAM);
    }

    //FOR LENGTH ARRAY
    AD* EnemyAD1;

    while (AttAD.dequeue(EnemyAD1)) {
        getgame()->getAlien()->addAunit(EnemyAD1);
    }


}

void EG::printdata()
{
	cout << getID() << " " << getType() << endl;
	cout << "H: " << getHealth() << " " << "P: " << getPower() << " " <<"P_H: "<<Power_health<<" "<<"JT: " << getJoinTime() << endl;
}
