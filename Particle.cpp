#include "Particle.h"
#include <iostream>

Particle::Particle(int name_ptc, float m, float x, float y, float vx, float vy) {
	name = name_ptc;
	mass = m;
	Pos = { x, y };
	Vel = { vx,vy };
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
