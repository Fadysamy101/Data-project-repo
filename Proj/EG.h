#pragma once
#include "unit.h"
#include<iostream>

class EG : public unit
{
private:
	int Power_health;
public:
	EG(int id, int jt, int h, int p, int ac);
	EG() = default;

	int getP_H();
	void setP_H();
	void attack();
	void printdata();
	int rndm(int i);
};

inline std::ostream& operator<<(std::ostream& U, EG* E)
{
	U << E->getID();
	return U;
}
