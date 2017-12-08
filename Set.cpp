#include "Set.h"

Set::Set(int name_set)
{
	int name = name_set;
}

Set::~Set()
{
}

void Set::addParticle(Particle *p)
{
	particlesInSet.push_back(*p);
}

void Set::delParticle(Particle *p)
{
}
