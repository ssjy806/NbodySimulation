#pragma once
#include "Vector3.h"

class Force {
public:
	Force(int name_force, int name_set, double x, double y);
	~Force();

	int name;
	int set;
	Vector3 Dir;
	void print();
};
