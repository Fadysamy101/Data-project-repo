#pragma once
#pragma once
#include "priQueue.h"
#include "unit.h"
class UML1 : public priQueue<unit*>
{
public:
	void printUML()
	{
		cout << "============ Unit Maintainace List =============" << endl;
		cout <<"Number of injured units\n"<<getCount() <<endl<<" ";
		printQueue();
		
		cout << endl;
	}
};