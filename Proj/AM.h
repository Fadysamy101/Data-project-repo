#pragma once
#include "unit.h"
class AM : public unit
{
public:
	AM() = default;
	AM(int id, int jt, int h, int p, int ac);
	void attack();
};

inline std::ostream& operator<<(std::ostream& U, AM* E)
{
	U << E->getID();
	return U;
}
