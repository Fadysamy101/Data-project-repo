#pragma once
#include <iostream>
using namespace std;

class alienArmy
{
private:
	static int AUnitsNO;
	int ID;
	string type;
	int JoinTime;
	int Health;
	int Power;
	int AttackCap;
public:
	alienArmy(int id, string t, int jt, int h, int p, int ac)
	{
		setID(id);
		setAttCap(ac);
		setType(t);
		setHealth(h);
		setJoinTime(jt);
		setPower(p);
		AUnitsNO++;
	}


	void setID(int id)
	{
		ID = id;
	}
	void setType(string s)
	{
		type = s;
	}
	void setJoinTime(int jt)
	{
		JoinTime = jt;
	}
	void setPower(int p)
	{
		Power = p;
	}
	void setHealth(int h)
	{
		if (h <= 100 && h>0)
			Health = h;
	}
	void setAttCap(int ac)
	{
		AttackCap = ac;
	}


	int getID()
	{
		return ID;
	}
	string getType()
	{
		return type;
	}
	int getHealth()
	{
		return Health;
	}
	int getAttCap()
	{
		return AttackCap;
	}
	int getPower()
	{
		return Power;
	}
	int getJoinTime()
	{
		return JoinTime;
	}
};

int alienArmy::AUnitsNO = 0;