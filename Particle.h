#pragma once
#include <vector>
#include "Force.h"
#include "Vector3.h"


class Particle {
public:
	Particle(int name_ptc, double m, double x, double y, double vx, double vy);

	int name;
	int isFixed;

	Vector3 getPosition(), getVelocity();
	double getMass();
	void print();
	void calculate(std::vector<Particle> particles, std::vector<int> particlesInSet, std::vector<Force> forces, std::vector<int> forcesInSet, bool gravity, int t);
	std::vector<int> getIncludedSets();
	void addIncludedSets(int set_name);
	void delIncludedSets(int set_name);
	void init();
private:
	static int count;
	std::vector<int> includedSets;
	Vector3 Pos, Vel, Pos_post, Vel_post;
	double mass;
};