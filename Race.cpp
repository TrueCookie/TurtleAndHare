#include "Race.h"
#include <ctime>
#include <iostream>

Race::Race(Animal** animals, int racersNum){
	path = new Path(racersNum);
	racers = new Animal*[racersNum];
}

Race::~Race(){
	delete path;
	delete[] racers;
}

bool Race::update() {
	time_t prevTime = 0;
	if (time(nullptr) - prevTime >= 1) {
		int* racersShift = new int[racersNum];
		/*for (int i = 0; i < racersNum; ++i) {
			racersShift[i] = racers[i]->defMove();
		}*/
		this->move(racersShift);
	}
	prevTime = time(nullptr);
	return true;
}

void Race::process() {
	while(!finish()){
		this->update();
		path->print();
		this->printEnergy();
	}
}

void Race::printEnergy() {
	for (int i = 0; i < racersNum; ++i) {
		std::cout << racers[i]->getName() << ": " << racers[i]->getEnergy() << ' / ';
	}std::cout << std::endl;
}

bool Race::finish() {
	return path->update(racers);
}

void Race::move(int* racerShift) {
	path->update(racers);
}