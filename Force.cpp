#include <iostream>
#include "Force.h"

Force::Force(int name_force, float x, float y) {
	int name = name_force;
	Vector3 Dir = { x, y };
}

Force::~Force() {
}

void Force::print() {
	std::cout << "Force: " << name << std::endl;
	std::cout << "  (" << Dir.x << "," << Dir.y << ")" << std::endl;
}
