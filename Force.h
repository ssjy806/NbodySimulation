#pragma once
#include "Vector.h"

class Force {
public:
	Force(int name_force, float x, float y);
	~Force();

	static int count;
	int name;
	Vector Dir;
};
