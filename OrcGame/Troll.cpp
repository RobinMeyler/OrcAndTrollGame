#include "Troll.h"
#include <iostream>
using namespace std;

Troll::Troll(short t_health, short t_atk, short t_def, short t_dodge)	:
	health{ t_health },
	atkPower{ t_atk },
	shield{ t_def },
	dodge{ t_dodge }

{
}


short Troll::attack()
{
	return atkPower;
}

short Troll::radomizeAction()
{
	short random = rand() % 3;
	return random;
}

short Troll::getHealth()
{
	return health;
}

void Troll::decreaseHealth(short t_value)
{
	health = health - t_value;
}