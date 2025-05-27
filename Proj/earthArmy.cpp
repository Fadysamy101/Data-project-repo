#include "earthArmy.h"
#include <iostream>


HealList* earthArmy::getHlist()
{
	return &Heal_List;
}

void earthArmy::printArmy()
{
	cout << "============ Earth Army Alive Units=============" << endl;
	cout << ES_Que.getLength() << " ES "; ES_Que.printQueue(); cout << endl;
	cout << ET_Stack.getLength() << " ET "; ET_Stack.printStack(); cout << endl;
	cout << EG_PriQue.getLength() << " EG "; EG_PriQue.printQueue(); cout << endl;
	cout << Heal_List.getCount() << " HU"; Heal_List.printStack(); cout << endl;
}
priQueue<EG*>* earthArmy::getEG() {
	
	priQueue<EG*>* X = &EG_PriQue;
	return X;

}
ArrayStack<ET*> earthArmy:: getET() {
	return ET_Stack;
}
LinkedQueue<ES*> earthArmy::getES()
{
	return ES_Que;
}
void earthArmy::addEunit(unit* u)
{
	
	if (u != nullptr) {
		
		if (u->getType() == "Earth Soldier")
		{
		
			ES* e = dynamic_cast<ES*>(u);
			ES_Que.enqueue(e);
		}
		else if (u->getType() == "Earth Tank")
		{
			ET* e = dynamic_cast<ET*>(u);
			ET_Stack.push(e);
		}
		else if(u->getType()== "Earth Gunner")
		{
			EG* e = dynamic_cast<EG*>(u);
			EG_PriQue.enqueue(e, e->getP_H());
		}
		else if (u->getType() == "Heal Unit") {
			HU* e = dynamic_cast<HU*>(u);
			Heal_List.push(e);

		}
	}
	else return;
}

bool earthArmy::removeESoldier(ES*& removed)
{
	if (ES_Que.dequeue(removed))
	{
			return true;
	}
	return false;
}

bool earthArmy::removeTank(ET*&pt)
{ 
	if (ET_Stack.pop(pt))
	{
		
	
		return true;
	}
	return false;
}
bool earthArmy::removeHealer(HU*& pt) {

	if (Heal_List.pop(pt))
	{
		

		return true;
	}
	return false;

}

bool earthArmy::removeGunnery(EG*& pg,int& pri)
{
	
	if (EG_PriQue.dequeue(pg, pri))
	{
	
		return true;
	}
	return false;
}

void earthArmy::EARTH_ATTK()
{
	srand(time(0));
	
	int randomm;
	int pri;


	ES* ESF = nullptr;
	ET* ETF = nullptr;
	EG* EGF = nullptr;
	HU* HUF = nullptr;

	removeESoldier(ESF);
	removeTank(ETF);
	removeGunnery(EGF,pri);
	

	
	if (ESF)
		ESF->attack();
	if (ETF)
		ETF->attack();
	if (EGF)
		EGF->attack();
	if (Heal_List.pop(HUF))
		HUF->attack();
		

	addEunit(ESF);
	addEunit(ETF);
	addEunit(EGF);

}

LinkedQueue<unit*>* earthArmy::getAttackerList()
{
	return &AttackerList;
}

void earthArmy::EPrint_ShootingANDShot()
{
	unit* u = nullptr;
	int dmy;
	
	cout << "============ Units fighting at Curent step =============" << endl;

	while (!(AttackerList.isEmpty()))
	{
		AttackerList.dequeue(u);
		cout << u->getType() << " " << u->getID() << " shot "; u->getSHOT()->printQueue(); cout << endl;
		while (u->getSHOT()->dequeue(dmy))
		{

		}
	}

}
