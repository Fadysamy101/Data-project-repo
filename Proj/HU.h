#pragma once
#include "unit.h"
class HU :
public unit {
public:
	HU() = default;
	HU(int id, int jt, int h, int p, int ac);

	void attack();

};