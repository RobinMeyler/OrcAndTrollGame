#pragma once
#include <iostream>
#include "Orc.h"
#include "Troll.h"
using namespace std;

void runTextInfo(short t_bossNum, Troll *t_enemy);
void runTextBattle(short t_bossNum);
short runAttack(Orc *t_player, Troll *t_enemy );
short runDefence(Orc *t_player, Troll *t_enemy);
short runDodge(Orc *t_player, Troll *t_enemy);
void runLevelUp();
void runBattle(short t_bossNum, Orc *t_player, Troll *t_enemy );

int main()
{
	Orc orc;
	Troll troll;
	Orc *player = &orc;
	Troll *enemy = &troll;

	// Orc **superPTR = &player;  // Example of a pointer to pointer
	short bossNum = 1;
	cout << "You're storming the castle, a troll attacks you from behind like a coward, \nYou brush him back, a fight ensues" << endl;
	while (player->getAlive() == true)
	{
		runTextInfo(bossNum, enemy);

		runBattle(bossNum, player, enemy);
		std::cout << "Your health left: " << orc.getHealth() << std::endl;
		std::cout << "Enemys health left: " << troll.getHealth() << std::endl;
		if (player->getAlive() == false)
		{
			break;
		}
		runLevelUp();

		bossNum++;
	}
	
	std::cout << "Game Over" << std::endl;
	system("PAUSE");
}

short runAttack(Orc *t_player, Troll *t_enemy)
{
	short enemyMove = 0;// t_enemy->radomizeAction();
	short stringDecider{ 0 };
	if (enemyMove == 0) // Attacks
	{
		t_player->decreaseHealth(t_enemy->attack());
		t_enemy->decreaseHealth(t_player->attack());
		stringDecider = 0;
	}
	else if (enemyMove == 1)	// Shields
	{
		t_player->decreaseHealth(1);

		stringDecider = 1;
	}
	else if (enemyMove == 2)	// Dodges
	{


		stringDecider = 2;
	}
	return stringDecider;
}
short runDefence(Orc *t_player, Troll *t_enemy)
{
	short enemyMove = t_enemy->radomizeAction();
	short stringDecider{ 0 };
	if (enemyMove == 0) // Attacks
	{
		stringDecider = 3;
	}
	else if (enemyMove == 1)	// Shields
	{
		stringDecider = 4;
	}
	else if (enemyMove == 2)	// Dodges
	{
		stringDecider = 5;
	}
	return stringDecider;
}
short runDodge(Orc *t_player, Troll *t_enemy)
{
	short enemyMove = t_enemy->radomizeAction();
	short stringDecider{ 0 };
	if (enemyMove == 0) // Attacks
	{
		stringDecider = 6;
	}
	else if (enemyMove == 1)	// Shields
	{
		stringDecider = 7;
	}
	else if (enemyMove == 2)	// Dodges
	{
		stringDecider = 8;
	}
	return stringDecider;
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
void runBattle(short t_bossNum, Orc *t_player, Troll *t_enemy)
{
	bool battle = true;
	short input = 0;
	short stringReturn{ 9 };
	while (battle == true)
	{
		cout << "What action do you take?" << endl;
		cout << "1: Attack, 2: Shield 3: Dodge" << endl;
		cin >> input;
		
		if (input == 1)
		{
			stringReturn = runAttack(t_player, t_enemy);
		}
		else if (input == 2)
		{
			stringReturn = runDefence(t_player, t_enemy);
		}
		else if (input == 3)
		{
			stringReturn = runDodge(t_player, t_enemy);

		}
		runTextBattle(stringReturn);
		if (t_enemy->getAlive() == false)
		{
			battle = false;
		}
		if (t_player->getAlive() == false)
		{
			break;
		}
	}
}
void runTextInfo(short t_bossNum, Troll *t_enemy)
{
	switch (t_bossNum)
	{
	case 1:
		std::cout << "" << std::endl;
		t_enemy->setBossStats(4,2,1,0);
		break;
	case 2:
		std::cout << "" << std::endl;
		t_enemy->setBossStats(6,2,2,1);
		break;
	case 3:
		std::cout << "" << std::endl;
		t_enemy->setBossStats(4,3,2,2);
		break;
	case 4:
		std::cout << "" << std::endl;
		t_enemy->setBossStats(8,3,2,2);
		break;
	case 5:
		std::cout << "" << std::endl;
		t_enemy->setBossStats(12,4,4,3);
		break;
	}
}

void runTextBattle(short t_bossNum)
{
	switch (t_bossNum)
	{
	case 0:
		std::cout << "The enemy also attacks, you both swing, damaging you both" << std::endl;
		break;
	case 1:
		std::cout << "" << std::endl;
		break;
	case 2:
		std::cout << "" << std::endl;
		break;
	case 3:
		std::cout << "" << std::endl;
		break;
	case 4:
		std::cout << "" << std::endl;
		break;
	case 5:
		std::cout << "" << std::endl;
		break;
	case 6:
		std::cout << "" << std::endl;
		break;
	case 7:
		std::cout << "" << std::endl;
		break;
	case 8:
		std::cout << "" << std::endl;
		break;
	}
}