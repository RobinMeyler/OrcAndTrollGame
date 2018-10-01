#pragma once
#include"Character.h"

class Troll : public Character {
	public:
		void attack();
	private:
		short	health = 3;
		short	atkPower = 1;
};


