#pragma once
#include"Character.h"

class Troll : public Character {
	public:
		short attack();
		short radomizeAction();
	private:
		short	health = 3;
		short	atkPower = 1;
		short	shield = 2;
};


