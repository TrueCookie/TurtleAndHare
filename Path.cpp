#include "Path.h"
#include "Init.h"
#include <iostream>
#include <string>

Path::Path(){
	track = new Step[Init::width];
	snacks = new bool[Init::width/10];
	initTrack();
	finishFlag = false;
	winner = {"NULL", "NULL"};
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
	for (int i = 0; i < Init::width / 10; ++i) {
		snacks[i] = true;
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

void Path::fill(Step* track) {
	int snackCount = 0;
	for (int i = 0; i < Init::width; ++i) {
		if(i % 10 == 0 && snacks[i / 10]){
			track[i].setOccupant('@');
			track[i].putSnack();
			snackCount++;
		}else if(i % 10 == 0 && !(snacks[i / 10])){
			track[i].setOccupant(' ');
			snackCount++;
		}else {
			track[i].setOccupant(' ');
		}
	}
}

void Path::putName(Animal* racer) {
	if (track[racer->getPos()].getOccupant() == 'T' && racer->getName() == 'H' || track[racer->getPos()].getOccupant() == 'H' && racer->getName() == 'T') {
		writeOuch(racer->getPos());
	}
	else {
		track[racer->getPos()].setOccupant(racer->getName());
	}
}

void Path::update(Animal** racers) {
	delete[] track;
	track = new Step[Init::width];
	fill(track);
	for (int i = 0; i < Init::racersNum; ++i) {
		if (!(racers[i]->isSleep())) {
			finishFlag = racers[i]->setPos();
			if (finishFlag) {
				winner = std::make_pair(racers[i]->getType(), racers[i]->getName());
				return;
			}
		}else {
			racers[i]->setEnergy(10);
			racers[i]->getUp();
		}
		putName(racers[i]);
		int pos = racers[i]->getPos();
		if (track[pos].isSnack()) {
			track[pos].rmSnack();
			racers[i]->eatSnack();
			snacks[(pos/10)] = false;
		}
	}
}

bool Path::getFinishFlag() {
	return finishFlag;
}

std::pair<std::string, std::string> Path::getWinner() {
	return winner;
}