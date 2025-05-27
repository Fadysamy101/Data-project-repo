#pragma once

#include"EG.h"
#include"ET.h"
#include"ES.h"
#include "HU.h"
#include"ArrayStack.h"
#include"priQueue.h"
#include"LinkedQueue.h"
#include"HealList.h"

class earthArmy
{
private:
	LinkedQueue<ES*> ES_Que;
	ArrayStack<ET*> ET_Stack;
	priQueue<EG*> EG_PriQue;
	HealList Heal_List;

	LinkedQueue<unit*> AttackerList;
	
public:
	earthArmy() = default;
	HealList* getHlist();
	
	void printArmy();
	
	void addEunit(unit* u);
	priQueue<EG*> *getEG();
	ArrayStack<ET*> getET();
	LinkedQueue<ES*> getES();
	bool removeESoldier(ES*& pe);
	bool removeTank(ET*& pt);
	bool removeGunnery(EG*& pg, int &pri);
	bool removeHealer(HU*& pt);

	void EARTH_ATTK();

	LinkedQueue<unit*>* getAttackerList();

	void EPrint_ShootingANDShot();
};

