#include "Orc.h"
#include <iostream>
using namespace std;


void Orc::barrelRoll()
{
	cout << "rooooooolllllllllllinggggggg" << endl;
}
void Orc::walk()
{ 
	cout << "Doopers have a really cool walk!" << endl; 
}
short Orc::attack()
{ 
	return atkPower;
}

short Orc::getHealth()
{
	return health;
}

void Orc::decreaseHealth(short t_value)
{
	health = health - t_value;
}

bool Orc::getAlive()
{
	if (health > 0)
	{
		isAlive = true;
	}
	else
	{
		isAlive = false;
	}
	return isAlive;
}

