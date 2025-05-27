#include "ES.h"
#include"Game.h"
#include"earthArmy.h"
#include<iostream>
ES::ES(int id, int jt, int h, int p, int ac):unit(id,"Earth Soldier", jt, h, p, ac)
{
}

void ES::attack() {

	LinkedQueue<AS*> AttAS;
	ES* esptr = this;
	AS* asptr = nullptr;

	bool ATTACKERENQ = false;

	for (int i = 0; i < esptr->getAttCap(); i++) {

		if (getgame()->getAlien()->removeASoldier(asptr)) {
			int UAP = (this->getPower() * (this->getHealth() / 100.0)) / sqrt(asptr->getHealth());
			asptr->decrementHealth(UAP);

			getSHOT()->enqueue(asptr->getID());
			if (!ATTACKERENQ)
			{
				ATTACKERENQ = true;
				getgame()->getEarth()->getAttackerList()->enqueue(this);
			}


			if (asptr->getTA() == 0) {
				asptr->setTa(getgame()->gettime());
			}

			if (!asptr->CheckAlive()) {
				asptr->setTD(getgame()->gettime());
				getgame()->AddtoKilledList(asptr);
			}
			if (asptr->CheckAlive())
			{
				AttAS.enqueue(asptr);

			}

		}

	}
		while (AttAS.dequeue(asptr)) {
			getgame()->getAlien()->addAunit(asptr);
		}
	

}
