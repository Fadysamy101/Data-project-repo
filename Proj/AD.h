#pragma once
#include "unit.h"
class AD : public unit
{
public:
	AD() = default;
	AD(int id, int jt, int h, int p, int ac);
	void attack();

};

inline std::ostream& operator<<(std::ostream& U, AD* E)
{
	U << E->getID();
	return U;
}
