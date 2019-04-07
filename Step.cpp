#include "Step.h"

Step::Step(){
	_snack = false;
	_occupant = ' ';
}

Step::~Step(){}

char Step::getOccupant() {
	return _occupant;
}

void Step::setOccupant(char occup) {
	_occupant = occup;
}

void Step::setEmpty() {
	_occupant = ' ';
}

bool Step::isOccup() {
	return (_occupant != ' ' && _occupant != '@');
}

void Step::putSnack() {
	_snack = true;
}

bool Step::isSnack() {
	return _snack;
}

void Step::rmSnack() {
	_snack = false;
}