
#pragma once
#include "alienArmy.h"
#include "earthArmy.h"
#include "unitRand.h"
#include <fstream>
#include <iostream>
#include "UML.h"
#include "KilledList.h"

class unit;
class Game
{
private:
    int timeCounter = 1;
    earthArmy Earth;
    alienArmy Alien;
    unitRand Random;
    KilledList Killed;
    //LinkedQueue<unit*> TempList;
    priQueue<unit*> UML;
public:
    int gettime()const;
    Game()=default;
    
    Game(earthArmy& E, alienArmy& A, unitRand& R):Earth(E),Alien(A),Random(R) {
    }
    priQueue<unit*>* getUML();
    void removeUML(unit*& u,int& pri) {
        UML.dequeue(u,pri);
        
    }
    earthArmy* getEarth();
    alienArmy* getAlien(); 
    void displayScenarioDescriptions();
    bool read(int scenarioNumber);
    unitRand* getRand(); 
    KilledList* getKilledList();
    void timeStep()
    {//Increase waittime for UMLunits and kill if more than 10
       checkUML();
        timeCounter++;
    }
    void checkUML();
    void AddtoKilledList(unit* u);

    //LinkedQueue<unit*> getTempList();
   
    
    void AddtoUML(unit* u, int h) {
        int pri;
        if (u->getType() == "Earth Tank")
            pri = 0;
        else{ pri = (1.00 / h) * 1000; }
       
        UML.enqueue(u, pri);
    }
    
    void printUML(){ 
        cout << "===========Injured and Healed units=================\n";
        cout << "Number of injured units:\n" << UML.getCount() << endl;
        UML.printQueue();
        cout << endl;
        cout << "Number of Healed units:\n" << Earth.getHlist()->gethealed()<<endl;
    }
    
    void printGame();

    void produceOutputF();

    void STARTGAME();
};

