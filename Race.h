#pragma once
#include "Animal.h"
#include "Hare.h"
#include "Turtle.h"
#include "Path.h"


class Race{
private:
	Path *path;
	int racersNum;
	Animal** racers;
public:
	Race(Animal** animals, int racersNum);
	~Race();
	bool update();
	void process();
	void printEnergy();
	bool finish();
	void move(int* racerShift);
};

