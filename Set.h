#pragma once
#include <vector>
#include "Particle.h"
#include "Force.h"

class Set {
public:
	Set(int name_set);
	~Set();
	int name;
	void addParticle(Particle p);
	void delParticle(Particle p);
	void addForce(Force f);
	void delForce(Force f);

	std::vector<int> particlesInSet;
	std::vector<int> forcesInSet;
};