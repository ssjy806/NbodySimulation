#include <iostream>
#include <algorithm>
#include "Set.h"

Set::Set(int name_set) {
	// set imformation
	name = name_set;
}

Set::~Set() {
}

void Set::addParticle(Particle p) {
	// add a particle in a set
	p.addIncludedSets(name);
	particlesInSet.push_back(p.name);
}

void Set::delParticle(Particle p) {
	// delete a particle from sets
	p.delIncludedSets(name);
	// find the particle from set
	auto it = std::find(particlesInSet.begin(), particlesInSet.end(), p.name);
	if (it != particlesInSet.end()) {
		// swap the particle to back and pop it
		using std::swap;
		swap(*it, particlesInSet.back());
		particlesInSet.pop_back();
	}
}

void Set::addForce(Force f) {
	// add a force in a set
	forcesInSet.push_back(f.name);
}

void Set::delForce(Force f) {
	// delete a force from sets
	auto it = std::find(forcesInSet.begin(), forcesInSet.end(), f.name);
	if (it != forcesInSet.end()) {
		using std::swap;
		swap(*it, forcesInSet.back());
		forcesInSet.pop_back();
	}
}
