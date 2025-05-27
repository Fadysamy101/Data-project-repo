#include "unit.h"
#include"Game.h"

unit::unit(int id, string t, int jt, int h, int p, int ac)
{
	setMaxHealth(h);
	setID(id);
	setAttCap(ac);
	setType(t);
	setHealth(h);
	setJoinTime(jt);
	setPower(p);
}

unit::unit()
{
}

Game* unit::getgame()const{
	return gmeptr;

}
int unit::getMaxHealth()const {
	return MaxHealth;

}
void unit::setMaxHealth(int mh) {
	MaxHealth = mh;

}
void unit::setgame(Game* G) {
	gmeptr = G;
}
bool unit::CheckAlive() {
	
	if (Health == 0)
	{
		return false;
	}
	return true;
}

bool unit::CheckInjured() {
	 
		if (Health <= 0.2 * MaxHealth && Health>0) 
				return true;
		return false;

}
void unit::setID(int id)
{
	ID = id;
}

void unit::setType(string s)
{
	type = s;
}

void unit::setJoinTime(int jt)
{
	JoinTime = jt;
}

void unit::setPower(int p)
{
	Power = p;
}

void unit::setHealth(int h)
{
	if (h > 100)
		Health = 100;
	else if (h <= 100 && h >=0)
		Health = h;
	else if (h < 0)
		Health = 0;
	else cout << "Invalid health";
}

void unit::setAttCap(int ac)
{
	AttackCap = ac;
}

void unit::decrementHealth(int amount)
{
		Health = Health - amount;
		if (Health < 0)
			Health = 0;
	
}

int unit::getID() const
{
	return ID;
}

int unit::getDD() const
{
	return Dd;
}

int unit::getwait() const
{
	return waittime;
}
void  unit::setwait(int A)
{  
	waittime = A;
	
}

string unit::getType()
{
	return type;
}

int unit::getHealth()
{
	return Health;
}

int unit::getAttCap()
{
	return AttackCap;
}

int unit::getPower()
{
	return Power;
}

int unit::getJoinTime()
{
	return JoinTime;
}
int unit::getTA() const {
	return Ta;
}

int unit::getTD() const
{
	return Td;
}

int unit::getDF() const
{
	return Df;
}

int unit::getDB() const
{
	return Db;
}

void unit::printdata()
{
	cout << ID << " " << type << endl;
	cout << "H: " << Health << " " << "P: " << Power << " " << "JT: " << JoinTime << endl;
}

void unit::setTa(int s)
{
	Ta = s;
	setDf();
}

void unit::setTD(int s)
{
	Td = s;
	setDb();
	setDd();
}
LinkedQueue<int>* unit::getSHOT()
{
	return &shot;
}
void unit::setDd(){
	Dd = Td - Ta;
}
void unit::setDf()
{
	Df = Ta - JoinTime;
}

void unit::setDb()
{
	Db = Td - JoinTime;
}
