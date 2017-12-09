#pragma once
#include "Vector3.h"

class Force {
public:
	Force(int name_force, int name_set, float x, float y);
	~Force();

	static int count;
	int name;
	int set;
	Vector3 Dir;
	void print();
};
