#pragma once
#include"Character.h"

class Troll : public Character {
	public:
		Troll(short t_health, short t_atk, short t_def, short t_dodge);
		short attack();
		short radomizeAction();
		short getHealth();
		void decreaseHealth(short t_value);
	private:
		short	health = 3;
		short	atkPower = 1;
		short	shield = 2;
		short	dodge = 2;
};


