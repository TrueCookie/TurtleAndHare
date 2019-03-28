#pragma once
class Animal{
protected:
	char _name;
	int _energy;

	Animal();
	~Animal();
public:
	virtual int defMove() = 0;
	int getEnergy();
	void setName();
	char getName();
	int defNum();
};