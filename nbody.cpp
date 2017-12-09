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
	int timetick = 3600;
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
				for (int i = 0; i < particles.size(); i++) {
					particles[i].print();
				}
				break;
			case 'p': {
				if (inputs.size() != 2) {
					cout << "Insufficint parameters" << endl;
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
				if (inputs.size() != 2) {
					cout << "Insufficint parameters" << endl;
					break;
				}
				Set * set = findSet(sets, stoi(inputs[1]));
				if (set != NULL) {
					cout << "--- Set " << set->name << " ---" << endl;
					for (int i = 0; i < set->particlesInSet.size(); i++) {
						findParticle(particles, set->particlesInSet[i])->print();
					}
				}
				else cout << "No set with that number" << endl;
				break;
			}
			case 'f': {
				Force * force = findForce(forces, stoi(inputs[1]));
				if (force != NULL) {
					force->print();
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
					cout << "Insufficint parameters" << endl;
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
					Set setAdd = Set(stoi(inputs[1]));
					cout << "Set " << setAdd.name << " added" << endl;
					sets.push_back(setAdd);
				}
				else
					cout << "Set" << set->name << "already exists" << endl;
			}
			break;
			case 'e': {
				Set * set = findSet(sets, stoi(inputs[1]));
				Particle * particle = findParticle(particles, stoi(inputs[2]));
				if (set != NULL && particle != NULL) {
					set->addParticle(*particle);
					particle->addIncludedSets(set->name);
					cout << "Particle " << particle->name << " added to set " << set->name << endl;
				}
				else if (set == NULL && particle != NULL)
					cout << "No set with that number" << endl;
				else if (set != NULL && particle == NULL)
					cout << "No particle with that number" << endl;
				else
					cout << "No particle and set with that number" << endl;
			}
			break;
			case 'f': {
				Force * force = findForce(forces, stoi(inputs[1]));
				Set * set = findSet(sets, stoi(inputs[2]));
				float x = stof(inputs[3]);
				float y = stof(inputs[4]);
				if (set != NULL && force == NULL) {
					Force forceAdd = Force(stoi(inputs[1]), stoi(inputs[2]), x, y);
					set->addForce(forceAdd);
					forces.push_back(forceAdd);
					cout << "Force " << forceAdd.name << " added" << endl;
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
					vector<int> includedSets = particle->getIncludedSets();
					for(int i=0; i<includedSets.size(); i++)
					{
						Set * set = findSet(sets, includedSets[i]);
						set->delParticle(*particle);
					}
					int particle_name = particle->name;
					particles.erase(particles.begin()+distance(particles.data(), particle));
					cout << "Particle " << particle_name << " deleted" << endl;
				}
				else
					cout << "No particle with that number" << endl;
				break;
			}
			case 'e': {
				Particle * particle = findParticle(particles, stoi(inputs[1]));
				Set * set = findSet(sets, stoi(inputs[1]));
				if (set != NULL && particle != NULL) {
					set->delParticle(*particle)	;
					cout << "Particle " << particle->name << " deleted from set " << set->name << endl;
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
			case 't': { 
				timetick = stoi(inputs[1]);
				break;
			}
			case 'g': {
				if (inputs[1] == "true") {
					//enable gravity
					gravity = true;
					cout << "Gravity enabled" << endl;
				}
				else if (inputs[1] == "false") {
					//disable gravity
					gravity = false;
					cout << "Gravity disabled" << endl;
				}
				else { cout << "Cannot recognize status!" << endl;}
				break;
			}
			case 'p': {
				Particle * particle = findParticle(particles, stoi(inputs[1]));
				if (particle != NULL)
				{
					if (inputs[2] == "true") {
						particle->isFixed = 1;
						cout << "Particle " << particle->name << " is set to movable" << endl;
					}
					else if (inputs[2] == "false") {
						particle->isFixed = 0;
						cout << "Particle " << particle->name << " is set to fixed" << endl;
					}
					else { cout << "Cannot recognize status!" << endl; }
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
				forces.clear();
				cout << "All forces deleted" << endl;
				sets.clear();
				cout << "All sets deleted" << endl;
				particles.clear();
				cout << "All particles deleted" << endl;
				cout << "Particles: 0" << endl;
				cout << "Forces: 0" << endl;
				cout << "Sets: 0" << endl;
				return 0;
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