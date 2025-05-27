#include "AS.h"
#include"Game.h"
#include"alienArmy.h"
#include<iostream>
AS::AS(int id, int jt, int h, int p, int ac) :unit(id, "Alien Soldier", jt, h, p, ac)
{
}
void AS::attack() {
	
	LinkedQueue<ES*> AttES;
	AS* asptr = this;
	ES* esptr = nullptr;
	
	bool ATTACKERENQ = false;

	for (int i = 0; i < asptr->getAttCap(); i++) {

		if (getgame()->getEarth()->removeESoldier(esptr)) {
			int UAP = (this->getPower() * (this->getHealth() / 100.0)) / sqrt(esptr->getHealth());
			esptr->decrementHealth(UAP);

			getSHOT()->enqueue(esptr->getID());
			if (!ATTACKERENQ)
			{
				ATTACKERENQ = true;
				getgame()->getAlien()->getAttackerList()->enqueue(this);
			}
			
			if (esptr->getTA() == 0) {
				esptr->setTa(getgame()->gettime());
			}

			if (!esptr->CheckAlive()) {
				esptr->setTD(getgame()->gettime());
				getgame()->AddtoKilledList(esptr);
				
			}
			else {
				if (esptr->CheckInjured()) {
					esptr->getgame()->AddtoUML(esptr, esptr->getHealth());
				}
				else
				{
					AttES.enqueue(esptr);
				}
			}

		}
	}

	while (AttES.dequeue(esptr)) {
		getgame()->getEarth()->addEunit(esptr);
	}

}