#pragma once
#include "unit.h"
#include<iostream>


class ES : public unit
{
private:
	int UMLwait;
public:
	ES() = default;
	ES(int id, int jt, int h, int p, int ac);

	void attack();
};

inline std::ostream& operator<<(std::ostream& U, ES* E)
{
	U << E->getID();
	return U;
}