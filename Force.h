#pragma once
#include "Vector3.h"

class Force {
public:
	Force(int name_force, float x, float y);
	~Force();

	static int count;
	int name;
	Vector3 Dir;
	void print();
};
