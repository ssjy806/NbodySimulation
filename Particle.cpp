#include "Particle.h"
#include "Force.h"
#include <math.h>
#include <iostream>
#include <vector>

extern Particle * findParticle(std::vector<Particle> & particles, int name);
extern Force * findForce(std::vector<Force> & forces, int name);
extern Vector3 add(Vector3 v1, Vector3 v2);
extern Vector3 subtraction(Vector3 v1, Vector3 v2);
extern double distance(Vector3 v1, Vector3 v2);

Particle::Particle(int name_ptc, double m, double x, double y, double vx, double vy) {
	// particle imformation
	name = name_ptc;
	mass = m;
	Pos = { x, y };
	Pos_post = { x, y };
	Vel = { vx,vy };
	Vel_post = { vx,vy };
	isFixed = 0;
}

Vector3 Particle::getPosition() {
	// get position of particle
	return Pos;
}

Vector3 Particle::getVelocity() {
	// get velocity of particle
	return Vel;
}

double Particle::getMass() {
	// get mass of particle
	return mass;
}

void Particle::print() {
	// print imformation of particle
	std::cout << "Particle: " << name << std::endl;
	std::cout << "  Location: (" << Pos.x << "," << Pos.y << ")" << std::endl;
	std::cout << "  Velocity: (" << Vel.x << "," << Vel.y << ")" << std::endl;
}

void Particle::calculate(std::vector<Particle> particles, std::vector<int> particlesInSet, std::vector<Force> forces, std::vector<int> forcesInSet, bool gravity, int tick) {
	// caculate vectors of particles
	Vector3 sum_force = { 0, 0 };
	int t = tick;
	double a_x, a_y, d_x, d_y;
	const double g = 6.67384e-11;
	if (isFixed == 0) {
		if (gravity) {
			for (int i = 0; i < particlesInSet.size(); i++) {				
				Particle * particle = findParticle(particles, particlesInSet[i]);
				if (particle->name != name) {
					// create displace vector to calculate
					Vector3 displace = subtraction(particle->getPosition(), Pos);
					// calculate distance between vectors
					double distance = sqrt(pow(displace.x, 2) + pow(displace.y, 2));
					// use atan2 function to calculate in range -pi to pi
					double theta = atan2(displace.y, displace.x);
					// calculate gravity
					double grav = (g*mass*particle->getMass()) / pow(distance, 2);
					double gravity_x = grav*cos(theta);
					double gravity_y = grav*sin(theta);
					Vector3 gravity_calc = { gravity_x, gravity_y };
					sum_force = add(sum_force, gravity_calc);
				}
			}
		}
		for (int i = 0; i < forcesInSet.size(); i++) {
			// calculate sum of forces
			Force * force = findForce(forces, forcesInSet[i]);
			sum_force = add(sum_force, force->Dir);
		}
		// calculate accelation
		a_x = sum_force.x / mass;
		a_y = sum_force.y / mass;
		// calculate displacement
		d_x = (Vel.x*t) + (0.5*a_x*pow(t, 2));
		d_y = (Vel.y*t) + (0.5*a_y*pow(t, 2));
		Vector3 disp = { d_x, d_y };
		Vector3 accel = { a_x*t, a_y*t };
		Pos_post = add(Pos, disp);
		Vel_post = add(Vel, accel);
	}
}


std::vector<int> Particle::getIncludedSets() {
	// get particle from set
	return includedSets;
}

void Particle::addIncludedSets(int set_name) {
	includedSets.push_back(set_name);
}

void Particle::delIncludedSets(int set_name) {
	// delete particle from set
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
	// initialize particle position
	Pos = Pos_post;
	Vel = Vel_post;
}
