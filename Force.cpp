#include <iostream>
#include "Force.h"

Force::Force(int name_force, int name_set, float x, float y) {
	name = name_force;
	Dir = { x, y };
	set = name_set;
}

Force::~Force() {
}

void Force::print() {
	std::cout << "Force " << name << " added to set " << set
		<< ": (" << Dir.x << "," << Dir.y << ")" << std::endl;
}
