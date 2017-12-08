#pragma once
#include "Vector.h"

class Particle {
public:
	Particle(int name_ptc, float m, float x, float y, float vx, float vy);
	~Particle();

	static int count;
	int name;
	bool isFixed;

	Vector getPosition(), getVelocity();
	float getMass();
	void calculate();

private:
	Vector Pos, Vel;
	float mass;
};