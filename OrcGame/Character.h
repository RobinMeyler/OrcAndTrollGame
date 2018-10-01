#pragma once

class Character
{
public:

	//Virtual
	void flip();
	virtual void walk();
	virtual void attack() = 0; //pure virtual function


	//Standard
	bool getAlive();
	void changeAliveStatus();

private:
	bool  isAlive = true;
	short	health;
	short	atkPower;
	short	dodge;
};




