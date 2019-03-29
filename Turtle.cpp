#include "Turtle.h"

Turtle::Turtle(){
	_energy = 20;
	_name = 'T';
	_type = "turtle";
}

Turtle::~Turtle(){}

int Turtle::defMove() {
	int randNum = defNum();
	if (randNum >= 1 && randNum <= 5) {
		return 3;
	}
	else if (randNum >= 6 && randNum <= 7) {
		return -9;
	}
	else{
		return 1;
	}
}