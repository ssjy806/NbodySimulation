#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Particle.h"
#include "Set.h"
#include "Force.h"

using namespace std;

Particle * findParticle(vector<Particle> & particles, int name) {
	Particle * particle = NULL;
	if (particles.size() == 0) {
		return particle;
	}
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


int main(void) {
	vector<Set> sets;
	vector<Particle> particles;
	vector<Force> forces;
	bool gravity = true;
	while (1) {
		vector<string> inputs;
		string buffer;
		string rawInput;
		stringstream strStream;
		cout << "Enter a command: ";
		getline(cin, rawInput);
		strStream.str(rawInput);
		while (strStream >> buffer)
			inputs.push_back(buffer);
		if (inputs[0].length() != 2) {
			cout << "Unrecognized command!" << endl;
			continue;
		}
		switch (inputs[0][0]) {
		case 'p':
			switch (inputs[0][1]) {
			case 'a':
				cout << "in PA" << endl;
				break;
			case 'p': {
				if (inputs.size() != 2) {
					cout << "인수 더넣으셈" << endl;
					break;
				}
				Particle * particle = findParticle(particles, stoi(inputs[1]));
				if (particle != NULL) {
					particle->print();
				}
				else cout << "No particle with that number" << endl;
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
				cout << "Unrecognized command!" << endl;
				break;
			}
			break;
		case 'a':
			switch (inputs[0][1]) {
			case 'p': {
				if (inputs.size() != 7) {
					cout << "인수 더넣으셈" << endl;
					break;
				}
				Particle * particle = findParticle(particles, stoi(inputs[1]));
				if (particle == NULL) {
					float mass = stof(inputs[2]);
					float posX = stof(inputs[3]);
					float posY = stof(inputs[4]);
					float velX = stof(inputs[5]);
					float velY = stof(inputs[6]);
					Particle particleAdd = Particle(stoi(inputs[1]), mass, posX, posY, velX, velY);
					cout << "Particle " << particleAdd.name << " added" << endl;
					particles.push_back(particleAdd);
				}
				else
					cout << "Particle " << particle->name << " already exists." << endl;
				
			}
			break;
			case 's': {
				Set * set = findSet(sets, stoi(inputs[1]));
				if (set == NULL) {
					//add a set
				}
				else
					cout << "Set" << set << "already exists" << endl;
			}
			break;
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
			}
			break;
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
				cout << "Unrecognized command!" << endl;
				break;
			}
		break;
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
				cout << "Unrecognized command!" << endl;
				break;
			}
		break;
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
				cout << "Unrecognized command!" << endl;
				break;
			}
		break;
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
				cout << "Unrecognized command!" << endl;
				break;
			}
		break;
		case 'q':
			switch (inputs[0][1]) {
			case 'q': {
				//stop the simulation
				//delete all the particles, sets and forces
				//print memory
				break;
			}
			default:
				cout << "Unrecognized command!" << endl;
				break;
			}
		break;
		default:
			cout << "Unrecognized command!" << endl;
			break;
		}
	}
};