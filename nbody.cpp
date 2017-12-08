#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "nbody.h"
#include "Particle.h"
#include "Set.h"
#include "Force.h"

using namespace std;

Particle * findParticle(vector<Particle> & particles, int name) {
	Particle * particle = NULL;
	for (int i = 0; i < particles.size(); i++) {
		if (particles[i].name == name) {
			particle = &particles[i];
			break;
		}
		else continue;
	}
	return particle;
}

Set * findSet(vector<Set> & sets, int name) {
	Set * set = NULL;
	for (int i = 0; i < sets.size(); i++) {
		if (sets[i].name == name) {
			set = &sets[i];
			break;
		}
		else continue;
	}
	return set;
}

Force * findForce(vector<Force> & forces, int name) {
	Force * force = NULL;
	for (int i = 0; i < forces.size(); i++) {
		if (forces[i].name == name) {
			force = &forces[i];
			break;
		}
		else continue;
	}
	return force;
}


void main() {
	vector<Set> sets;
	vector<Particle> particles;
	vector<Force> forces;
	bool gravity = true;
	while (1) {
		vector<string> inputs;
		string buffer;
		string rawInput;
		stringstream strStream;
		cin >> rawInput;
		strStream.str(rawInput);
		while (strStream >> buffer)
			inputs.push_back(buffer);
		switch (inputs[0][0]) {
		case 'p':
			switch (inputs[0][1]) {
			case 'a':
				//print info about all the particles
				break;
			case 'p': {
				try {
					Particle * particle = findParticle(particles, stoi(inputs[1]));
					if (particle != NULL)
					{
						//print info about particle
					}
					else cout << "No particle with that number" << endl;
				}
				catch (const char* msg) {
					cout << "No particle with that number" << endl;
				}
				break;
			}
			case 's': {
				Set * set = findSet(sets, stoi(inputs[1]));
				if (set != NULL) {
					//print info about set
				}
				else cout << "No set with that number" << endl;
				break;
			}
			case 'f': {
				Force * force = findForce(forces, stoi(inputs[1]));
				if (force != NULL) {
					//print info about set
				}
				else cout << "No force with that number" << endl;
				break;
			}
			default:
				break;
			}
		case 'a':
			switch (inputs[0][1]) {
			case 'p': {
				float mass = stof(inputs[2]);
				float posX = stof(inputs[3]);
				float posY = stof(inputs[4]);
				float velX = stof(inputs[5]);
				float velY = stof(inputs[6]);
				Particle * particle = &Particle(stoi(inputs[1]), mass, posX, posY, velX, velY);
				particles.push_back(*particle);
				break;
			}
			case 's': {
				Set * set = findSet(sets, stoi(inputs[1]));
				if (set == NULL) {
					//add a set
				}
				else
					cout << "Set" << set << "added" << endl;
				break;
			}
			case 'e': {
				Set * set = findSet(sets, stoi(inputs[1]));
				Particle * particle = findParticle(particles, stoi(inputs[1]));
				if (set != NULL && particle != NULL) {
					//add a particle to a set			
				}
				else if (set == NULL && particle != NULL)
					cout << "No set with that number" << endl;
				else if (set != NULL && particle == NULL)
					cout << "No particle with that number" << endl;
				else
					cout << "No particle and set with that number" << endl;
				break;
			}
			case 'f': {//set size error not included
				Force * force = findForce(forces, stoi(inputs[1]));
				Set * set = findSet(sets, stoi(inputs[1]));
				int x = inputs[1][0];
				int y = inputs[1][1];
				if (set != NULL && force == NULL) {
					//add a force which is imposed on the particles in set <set> whose size is given as a vector (x, y)
				}
				else if (set == NULL && force == NULL)
					cout << "No set with that number" << endl;
				else if (set != NULL && force != NULL)
					cout << "force" << force << "added" << endl;
				else
					cout << "No set with that number and force" << force << "added" << endl;
				break;
			}
			default:
				break;
			}
		case 'd':
			switch (inputs[0][1]) {
			case 'p': {
				Particle * particle = findParticle(particles, stoi(inputs[1]));
				if (particle != NULL)
				{
					//delete particle
				}
				else
					cout << "No particle with that number" << endl;
				break;
			}
			case 'e': {
				Particle * particle = findParticle(particles, stoi(inputs[1]));
				Set * set = findSet(sets, stoi(inputs[1]));
				if (set != NULL && particle != NULL) {
					//delete particle from set		
				}
				else if (set == NULL && particle != NULL)
					cout << "No set with that number" << endl;
				else if (set != NULL && particle == NULL)
					cout << "No particle with that number" << endl;
				else
					cout << "No particle and set with that number" << endl;
				break;
			}
			case 'f': {
				Force * force = findForce(forces, stoi(inputs[1]));
				if (force != NULL)
				{
					//delete force
				}
				else
					cout << "No force with that number" << endl;
				break;
			}
			case 'a': {
				// delete all particles, sets and forces
				break;
			}
			default:
				break;
			}
		case 'c':
			switch (inputs[0][1]) {
			case 't': { //tick??
						//change timetick
				break;
			}
			case 'g': {
				if (gravity == true) {
					//enable gravity
					gravity = false;
				}
				else {
					//disable gravity
					gravity = true;
				}
				break;
			}
			case 'p': {
				Particle * particle = findParticle(particles, stoi(inputs[1]));
				if (particle != NULL)
				{
					//fix or unfix the location of particle, depending on bool
				}
				else
					cout << "No particle with that number" << endl;
				break;
			}
			default:
				break;
			}
		case 'r':
			switch (inputs[0][1]) {
			case 'u': {
				//run the simulation for <duration> seconds
				break;
			}
			case 'v': {
				//run the simulation for <duration> seconds and print out the location of each particle (x and y coordinates) at each tick
				break;
			}
			default:
				break;
			}
		case 'q':
			switch (inputs[0][1]) {
			case 'q': {
				//stop the simulation
				//delete all the particles, sets and forces
				//print memory
				break;
			}
			default:
				break;
			}
		}
	}
};