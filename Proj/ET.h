#pragma once
#include "unit.h"


class ET : public unit
{
private:
	int UMLwait;
public:
	ET() = default;
	ET(int id, int jt, int h, int p, int ac);
	void attack();
	int random(int n) {
		if (n == 0)
			return 0;
		return ((rand() % n));

	}
};

inline std::ostream& operator<<(std::ostream& U, ET* E)
{
	U << E->getID();
	return U;
}