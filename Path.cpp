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
	std::cout << tracks.back();
}

void Path::writeOuch(int pos) {
	std::string ouch("OUCH!!!");
	for (int i = pos; i < pos + 7; ++i) {
		(tracks.back()).at(i) = ouch[i-pos];
	}
}

void Path::printEnd(char name) {
	std::cout << name << " won" << std::endl;
}

bool Path::fillNewPath(Animal** racers) {
	curTrack = new std::string(Init::width, ' ');
	for (int i = 0; i < Init::racersNum; ++i) {
		curTrack[racers[i]->getPos()] = racers[i]->getName();
	}
	return false;
}
void Path::update() {
	tracks.push_back(*curTrack);
	tracksNum++;
}

std::string* Path::getCurTrack() {
	return curTrack;
}