#include <iostream>
#include "Set.h"

Set::Set(int name_set) {
	name = name_set;
}

Set::~Set() {
}

void Set::addParticle(Particle p) {
	particlesInSet.push_back(p.name);
}

void Set::delParticle(Particle p) {
	std::vector<int>::iterator it;
	auto it = std::find(particlesInSet.begin(), particlesInSet.end(), p.name);
	if (it != particlesInSet.end()) {
		using std::swap;

		swap(*it, particlesInSet.back());
		particlesInSet.pop_back();
	}
}

void Set::addForce(Force f) {
	forcesInSet.push_back(f.name);
}

void Set::delForce(Force f)
{
}
