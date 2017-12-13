#include <iostream>
#include <algorithm>
#include "Set.h"

Set::Set(int name_set) {
	name = name_set;
}

Set::~Set() {
}

void Set::addParticle(Particle p) {
	p.addIncludedSets(name);
	particlesInSet.push_back(p.name);
}

void Set::delParticle(Particle p) {
	p.delIncludedSets(name);
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

void Set::delForce(Force f) {
	auto it = std::find(forcesInSet.begin(), forcesInSet.end(), f.name);
	if (it != forcesInSet.end()) {
		using std::swap;
		swap(*it, forcesInSet.back());
		forcesInSet.pop_back();
	}
}
