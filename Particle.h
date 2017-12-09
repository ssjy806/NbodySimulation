#pragma once
#include <vector>
#include "Vector3.h"

class Particle {
public:
	Particle(int name_ptc, float m, float x, float y, float vx, float vy);
	~Particle();


	int name;
	int isFixed;

	Vector3 getPosition(), getVelocity();
	float getMass();
	void print();
	void calculate();
	void clear();
	std::vector<int> sets;

private:
	static int count;
	Vector3 Pos, Vel;
	float mass;
};