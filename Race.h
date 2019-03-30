#pragma once
#include "Init.h"
#include "Animal.h"
#include "Hare.h"
#include "Turtle.h"
#include "Path.h"


class Race{
private:
	Path *path;
	Animal** racers;
	bool finish;
public:
	Race(Animal** animals);
	~Race();
	void move();
	bool update();
	void process();
	void printEnergy();
	void checkCollusion(std::string* curTrack);
	bool finished();
};

