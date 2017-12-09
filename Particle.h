#pragma once
#include <vector>
#include "Vector3.h"

class Particle {
public:
	Particle(int name_ptc, float m, float x, float y, float vx, float vy);


	int name;
	int isFixed;

	Vector3 getPosition(), getVelocity();
	float getMass();
	void print();
	void calculate();
	std::vector<int> getIncludedSets();
	void addIncludedSets(int set_name);
	void delIncludedSets(int set_name);

private:
	static int count;
	std::vector<int> includedSets;
	Vector3 Pos, Vel;
	float mass;
};