#include "Hare.h"

Hare::Hare(){
	_energy = 20;
	_name = 'H';
	_type = "hare";
}

Hare::~Hare(){}

int Hare::defMove() {
	int randNum = defNum();
	if (randNum <= 2) {
		return 0;
	}
	else if(randNum >= 3 && randNum <= 4){
		return 9;
	}
	else if (randNum == 5) {
		return -12;
	}
	else if (randNum >= 6 && randNum <= 8) {
		return 1;
	}
	else if (randNum >= 9) {
		return -2;
	}
}

void Hare::isBitten() {
	_energy -= 5;
}