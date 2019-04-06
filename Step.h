#pragma once
class Step{
private:
	char _occupant;
	bool _snack;
public:
	Step();
	~Step();

	char getOccupant();
	void setOccupant(char occup);
	void setEmpty();
	bool isEmpty();
	void putSnack();
	void rmSnack();
	bool isSnack();
};

