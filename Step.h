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
	bool isOccup();
	void putSnack();
	void rmSnack();
	bool isSnack();
};

