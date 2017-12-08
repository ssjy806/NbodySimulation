#pragma once
#include <vector>
#include "Particle.h"
#include "Force.h"

class Set {
public:
	Set(int name_set);
	~Set();
	static int count;
	int name;
	void addParticle(Particle *p);
	void delParticle(Particle *p);
private:
	vector<Particle> particlesInSet;
	vector<Force> forcesInSet;
};