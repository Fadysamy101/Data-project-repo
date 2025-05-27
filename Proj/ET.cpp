#include "ET.h"
#include"Game.h"
#include"earthArmy.h"
#include "alienArmy.h"
#include<iostream>
ET::ET(int id, int jt, int h, int p, int ac) :unit(id, "Earth Tank", jt, h, p, ac)
{

}
void ET::attack() {
	ET* EarthTank = this;
	AM* AlienMonster = nullptr;
	AS* AlienSolider = nullptr;
	LinkedQueue<AM*> MonstTempList;
	LinkedQueue<AS*> SoliderTempList;

	bool ATTACKERENQ = false;

	if (getgame()->getEarth()->getES().getCount() < getgame()->getAlien()->getAS().getCount() * 0.3) {
		float attcap = this->getAttCap();
		float MonsterCap = ceil(attcap / 2);
		float SoliderCap = floor(attcap / 2);
		int CountMonst = 0;
		int CountSolider = 0;

		for (int i = 0; i < MonsterCap; i++) {
			int Rand = random(getgame()->getAlien()->getArr().getCount() - 1);
			if (getgame()->getAlien()->removeMonster(AlienMonster, Rand)) {

				int UAP = (this->getPower() * (this->getHealth() / 100.0)) / sqrt(AlienMonster->getHealth());
				if (AlienMonster->getTA() == 0) {
					AlienMonster->setTa(getgame()->gettime());
				}
				AlienMonster->decrementHealth(UAP);

				getSHOT()->enqueue(AlienMonster->getID());
				if (!ATTACKERENQ)
				{
					ATTACKERENQ = true;
					getgame()->getEarth()->getAttackerList()->enqueue(this);
				}

				if (!AlienMonster->CheckAlive()) {
					AlienMonster->setTD(getgame()->gettime());
					getgame()->AddtoKilledList(AlienMonster);
				}
				if (AlienMonster->CheckAlive()) {
					MonstTempList.enqueue(AlienMonster);
				}
				CountMonst++;
			}
		}
		for (int i = 0; i < SoliderCap; i++) {

			if (getgame()->getEarth()->getES().getCount() < getgame()->getAlien()->getAS().getCount() * 0.8) {

				if (getgame()->getAlien()->removeASoldier(AlienSolider)) {

					int UAP = (this->getPower() * (this->getHealth() / 100.0)) / sqrt(AlienSolider->getHealth());
					if (AlienSolider->getTA() == 0) {
						AlienSolider->setTa(getgame()->gettime());
					}
					AlienSolider->decrementHealth(UAP);

					getSHOT()->enqueue(AlienSolider->getID());
					if (!ATTACKERENQ)
					{
						ATTACKERENQ = true;
						getgame()->getEarth()->getAttackerList()->enqueue(this);
					}

					if (!AlienSolider->CheckAlive()) {
						AlienSolider->setTD(getgame()->gettime());
						getgame()->AddtoKilledList(AlienSolider);
					}
					if (AlienSolider->CheckAlive()) {
						SoliderTempList.enqueue(AlienSolider);
					}
					CountSolider++;
				}
			}
		}
		if (SoliderCap - CountSolider != 0 && MonsterCap - CountMonst == 0) {
			for (int i = 0; i < SoliderCap - CountSolider; i++) {
				int Rand = random(getgame()->getAlien()->getArr().getCount() - 1);
				if (getgame()->getAlien()->removeMonster(AlienMonster, Rand)) {
					int UAP = (this->getPower() * (this->getHealth() / 100.0)) / sqrt(AlienMonster->getHealth());
					if (AlienMonster->getTA() == 0) {
						AlienMonster->setTa(getgame()->gettime());
					}
					AlienMonster->decrementHealth(UAP);

					getSHOT()->enqueue(AlienMonster->getID());
					if (!ATTACKERENQ)
					{
						ATTACKERENQ = true;
						getgame()->getEarth()->getAttackerList()->enqueue(this);
					}

					if (!AlienMonster->CheckAlive()) {
						AlienMonster->setTD(getgame()->gettime());
						getgame()->AddtoKilledList(AlienMonster);
					}
					if (AlienMonster->CheckAlive()) {
						MonstTempList.enqueue(AlienMonster);
					}
					CountMonst++;
				}
			}
		}
		if (SoliderCap - CountSolider == 0 && MonsterCap - CountMonst != 0) {
			for (int i = 0; i < MonsterCap - CountMonst; i++) {

				if (getgame()->getEarth()->getES().getCount() < getgame()->getAlien()->getAS().getCount() * 0.8) {

					if (getgame()->getAlien()->removeASoldier(AlienSolider)) {
						int UAP = (this->getPower() * (this->getHealth() / 100.0)) / sqrt(AlienSolider->getHealth());
						if (AlienSolider->getTA() == 0) {
							AlienSolider->setTa(getgame()->gettime());
						}
						AlienSolider->decrementHealth(UAP);

						getSHOT()->enqueue(AlienSolider->getID());
						if (!ATTACKERENQ)
						{
							ATTACKERENQ = true;
							getgame()->getEarth()->getAttackerList()->enqueue(this);
						}

						if (!AlienSolider->CheckAlive()) {
							AlienSolider->setTD(getgame()->gettime());
							getgame()->AddtoKilledList(AlienSolider);
						}
						if (AlienSolider->CheckAlive()) {
							SoliderTempList.enqueue(AlienSolider);
						}
						CountSolider++;

					}
				}
			}
		}
		while (MonstTempList.dequeue(AlienMonster)) {
			getgame()->getAlien()->addAunit(AlienMonster);
		}
		while (SoliderTempList.dequeue(AlienSolider)) {
			getgame()->getAlien()->addAunit(AlienSolider);
		}
	}
	else {

		for (int i = 0; i < EarthTank->getAttCap(); i++) {
			int Rand = random(getgame()->getAlien()->getArr().getCount() - 1);
			if (getgame()->getAlien()->removeMonster(AlienMonster, Rand)) {
				int UAP = (this->getPower() *( this->getHealth() / 100.0)) / sqrt(AlienMonster->getHealth());
				if (AlienMonster->getTA() == 0) {
					AlienMonster->setTa(getgame()->gettime());
				}
				AlienMonster->decrementHealth(UAP);

				getSHOT()->enqueue(AlienMonster->getID());
				if (!ATTACKERENQ)
				{
					ATTACKERENQ = true;
					getgame()->getEarth()->getAttackerList()->enqueue(this);
				}

				if (!AlienMonster->CheckAlive()) {
					AlienMonster->setTD(getgame()->gettime());
					getgame()->AddtoKilledList(AlienMonster);
				}
				if (AlienMonster->CheckAlive()) {
					MonstTempList.enqueue(AlienMonster);
				}
			}
		}
		while (MonstTempList.dequeue(AlienMonster)) {
			getgame()->getAlien()->addAunit(AlienMonster);
		}

	}
}
