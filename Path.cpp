#include "Path.h"
#include <iostream>
#include <string>

Path::Path(int num){
	track = new char[70];
	racersNum = num;
	racersPos = new int[num];
}

Path::~Path(){
	delete[] track;
}

void Path::print() {
	for (int i = 0; i < 70; ++i) {
		std::cout << track[i];
	}
}

void Path::writeOuch(int pos) {
	std::string ouch("OUCH!!!");
	for (int i = pos; i < pos + 7; ++i) {
		track[i] = ouch[i-pos];
	}
}

bool Path::update(Animal** racers) {
	for (int i = 0; i < racersNum; ++i) {//move racers
		racersPos[i] += racers[i]->defMove();
		if (racersPos[i] < 0) {	//check out of range case
			racersPos[i] = 0;
		}
		else if (racersPos[i] > 69) {
			return true;
		}
	}
	track = new char[70];
	//checking collusion for everyone
	for (int i = 0; i < racersNum-1; ++i){
		for (int j = i+1; j < racersNum; ++j) {
			if (racersPos[i] != racersPos[j]) {
				track[racersPos[i]] = racers[i]->getName();
			}
			else {
				writeOuch(racersPos[i]);
			}
		}
	}
	return false;
} 