#include "HU.h"
#include "priQueue.h"
#include "Game.h"
#include <cmath>
#include "UML.h"
HU::HU(int id, int jt, int h, int p, int ac) :unit(id, "Heal Unit", jt, h, p, ac)
{
}



void HU::attack() {

	LinkedQueue<unit*> EStemp;
	LinkedQueue<unit*> ETtemp;

	unit* U1 = nullptr;
	unit* U2 = nullptr;
	HU* H1 = this;
	Game* G = getgame();
	priQueue<unit*>* E = G->getUML();
	int ac = getAttCap();

	if (G->getUML()->getCount() != 0)
	{
		for (int i = 0; i < ac; i++) {
			unit* U = nullptr;
			int pri;
			E->dequeue(U, pri);
			if (!U) {
				return;
			}
			U->setHealth(U->getHealth() + ((getHealth() / 100.0) * getPower()) / sqrt(U->getHealth()));
			G->getEarth()->getHlist()->inc_healed();
			if (U->getHealth() > U->getMaxHealth() * 0.2)
			{
				getgame()->getEarth()->addEunit(U);

			}
			else {
				if (pri == 0)
					ETtemp.enqueue(U);
				else
					EStemp.enqueue(U);

			}


		}
		while (ETtemp.dequeue(U1) || EStemp.dequeue(U2))
		{
			getgame()->AddtoUML(U1, U1->getHealth());
			getgame()->AddtoUML(U2, U2->getHealth());
		}

		/////Kill the Healing unit
		this->setHealth(0);
		this->setTD(getgame()->gettime());
		this->setTa(getgame()->gettime());

		getgame()->getKilledList()->enqueue(this);
	}
	else
	{
		getgame()->getEarth()->getHlist()->push(this);
	}
}