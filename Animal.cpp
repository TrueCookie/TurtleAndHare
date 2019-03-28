#include "Animal.h"
#include <ctime>
#include <iostream>

Animal::Animal() {
	_energy = 20;
}

Animal::~Animal() {}

int Animal::defNum() {
	srand((unsigned int)time(nullptr));
	return rand() % 10 + 1;
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

