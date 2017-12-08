#include "Particle.h"
#include <iostream>
int Particle::count = 0;

Particle::Particle(int name_ptc, float m, float x, float y, float vx, float vy) {
	name = name_ptc;
	mass = m;
	Pos = { x, y };
	Vel = { vx,vy };
	count += 1;
	std::cout << "Particle" << name << "added" << std::endl;
}

Particle::~Particle() {
	count -= 1;
	std::cout << "Particle" << name << "deleted" << std::endl;
}

Vector3 Particle::getPosition() {
	return Pos;
}

Vector3 Particle::getVelocity() {
	return Vel;
}

float Particle::getMass() {
	return mass;
}

void Particle::print() {
	std::cout << "Particle: " << name << std::endl;
	std::cout << "  Location: (" << Pos.x << "," << Pos.y << ")" << std::endl;
	std::cout << "  Velocity: (" << Vel.y << "," << Vel.y << ")" << std::endl;
}
void Particle::calculate()
{
}
