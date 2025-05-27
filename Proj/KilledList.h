#pragma once
#include"LinkedQueue.h"
#include "unit.h"

class KilledList: public LinkedQueue<unit*>
{
public:
	void printKilled();

};

