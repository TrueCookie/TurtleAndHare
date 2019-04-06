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
	return _pos >= 69;
}

bool Animal::setPos() {
	_pos += defMove();
	if (isOut()) {
		_pos = 0;
	}
	else if (isFinished()) {
		_pos = 69;
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

std::string Animal::getType() {
	return _type;
}

char Animal::getName() {
	return _name;
}

void Animal::eatSnack() {
	if (_energy >= 25) {
		_energy = 20;
	}
	else {
		_energy += 5;
	}
}

void Animal::bite() {
	_energy -= 10;
}