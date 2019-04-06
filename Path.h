#pragma once
#include "Animal.h"
#include "Step.h"
#include <vector>
#include <string>
class Path{
private:
	int tracksNum;
	Step* step = new Step;
	std::vector<Step*> tracks;
	Step* curTrack;
	int* racersPos;
public:
	Path();
	~Path();
	void print();
	void update();
	void pasteItems(Step*);
	bool fillNewPath(Animal** racers);
	void writeOuch(int pos);
	void printEnd(char name);
	Step* getCurTrack();
};