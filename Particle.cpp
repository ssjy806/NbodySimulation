#include "Particle.h"

int Particle::count = 0;

Particle::Particle(int name_ptc, float m, float x, float y, float vx, float vy)
{
	name = name_ptc;
	mass = m;
	Pos = { x, y };
	Vel = { vx,vy };
	count += 1;
}

Particle::~Particle()
{
	count -= 1;
}

Vector Particle::getPosition()
{
	return Pos;
}

Vector Particle::getVelocity()
{
	return Vel;
}

float Particle::getMass()
{
	return mass;
}

void Particle::calculate()
{
}
