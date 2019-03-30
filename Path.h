#pragma once
#include "Animal.h"
#include <vector>
#include <string>
class Path{
private:
	int tracksNum;
	std::vector<std::string> tracks;
	std::string* curTrack;
	int* racersPos;
public:
	Path();
	~Path();
	void print();
	void update();
	bool fillNewPath(Animal** racers);
	void writeOuch(int pos);
	void printEnd(char name);
	std::string* getCurTrack();
};