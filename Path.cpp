#include "Path.h"
#include <iostream>
#include <string>

Path::Path(int num){
	tracksNum = 0;
	//tracks = new char*[tracksNum];
	racersNum = num;
	racersPos = new int[num];
}

Path::~Path(){
	//delete[] tracks;
}

void Path::print() {
	for (int i = 0; i < 70; ++i) {
		std::cout << tracks.back[i];
	}
}

void Path::writeOuch(int pos) {
	std::string ouch("OUCH!!!");
	for (int i = pos; i < pos + 7; ++i) {
		tracks.back[i] = ouch[i-pos];
	}
}

/*bool Path::move(Animal** racers) {
	for (int i = 0; i < racersNum; ++i) {//move racers
		racersPos[i] += racers[i]->defMove();
		if (racersPos[i] < 0) {	//check out of range case
			racersPos[i] = 0;
		}
		else if (racersPos[i] > 69) {
			printEnd(racers[racersPos[i]]->getName);
			return true;
		}
	}
	return false;
}*/


void Path::printEnd(char name) {
	std::cout << name << " won" << std::endl;
}

void Path::checkCollusion(char** curTrack) {
	for (int i = 0; i < racersNum - 1; ++i) {
		for (int j = i + 1; j < racersNum; ++j) {
			if (racersPos[i] != racersPos[j]) {
				curTrack[racersPos[i]] = racers[i]->getName();
			}
			else {
				writeOuch(racersPos[i]);
			}
		}
	}
}

bool Path::update(Animal** racers) {
	char* curTrack = new char[70];
	memset(curTrack, ' ', 70);
	for (int i = 0; i < racersNum; ++i) {
		curTrack[racers[i]->getPos()] = racers[i]->getName();
	}
	checkCollusion(&curTrack);
	tracks.push_back(curTrack);
	return false;
} 