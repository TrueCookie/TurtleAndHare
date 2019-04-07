#include "Path.h"
#include "Init.h"
#include <iostream>
#include <string>

Path::Path(){
	racersPos = new int[Init::racersNum];
	track = new Step[Init::width];
	initTrack();
	finishFlag = false;
}

Path::~Path(){
	//delete[] tracks;
}

void Path::initTrack() {
	for (int i = 0; i < Init::width; ++i) {
		if (i % 10 == 0) {
			track[i].setOccupant('@');
		}
	}
}

void Path::print() {
	for (int i = 0; i < Init::width; ++i) {
		std::cout << track[i].getOccupant();
	}
}

void Path::writeOuch(int pos) {
	std::string ouch("OUCH!!!");
	int begin = pos;
	for (int i = pos; i < pos+7; ++i) {
		track[i].setOccupant(ouch[i-pos]);
	}
}

void Path::printEnd(char name) {
	std::cout << name << " won" << std::endl;
}

/*void Path::fillNewPath(Animal** racers) {
	for (int i = 0; i < Init::racersNum; ++i) {
		if (!track[racers[i]->getPos()].isOccup()) {
			track[racers[i]->getPos()].setOccupant(racers[i]->getName());
			if (track[racers[i]->getPos()].isSnack()) {
				racers[i]->eatSnack();
				track[racers[i]->getPos()].rmSnack();
			}
		}else {
			if (racers[i]->getType() == "hare") {
				racers[i]->bite();
			}
			writeOuch(racers[i]->getPos());
		}
	}
}*/

void Path::update(Animal** racers) {
	for (int i = 0; i < Init::racersNum; ++i) {
		track[racers[i]->getPos()].setEmpty();
		if (racers[i]->setPos()) {
			finishFlag = true;
		}
		int racerPos = racers[i]->getPos();
		if (track[racerPos].isSnack()) {
			racers[i]->eatSnack();
		}
		track[racerPos].setOccupant(racers[i]->getName());
	}
	for (int i = 0; i < Init::racersNum; ++i) {
		if (track[racers[i]->getPos()].isOccup() && racers[i]->getType() == "hare") {
			racers[i]->bite();
			writeOuch(racers[i]->getPos());
		}
	}
}

bool Path::getFinishFlag() {
	return finishFlag;
}