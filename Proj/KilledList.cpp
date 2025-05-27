#include "KilledList.h"

void KilledList::printKilled()
{
	cout << "============ Killed Units=============" << endl;
	cout << getLength() << " Killed units "; printQueue();
	cout << endl;
}
