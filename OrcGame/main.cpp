#pragma once
#include <iostream>
#include "Orc.h"
#include "Troll.h"
using namespace std;

void runTextInfo(short t_bossNum);
void runAttack();
void runDefence();
void runDodge();
void runLevelUp();
void runBattle(short t_bossNum);

int main()
{
	Orc orc;
	Troll troll;
	Character *player = &orc;
	Character *enemy = &troll;
	short bossNum = 1;
	cout << "You're storming the castle, a troll attacks you from behind\nlike a coward, you brush him back, a fight ensues" << endl;
	while (player->getAlive() == true)
	{
		runTextInfo(bossNum);

		runBattle(bossNum);
		
		runLevelUp();

		bossNum++;
	}
	
	
}

void runAttack()
{

}
void runDefence()
{

}
void runDodge()
{

}
void runLevelUp()
{
	short input = 0;
	cout << "Which stat would you like to increase?" << endl;
	cout << "1: Attack, 2: Shield 3: Dodge 4: Hp" << endl;
	while (input < 1 && input > 4)
	{
		cout << "1: Attack, 2: Shield 3: Dodge 4: Hp" << endl;
		cin >> input;
	}
	if (input == 1)
	{

	}
	else if (input == 2)
	{
		
	}
	else if (input == 3)
	{

	}
	else if (input == 3)
	{

	}
}
void runBattle(short t_bossNum)
{
	bool battle = true;
	short input = 0;
	while (battle == true)
	{
		cout << "What action do you take?" << endl;
		cout << "1: Attack, 2: Shield 3: Dodge" << endl;
		cin >> input;
		if (input == 1)
		{
			runAttack();
		}
		else if (input == 2)
		{
			runDefence();
		}
		else if (input == 3)
		{
			runDodge();
		}
	}
}
void runTextInfo(short t_bossNum)
{
	switch(t_bossNum)
	case 1: 
		break;
}