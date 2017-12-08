#pragma once
#include "Vector3.h"

class Particle {
public:
	Particle(int name_ptc, float m, float x, float y, float vx, float vy);
	~Particle();

	static int count;
	int name;
	bool isFixed;

	Vector3 getPosition(), getVelocity();
	float getMass();
	void print();
	void calculate();

private:
	Vector3 Pos, Vel;
	float mass;
};