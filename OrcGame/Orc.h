#pragma once
#include "Character.h" 

class Orc : public Character {
public:
	void barrelRoll();
	void walk();
	short attack();
	short getHealth();
	void decreaseHealth(short t_value);
private:
	short	health = 5;
	short	atkPower = 2;
	short	dodge = 2;
	short	defence = 1;
};


