#pragma once
#include "Animal.h"
class Path{
private:
	char* track;
	int racersNum;
	int* racersPos;
public:
	Path(int racersNum);
	~Path();
	void print();
	bool update(Animal** racers);
	void writeOuch(int pos);
};