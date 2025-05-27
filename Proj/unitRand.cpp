#include"unit.h"
#include"unitRand.h"
#include <iostream>
#include <fstream>
#include <cstdlib> 
#include "earthArmy.h"
#include <ctime>
#include "Game.h"
int unitRand::earth_id_counter = 1;
int unitRand::alien_id_counter = 2000;
void unitRand::setGame(Game* G) { this->G = G; }
void unitRand::setN(int n) {
    N = n;
}
void unitRand::setpercentage(int E1,int E2,int Heal,int E3,int A1,int A2,int A3,int p){
    ESPercent = E1;
    HUPercent=Heal;
    ETPercent = E2;
    EGPercent = E3;
    ASPercent = A1;
    AMPercent = A2;
    ADPercent = A3;
    prob = p;
}
void unitRand::setHealth(int E1, int E2, int A1, int A2) {
    health1E = E1;
        health2E = E2;
        health1A = A1;
    health2A = A2;

}
void unitRand::setAttack(int E1, int E2, int A1, int A2) {
    MinattackE = E1;
    MaxattackE = E2;
    MinattackA = A1;
    MaxattackA = A2;
}
void unitRand::setac(int E1, int E2, int A1, int A2) {
    ac1E=E1;
        ac2E=E2;
       ac1A=A1;
       ac2A=A2;
}
int unitRand::random (int n) {
 
    return (1 + (rand() % n));

}
void unitRand::getstatsearth(int& h, int& p, int& c){

    h = (health1E - 1) + random(health2E-health1E+1);
    c = (ac1E - 1) + random(ac2E-ac1E+1);
    p = (MinattackE - 1) + random(MaxattackE - MinattackE + 1);


}
void unitRand::getstatsalien(int& h, int& p, int& c) {
    h = (health1A - 1) + random(health2A - health1A + 1);
    c = (ac1A - 1) + random(ac2A - ac1A + 1);
    p = (MinattackA - 1) + random(MaxattackA - MinattackA + 1);

}
void unitRand::MULTIPLE_generate_N_assign_Unit(int t)
{
    int A = random(100);
    if (A <= prob)
    {
        for (int i = 0; i < N; i++)
        {
            generate_N_assign_Unit(t);
        }
    }
}
unit* unitRand::generate_Aunit(int& t) {
    if (alien_id_counter > 2999)
    {
        //cout << "All alien unit slots are occupied";
        return nullptr;
        
    }
    int h, p, c;
    getstatsalien(h, p, c);
     
        int B = random(100);
        {
            if (B <= ASPercent) {
                AS* temp = new AS(alien_id_counter++, t, h, p, c);
                temp->setgame(G);
                return temp;

            }
            else if (B <= AMPercent + ASPercent) {

                AM* temp = new AM(alien_id_counter++, t, h, p, c);
                temp->setgame(G);
                return temp;
            }
            else  {
                AD* temp = new AD(alien_id_counter++, t, h, p, c);
                temp->setgame(G);
                return temp;

            }
    

   

        }
    
     return nullptr;
}
unit* unitRand::generate_Eunit(int& t) 
{
    if (earth_id_counter > 999)
    {
        //cout << "All earth unit slots are occupied";
        return nullptr;

    }
 
    
    int h, p, c;
    getstatsearth(h, p, c);
    {
        int B = random(100);
        {
            if (B <= ESPercent) {
           
                ES* temp = new ES(earth_id_counter++, t, h, p, c);
                temp->setgame(G);
                return temp;

            }
            else if (B <= ETPercent + ESPercent) {
              
                ET* temp = new ET(earth_id_counter++, t, h, p, c);
                temp->setgame(G);
                return temp;
            }
            else if(B<= ETPercent + ESPercent+ EGPercent)
            {
                EG* temp = new EG(earth_id_counter++, t, h, p, c);
                temp->setP_H();
                temp->setgame(G);
                return temp;
            }
            else {
                HU* temp = new HU(earth_id_counter++, t, h, p, c);
                temp->setgame(G);
                return temp;

            }

        }
    }
     return nullptr;
}
void unitRand::generate_N_assign_Unit(int t){
   unit* E= generate_Eunit(t);
    unit*A=generate_Aunit(t);
    alienArmy* Aforce = G->getAlien();
    earthArmy* Eforce = G->getEarth();

    if (A != nullptr) {

        Aforce->addAunit(A);
    }

    if(E != nullptr)
        Eforce->addEunit(E);
}
