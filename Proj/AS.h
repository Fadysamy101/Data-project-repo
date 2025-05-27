#pragma once
#include "unit.h"
class AS : public unit
{
public:
	AS() = default;
	AS(int id, int jt, int h, int p, int ac);
	void attack();
};

inline std::ostream& operator<<(std::ostream& U, AS* E)
{
	U << E->getID();
	return U;
}