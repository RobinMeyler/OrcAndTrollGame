#include "Troll.h"
#include <iostream>
using namespace std;


short Troll::attack()
{
	return 5;
}

short Troll::radomizeAction()
{
	short random = rand() % 2;
	short toReturn = 0;
	if (random == 0)
	{
		toReturn = atkPower;
	}
	if (random == 1)
	{
		toReturn = atkPower;

	}
	if (random == 3)
	{
		toReturn = atkPower;
	}
	return toReturn;
}
