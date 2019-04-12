#pragma once
#include <string>
class Animal{
protected:
	char _name;
	int _energy;
	int _pos;
	std::string _type;
	bool sleepFlag;

	Animal();
	~Animal();
public:
	int defNum();
	virtual int defMove() = 0;
	bool setPos();
	int getPos();
	void decreaseEnergy(int val);
	void setEnergy(int val);
	int getEnergy();
	bool isSleep();
	void getUp();
	std::string getType();
	//void setName();
	char getName();
	bool isOut();
	bool isFinished();
	void eatSnack();
	void bite();
};