#pragma once
#include <iostream>
#include"LinkedQueue.h"
using namespace std;
class Game;
class unit
{
private:
	int ID;
	string type;
	int JoinTime;
	int Health;
	int Power;
	int AttackCap;
	int MaxHealth;
	int waittime=0;
	Game* gmeptr;

	LinkedQueue<int> shot;


	int Ta=0;
	int Td=0;
	int Df=0;
	int Dd=0;
	int Db=0;
	
	void setDf();
	void setDb();
	void setDd();
public:
	unit(int id, string t, int jt, int h, int p, int ac);
	unit();
	Game* getgame()const;
	int getMaxHealth()const;
	void setgame(Game* G);
	void setMaxHealth(int mh);
	void setID(int id);
	void setType(string s);
	void setJoinTime(int jt);
	void setPower(int p);
	void setHealth(int h);
	void setAttCap(int ac);
	void decrementHealth(int amount);
	int getID() const;
	int getTA() const;
	int getTD() const;
	int getDF() const;
	int getDB() const;
	int getDD()	const;
	int getwait()const;
	void setwait(int A);
	string getType();
	int getHealth();
	int getAttCap();
	int getPower();
	int getJoinTime();
	bool CheckAlive();
	bool CheckInjured();
	virtual void printdata();
	
	void setTa(int s);
	void setTD(int s);

	LinkedQueue<int>* getSHOT();

};
inline std::ostream& operator<<(std::ostream& U, unit* E)
{
	U << E->getID();
	return U;
}