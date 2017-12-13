#include "Particle.h"
#include "Force.h"
#include <cmath>
#include <iostream>
#include <vector>

extern Particle * findParticle(std::vector<Particle> & particles, int name);
extern Force * findForce(std::vector<Force> & forces, int name);

Particle::Particle(int name_ptc, float m, float x, float y, float vx, float vy) {
	name = name_ptc;
	mass = m;
	Pos = { x, y };
	Pos_post = { x, y };
	Vel = { vx,vy };
	Vel_post = { vx,vy };
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

void Particle::calculate(std::vector<Particle> particles, std::vector<int> particlesInSet, std::vector<Force> forces, std::vector<int> forcesInSet, bool gravity, int t) {
	Vector3 sum_force = { 0, 0 };
	float a_x, a_y, d_x, d_y;
	const float g = 9.80665;
	if (isFixed == 0) {
		if (gravity) {
			for (int i = 0; i < particlesInSet.size(); i++) {
				Particle * particle = findParticle(particles, particlesInSet[i]);
				Vector3 displace = Pos.subtraction(particle->getPosition());
				float distance = sqrt(pow(displace.x, 2) + pow(displace.y, 2));
				float theta = atan(displace.y / displace.x);
				float grav = (g*mass*particle->getMass()) / pow(distance, 2);
				Vector3 gravity = { grav*cos(theta), grav*sin(theta) };
				sum_force = sum_force.add(gravity);
			}
		}
		for (int i = 0; i < forcesInSet.size(); i++) {
			Force * force = findForce(forces, forcesInSet[i]);
			sum_force = sum_force.add(force->Dir);
		}
		a_x = sum_force.x / mass;
		a_y = sum_force.y / mass;
		d_x = Vel.x*t + (1 / 2)*a_x*pow(t, 2);
		d_y = Vel.y*t + (1 / 2)*a_y*pow(t, 2);
		Vector3 disp = { d_x, d_y };
		Vector3 accel = { a_x*t, a_y*t };
		Pos_post = Pos_post.add(disp);
		Vel_post = Vel_post.add(accel);
	}
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

void Particle::init() {
	Pos = Pos_post;
	Vel = Vel_post;
}
