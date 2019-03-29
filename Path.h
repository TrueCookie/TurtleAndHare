#pragma once
#include "Animal.h"
#include <vector>
class Path{
private:
	int racersNum;

	int tracksNum;
	std::vector<char*> tracks;
	int* racersPos;
public:
	Path(int racersNum);
	~Path();
	void print();
	//bool move(Animal** racers);
	void checkCollusion(char** curTrack);
	bool update(Animal** racers);
	void writeOuch(int pos);
	void printEnd(char name);
};