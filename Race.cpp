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
	while(!finished()){
		this->update();
		path->fillNewPath(racers);
		path->update();
		path->print();
		checkCollusion(path->getCurTrack());
		this->printEnergy();
	}
}

void Race::move() {
	for (int i = 0; i < Init::racersNum; ++i) {
		finish = racers[i]->setPos();
	}
}

void Race::printEnergy() {
	for (int i = 0; i < Init::racersNum; ++i) {
		std::cout << racers[i]->getName() << ": " << racers[i]->getEnergy() << ' / ';
	}std::cout << std::endl;
}

void Race::checkCollusion(std::string* curTrack) {
	for (int i = 0; i < Init::racersNum - 1; ++i) {
		for (int j = i + 1; j < Init::racersNum; ++j) {
			if (racers[i]->getPos() != racers[j]->getPos()) {
				curTrack[racers[i]->getPos()] = racers[i]->getName();
			}
			else {
				path->writeOuch(racers[i]->getPos());
			}
		}
	}
}

bool Race::finished() {
	return finish;
}