#include "Animal.h"
#include <ctime>
#include <iostream>

Animal::Animal() {
	_energy = 20;
	_pos = 0;
}

Animal::~Animal() {}

int Animal::defNum() {
	srand((unsigned int)time(nullptr));
	return rand() % 10 + 1;
}

bool Animal::isOut() {
	return _pos < 0;
}

bool Animal::isFinished() {
	return _pos > 69;
}

bool Animal::setPos() {
	_pos += defMove();
	if (isOut()) {	//check out of range case
			_pos = 0;
	}
	else if (isFinished()) {	//racer won
			return true;
	}
	return false;
}

int Animal::getPos() {
	return _pos;
}

int Animal::getEnergy() {
	return _energy;
}

void Animal::setName() {
	char name = 'X';
	std::cin >> name;
	_name = name;
}

char Animal::getName() {
	return _name;
}