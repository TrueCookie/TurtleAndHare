#include "Game.h"
#include "Race.h"
#include <iostream>

Game::Game(){
	racersNum = defRacersNum();
}


Game::~Game(){}

void Game::start() {
	Race race(defRacersType(racersNum), racersNum);
	race.process();
}

int Game::defRacersNum() {
	int num = 0;
	std::cin >> num;
	return num;
}

Animal** Game::defRacersType(int racersNum) {
	Animal** racers = new Animal*[racersNum];
	for (int i = 0; i < racersNum; i = i+2) {
		racers[i] = new Hare();
		racers[i+1] = new Turtle();
	}
	return racers;
}
