#pragma once
#include "Animal.h"
class Game{
private:
	int racersNum;
public:
	Game();
	~Game();

	void start();
	int defRacersNum();
	Animal** defRacersType(int racersNum);
};

