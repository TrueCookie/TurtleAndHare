#pragma once
#include <string>
class Animal{
protected:
	char _name;
	int _energy;
	int _pos;
	std::string _type;

	Animal();
	~Animal();
public:
	int defNum();
	virtual int defMove() = 0;
	bool setPos();
	int getPos();
	int getEnergy();
	std::string getType();
	void setName();
	char getName();
	void medHelp();
	bool isOut();
	bool isFinished();
	void eatSnack();
};