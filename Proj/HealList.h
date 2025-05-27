#pragma once
#include "ArrayStack.h"

#include "unit.h"
#include "HU.h"
class HealList :public ArrayStack<HU*>{
private:
	int healedcount;
public:
	int gethealed()const {
		return healedcount;
	}
	void inc_healed() {
		healedcount++;
	}

};