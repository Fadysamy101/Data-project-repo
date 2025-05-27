#include "Game.h"
#include <string>
#include "UML.h"
earthArmy* Game::getEarth() {
    return &Earth;
}
int Game::gettime()const {
    return timeCounter;
}
alienArmy* Game::getAlien() {
    return &Alien;
}

void Game::displayScenarioDescriptions()
{int scenarioNumber = 0;
cout << "Enter the scenario number (1-6): \n";
cout << "Scenarios:" << endl;
cout << "1. Weak Earth - Weak Aliens" << endl;
cout << "2. Weak Earth - Moderate Aliens" << endl;
cout << "3. Weak Earth - Strong Aliens" << endl;
cout << "4. Strong Earth - Weak Aliens" << endl;
cout << "5. Strong Earth - Moderate Aliens" << endl;
cout << "6. Strong Earth - Strong Aliens" << endl;
while (scenarioNumber < 1 || scenarioNumber > 6)
{
  
    cin >> scenarioNumber;
    if (scenarioNumber < 1 || scenarioNumber > 6)
        cout << "Enter scenario agian,please:\n";
}
    read(scenarioNumber);
}

unitRand* Game::getRand() {
    return &Random;
}

    priQueue<unit*>* Game::getUML() {
        return &UML;
    }


KilledList* Game::getKilledList() {
    return &Killed;

}
void Game::checkUML() {
    unit* E;
    int pri;
    int count = UML.getCount();
    while (count) {
        UML.dequeue(E, pri);
        if (E) {
            E->setwait(E->getwait() + 1);
            if (E->getwait() > 10) {
                E->setHealth(0);
                E->setTD(timeCounter);
                Killed.enqueue(E);
            }
            else {
               
                AddtoUML(E, E->getHealth());
            }
        }
        count--;
        }
    }

void Game::AddtoKilledList(unit* u) {
    Killed.enqueue(u);// added add to kill list function 
}

//LinkedQueue<unit*> Game::getTempList()
//{
//    return TempList;
//}

//void Game::printUML()
//{
//        cout << "============ Unit Maintainace List =============" << endl;
//        cout << UML.getCount() << " "; UML.printQueue();
//           cout<< endl;   
//}

void Game::printGame()
{
    cout << "Current Timestep " << timeCounter << endl;
    Earth.printArmy();
    Alien.printArmy();
    printUML();
    Earth.EPrint_ShootingANDShot();
    Alien.APrint_ShootingANDShot();
    cout << endl;
    Killed.printKilled();
    cout << endl;


}

void Game::produceOutputF()
{
    int SCS_HEAL = Earth.getHlist()->gethealed();

    int D_ES = 0;
    int D_ET = 0;
    int D_EG = 0;
    int D_AS = 0;
    int D_AM = 0;
    int D_AD = 0;

    int D_EARTOTAL=0;
    int D_ALIETOTAL=0;

    int UML_ES = 0;
    int UML_ET = 0;

    int TOT_DB_EARTH = 0;
    int TOT_DF_EARTH = 0;
    int TOT_DD_EARTH = 0;

    int TOT_DB_ALIEN = 0;
    int TOT_DF_ALIEN = 0;
    int TOT_DD_ALIEN = 0;

    ofstream myFile("Output.txt");

    myFile << "TD    ID    TJ    DF    DD    DB" << endl;
    unit* u;
    for (int i = 0; i < Killed.getCount(); i++) {
        Killed.dequeue(u);
        myFile << u->getTD() << "    " << u->getID() << "    " << u->getJoinTime() << "     " << u->getDF() << "     " << u->getDD() << "    " << u->getDB() << endl;
        myFile << "==========================================================================" << endl;
        Killed.enqueue(u);
        if (u) {
            string t = u->getType();

            if (t == "Earth Soldier") {
                D_ES++;
                TOT_DB_EARTH += u->getDB();
                TOT_DF_EARTH += u->getDF();
                TOT_DD_EARTH += u->getDD();
            }
            if (t == "Earth Tank") {
                D_ET++;
                TOT_DB_EARTH += u->getDB();
                TOT_DF_EARTH += u->getDF();
                TOT_DD_EARTH += u->getDD();
            }
            if (t == "Earth Gunner") {
                D_EG++;
                TOT_DB_EARTH += u->getDB();
                TOT_DF_EARTH += u->getDF();
                TOT_DD_EARTH += u->getDD();
            }
            if (t == "Alien Soldier") {
                D_AS++;
                TOT_DB_ALIEN += u->getDB();
                TOT_DF_ALIEN += u->getDF();
                TOT_DD_ALIEN += u->getDD();
            }
            if (t == "Alien Monster") {
                D_AM++;
                TOT_DB_ALIEN += u->getDB();
                TOT_DF_ALIEN += u->getDF();
                TOT_DD_ALIEN += u->getDD();
            }
            if (t == "Alien Drone") {
                D_AD++;
                TOT_DB_ALIEN += u->getDB();
                TOT_DF_ALIEN += u->getDF();
                TOT_DD_ALIEN += u->getDD();
            }
        }
    }

    unit* z;
    int pri=0;

    for (int i = 0; i < UML.getCount(); i++) {
        UML.dequeue(z, pri);
        UML.enqueue(z, pri);
        if (z) {
            if (z->getType() == "Earth Soldier")
                UML_ES++;
            if (z->getType() == "Earth Tank")
                UML_ET++;
        }
    }
    int T_DESTRUCTED_EARTH = D_ES + D_ET + D_EG;
    int T_DESTRUCTED_ALIEN = D_AS + D_AM + D_AD;

    int T_ES = UML_ES + Earth.getES().getCount() + D_ES;
    int T_ET = UML_ET + Earth.getET().getCount() + D_ET;
    int T_EG = Earth.getEG()->getCount() + D_EG;

    int T_AS = Alien.getAS().getCount() + D_AS;
    int T_AM = Alien.getArr().getCount() + D_AM;
    int T_AD = Alien.getAD().getCount() + D_AD;

    int T_E = T_ES + T_ET + T_EG;
    int T_A = T_AS + T_AM + T_AD;

    int TOTAL = T_E + T_A;

    myFile << "==========================================================================" << endl;

    myFile << "BATTLE RESULT: ";

    if (Earth.getES().getCount() + Earth.getET().getCount() + Earth.getEG()->getCount() == 0)
        myFile << "Aliens WON!" << endl;
    else if (Alien.getAS().getCount() + Alien.getArr().getCount() + Alien.getAD().getCount() == 0)
        myFile << "Earth WON!" << endl;
    else myFile << " DRAW!" << endl;

    myFile << "==========================================================================" << endl;

    myFile << "Total Earth Army Units (Destructed & Alive)" << endl
        << "ES ET EG" << endl << T_ES << " " << T_ET << " " << T_EG << endl;

    myFile << "% Healed to Total Earth Units:" << " " << (1.00*(SCS_HEAL)) / (T_E)<<endl;

    myFile << "Percentage Of Destructed Earth Units Relative To Their Total Specific Unit: " << "ES ET EG" << endl
        << ((D_ES * 1.0) / T_ES) * 100.0 << " " << ((D_ET * 1.0) / T_ET) * 100.0 << " " << ((D_EG * 1.0) / T_EG) * 100.0 << " " << endl;

    myFile << "% Of TOTAL Destructed Earth Units relative to their TOTAL: "
        << ((T_DESTRUCTED_EARTH * 100.0) / T_E) << endl;

    myFile << "Earth Average for DF, DB, DD (respectively): " << (TOT_DF_EARTH * 1.0) / T_DESTRUCTED_EARTH << " " << (TOT_DB_EARTH * 1.0) / T_DESTRUCTED_EARTH
        << " " << (TOT_DD_EARTH * 1.0) / T_DESTRUCTED_EARTH << endl;

    myFile << "Earth DF/DB % " << ((TOT_DF_EARTH * 1.0) / TOT_DB_EARTH) * 100 << endl;

    myFile << "Earth DD/DB % " << ((TOT_DD_EARTH * 1.0) / TOT_DB_EARTH) * 100 << endl;

    myFile << "==========================================================================" << endl;
    myFile << "==========================================================================" << endl;

    myFile << "Total Alien Army Units (Destructed & Alive)" << endl
        << "AS AM AD" << endl << T_AS << " " << T_AM << " " << T_AD << endl;

    myFile << "Percentage Of Destructed Alien Units Relative To Their Total Specific Unit: " << "AS AM AD" << endl
        << ((D_AS * 1.0) / T_AS) * 100.0 << " " << ((D_AM * 1.0) / T_AM) * 100.0 << " " << ((D_AD * 1.0) / T_AD) * 100.0 << " " << endl;

    myFile << "% Of TOTAL Destructed Alien Units relative to their TOTAL: "
        << (T_DESTRUCTED_ALIEN * 100.0 / T_E) << endl;

    myFile << "Alien Average for DF, DB, DD (respectively): " << (TOT_DF_ALIEN * 1.0) / T_DESTRUCTED_ALIEN << " " << (TOT_DB_ALIEN * 1.0) / T_DESTRUCTED_ALIEN
        << " " << (TOT_DD_ALIEN * 1.0) / T_DESTRUCTED_ALIEN << endl;

    myFile << "Alien DF/DB % " << ((TOT_DF_ALIEN * 1.0) / TOT_DB_ALIEN) * 100 << endl;

    myFile << "Alien DD/DB % " << ((TOT_DD_ALIEN * 1.0) / TOT_DB_ALIEN) * 100 << endl;

    myFile.close();

}

void Game::STARTGAME()
{
    srand(time(0));

    cout << "WELCOME TO EARTH VS ALIENS " << endl << "==========================================================================" << endl;
    int s;
    cout << "Choose the simulation mode: 1 for interactive, 2 for silent" << endl;
    cin >> s;
    
    while (s!=1 && s!=2)
    {
        cout << "Please choose a valid number: "<<endl;
            cin >> s;
    }

    bool EEMPTY = false;
    bool AEMPTY = false;

    displayScenarioDescriptions();

    if (s == 2)
    {
        cout << "Silent Mode" << endl;
        cout << "Simulation Starts..." << endl;
      

        while (!AEMPTY && !EEMPTY)
        {
            //timeCounter++;


            Random.MULTIPLE_generate_N_assign_Unit(timeCounter);
            
            Earth.EARTH_ATTK();
            Alien.ALIENS_ATTK();
 /*           printGame();*/


            if (timeCounter>=400)
                break;

            timeStep();


            //if (timeCounter == 200)
            //    system("pause");

            if (gettime() >= 40)
            {
                AEMPTY = ((Alien.getAD().getCount() + Alien.getArr().getCount() + Alien.getAS().getCount()) == 0);
                EEMPTY = ((Earth.getES().getCount() + Earth.getEG()->getCount() + Earth.getET().getCount()) == 0);
            }
        }
        produceOutputF();
    }
    else {
        while (!AEMPTY && !EEMPTY)
        {
            Random.MULTIPLE_generate_N_assign_Unit(timeCounter);
            Earth.EARTH_ATTK();
            Alien.ALIENS_ATTK();
            
            printGame();
           

            if (timeCounter == 1)
                system("Pause");
           
            
            if (timeCounter >= 400)
                break;

            timeStep();

            if (gettime() > 40)
            {
                AEMPTY = ((Alien.getAD().getCount() + Alien.getArr().getCount() + Alien.getAS().getCount()) == 0);
                EEMPTY = ((Earth.getES().getCount() + Earth.getEG()->getCount() + Earth.getET().getCount()) == 0);
            }
            cin.get();
        }
        produceOutputF();
    }
    cout << "Simulation ends, Output created." << endl;

    int c;
    cin >> c;

}

bool Game::read(int scenarioNumber) {
  
    string filename = "scenario_" + to_string(scenarioNumber) + ".txt";
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return false;
    }

    
    int N, ESPercent, HUPercent, ETPercent, EGPercent, ASPercent, AMPercent, ADPercent, prob;
    int MinattackE, MaxattackE, health1E, health2E, ac1E, ac2E;
    int MinattackA, MaxattackA, health1A, health2A, ac1A, ac2A;

    inputFile >> N >> ESPercent >> HUPercent >> ETPercent >> EGPercent >> ASPercent >> AMPercent >> ADPercent >> prob
        >> MinattackE >> MaxattackE >> health1E >> health2E >> ac1E >> ac2E
        >> MinattackA >> MaxattackA >> health1A >> health2A >> ac1A >> ac2A;
    
    
    Random.setN(N);
    Random.setAttack(MinattackE, MaxattackE, MinattackA, MaxattackA);
    Random.setHealth(health1E, health2E, health1A, health2A);
    Random.setac(ac1E, ac2E, ac1A, ac2A);
    Random.setpercentage(ESPercent, ETPercent,HUPercent, EGPercent, ASPercent, AMPercent, ADPercent, prob);
    Random.setGame(this);
    
    return true;
}