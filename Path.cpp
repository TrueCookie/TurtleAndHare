#include "Path.h"
#include "Init.h"
#include <iostream>
#include <string>

Path::Path(){
	tracksNum = 0;
	racersPos = new int[Init::racersNum];
}

Path::~Path(){
	//delete[] tracks;
}

void Path::print() {
	for (int i = 0; i < Init::width; ++i) {
		std::cout << tracks.back()[i].getOccupant();
	}
}

void Path::writeOuch(int pos) {
	std::string ouch("OUCH!!!");
	for (int i = pos; i < pos + 7; ++i) {
		(tracks.back())[i].setOccupant(ouch[pos + i]);
	}
}

void Path::printEnd(char name) {
	std::cout << name << " won" << std::endl;
}

void Path::pasteItems(Step*) {
	for (int i = 0; i < Init::width; ++i) {
		if()
	}
}

bool Path::fillNewPath(Animal** racers) {
	Step* track = new Step[Init::width];
	track->pasteItems();
	for (int i = 0; i < Init::racersNum; ++i) {
		if (track[racers[i]->getPos()].isEmpty()) {
			track[racers[i]->getPos()].setOccupant(racers[i]->getName());
			if()
		}else {
			writeOuch(racers[i]->getPos());
		}
	}
	curTrack = track;
	return false;
}

void Path::update() {
	tracks.push_back(curTrack);
	tracksNum++;
}

Step* Path::getCurTrack() {
	return curTrack;
}