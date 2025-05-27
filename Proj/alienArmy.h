#pragma once
#pragma once
#include"AM.h"
#include"AS.h"
#include"AD.h"
#include<iostream>
#include"LinkedQueue.h"
#include"Arr_Bag.h"
#include"DervQueue.h"


class alienArmy
{
private:
	LinkedQueue<AS*> AS_Que;
	Arr_Bag<AM*> AM_Arr;
	DervQueue<AD*> AD_DervQue;

	LinkedQueue<unit*> AttackerList;

public:
	alienArmy() = default;

	void addAunit(unit* u);
	void printArmy();
	Arr_Bag<AM*> getArr(){
		return AM_Arr;
	}
	LinkedQueue<AS*> getAS();
	DervQueue<AD*> getAD();
	bool removeASoldier(AS*& rmvd);
	bool removeMonster(AM*& rmvd,int& i);
	//bool removeDronePair(AD*& rmvd1, AD* rmved2);
	bool remove_Frnt_Drone(AD*& rmvd1);
	bool remove_Bck_Drone(AD*& rmvd2);

	void ALIENS_ATTK();

	LinkedQueue<unit*>* getAttackerList();

	void APrint_ShootingANDShot();
};

