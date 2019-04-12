#pragma once
#include "Animal.h"
#include "Step.h"
#include <vector>
#include <string>
class Path{
private:
	Step* track;
	bool* snacks;
	bool finishFlag;
	std::pair<std::string, std::string> winner;
public:
	Path();
	~Path();
	void initTrack();
	void fill(Step* track);
	void putName(Animal*);
	void print();
	void update(Animal** racers);
	void writeOuch(int pos);
	void printEnd(char name);
	bool getFinishFlag();
	std::pair<std::string, std::string> getWinner();
};