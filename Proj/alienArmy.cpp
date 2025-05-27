#include "alienArmy.h"

void alienArmy::addAunit(unit* u)
{
	if (u != nullptr)
		if (u->getType() == "Alien Soldier")
		{
			AS* e = dynamic_cast<AS*>(u);
			AS_Que.enqueue(e);
		}
		else if (u->getType() == "Alien Monster")
		{
			AM* e = dynamic_cast<AM*>(u);
			AM_Arr.add(e);
		}
		else if(u->getType()=="Alien Drone")
		{
			AD* e = dynamic_cast<AD*>(u);
			AD_DervQue.Total_enqueue(e);
		}
	else return;
}

void alienArmy::printArmy()
{
	cout << "============ Alien Army Alive Units=============" << endl;
		cout << AS_Que.getLength() << " AS "; AS_Que.printQueue(); cout << endl;
		cout << AM_Arr.getLength() << " AM "; AM_Arr.printArray(); cout << endl;
		cout << AD_DervQue.getLength() << " AD "; AD_DervQue.printQueue(); cout << endl;
	
}

LinkedQueue<AS*> alienArmy::getAS()
{
	return AS_Que;
}

DervQueue<AD*> alienArmy::getAD()
{
	return AD_DervQue;
}

bool alienArmy::removeASoldier(AS*& rmvd)
{
	AS* temp = rmvd;
	if (AS_Que.dequeue(rmvd)) {
		
		return true;
	}
	return false;
}

//bool alienArmy::removeDronePair(AD*& rmvd1,AD*rmved2)
//{
//	return (AD_DervQue.dequeue_Pair(rmvd1, rmved2));
//}

bool alienArmy::remove_Bck_Drone(AD*& rmvd2)
{  
	return (AD_DervQue.dequeue_back(rmvd2));
}

void alienArmy::ALIENS_ATTK()
{
	srand(time(0));

	int randomm;

	if (AM_Arr.getCount() != 0)
		randomm = (rand() % AM_Arr.getCount());

	AS* ASF = nullptr;
	AM* AMF = nullptr;
	AD* F_ADF = nullptr;
	AD* B_ADF = nullptr;

	removeASoldier(ASF);
	removeMonster(AMF, randomm);
	remove_Frnt_Drone(F_ADF);
	remove_Bck_Drone(B_ADF);
	if (ASF)
	ASF->attack();
	if (AMF)
		AMF->attack();
	if (F_ADF && B_ADF)
	{
		F_ADF->attack();

		B_ADF->attack();
	}
	addAunit(ASF);
	addAunit(AMF);
	addAunit(F_ADF);
	addAunit(B_ADF);

}

void alienArmy::APrint_ShootingANDShot()
{
	unit* u = nullptr;
	int dmy;

	

	while (!(AttackerList.isEmpty()))
	{
		AttackerList.dequeue(u);
		cout << u->getType() << " " << u->getID() << " shot "; u->getSHOT()->printQueue(); cout << endl;
		while (u->getSHOT()->dequeue(dmy))
		{

		}
	}

}

LinkedQueue<unit*>* alienArmy::getAttackerList()
{
	return &AttackerList;
}

bool alienArmy::remove_Frnt_Drone(AD*& rmvd1)
{
	return (AD_DervQue.dequeue(rmvd1));
}


bool alienArmy::removeMonster(AM*& rmvd,int& i)
{
	if (AM_Arr .getCount() == 0)
		return false;
	if (AM_Arr.remove(i, rmvd)) {
	
		return true;
	}
	return false;
}
