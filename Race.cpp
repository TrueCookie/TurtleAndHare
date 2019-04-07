#include "Init.h"
#include "Race.h"
#include <ctime>
#include <iostream>

Race::Race(Animal** animals){
	path = new Path();
	racers = animals;
	finish = false;
}

Race::~Race(){
	delete path;
	delete[] racers;
}

bool Race::update() {
	time_t prevTime = 0;
	if (time(nullptr) - prevTime >= 1) {
		move();
	}
	prevTime = time(nullptr);
	return true;
}

void Race::process() {
	time_t prevTime = 0;
	while(!(path->getFinishFlag())){
		if (time(nullptr) - prevTime >= 1) {
			path->update(racers);
			path->print();
			this->printEnergy();
			prevTime = time(nullptr);
		}
		
	}
	end();
}

void Race::end() {
	std::cout << winner.first << " " << winner.second << " win!!!" << std::endl << "Congratulations!!!";
}

void Race::move() {
	for (int i = 0; i < Init::racersNum; ++i) {
		finish = racers[i]->setPos();
		if (finish) {
			winner = std::make_pair(racers[i]->getType(), racers[i]->getName());
		}
	}
}

void Race::printEnergy() {
	std::cout << "| Energy: ";
	for (int i = 0; i < Init::racersNum; ++i) {
		std::cout << racers[i]->getName() << ": " << racers[i]->getEnergy() << " / ";
	}std::cout << std::endl;
}

bool Race::finished() {
	return finish;
}