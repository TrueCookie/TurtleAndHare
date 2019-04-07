#pragma once
#include "Animal.h"
#include "Step.h"
#include <vector>
#include <string>
class Path{
private:
	Step* step = new Step;
	Step* track;
	int* racersPos;
	bool finishFlag;
public:
	Path();
	~Path();
	void initTrack();
	void print();
	void update(Animal** racers);
	//void fillNewPath(Animal** racers);
	void writeOuch(int pos);
	void printEnd(char name);
	bool getFinishFlag();
};