#pragma once
#include"unit.h"
#include "EG.h"
#include "ES.h"
#include "ET.h"
#include "AM.h"
#include "AS.h"
#include "alienArmy.h"
#include "earthArmy.h"

using namespace std;

class Game;
class unitRand {
private:
    static int earth_id_counter;
    static int alien_id_counter;
    int N;   
    int ESPercent;  
    int ETPercent;  
    int EGPercent;
    int ASPercent;  
    int AMPercent;  
    int ADPercent;
    int HUPercent;
    int prob;
    int MaxattackE;
    int MinattackE;
    int health1E;
    int health2E;
    int ac1E;
    int ac2E;
    int MaxattackA;
    int MinattackA;
    int health1A;
    int health2A;
    int ac1A;
    int ac2A;
    Game* G;

    void getstatsearth(int& h, int& p, int& c);
    void getstatsalien(int& h, int& p, int& c);



public:
    unitRand() {};
    void setGame(Game* G);
    void generate_N_assign_Unit(int t);
    void setN(int n);
    void setHealth(int E1, int E2, int A1, int A2);
    void setac(int E1, int E2, int A1, int A2);
    void setAttack(int E1, int E2, int A1, int A2);
    void setpercentage(int E1, int E2,int Heal, int E3, int A1, int A2, int A3, int p);
    int random(int n); /*return from 1-n*/
    void MULTIPLE_generate_N_assign_Unit(int t);

    unit* generate_Aunit(int& t);
    unit* generate_Eunit(int& t);
};