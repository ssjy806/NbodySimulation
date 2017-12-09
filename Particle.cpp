#include "Particle.h"
#include <iostream>

Particle::Particle(int name_ptc, float m, float x, float y, float vx, float vy) {
	name = name_ptc;
	mass = m;
	Pos = { x, y };
	Vel = { vx,vy };
	isFixed = 0;
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

std::vector<int> Particle::getIncludedSets() {
	return includedSets;
}

void Particle::addIncludedSets(int set_name) {
	includedSets.push_back(set_name);
}

void Particle::delIncludedSets(int set_name) {
	for(int i=0; i<includedSets.size(); i++)
	{
		if(includedSets[i]==set_name)
		{
			includedSets.erase(includedSets.begin()+i);
			break;
		}
		else continue;
	}
}