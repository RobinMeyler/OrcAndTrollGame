#pragma once

class Character
{
public:

	//Virtual
	void flip();
	virtual void walk();
	virtual short attack() = 0; //pure virtual function
	short getDodge();

	//Standard
	bool getAlive();
	void changeAliveStatus();

private:
	bool  isAlive = true;
	short	health;
	short	atkPower;
	short	dodge = 5;
};




