#include <iostream> 
#include <fstream>
#include "alienArmy.h"
#include "earthArmy.h"
#include "unitRand.h"
#include "Game.h"
#include "KilledList.h"

using namespace std;


	int main()
    {
        srand(time(0));
        
        Game G;
        G.STARTGAME();

        return 0;
    
	}

