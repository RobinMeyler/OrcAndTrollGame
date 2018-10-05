#pragma once
#include <iostream>
#include "Orc.h"
#include "Troll.h"
using namespace std;

void runTextInfo(short t_bossNum);
void runAttack(Orc *t_player, Troll *t_enemy );
void runDefence(Orc *t_player, Troll *t_enemy);
void runDodge(Orc *t_player, Troll *t_enemy);
void runLevelUp();
void runBattle(short t_bossNum, Orc *t_player, Troll *t_enemy );

int main()
{
	Orc orc;
	Troll troll;
	Orc *player = &orc;
	Troll *enemy = &troll;
	Orc **superPTR = &player;  // Example of a pointer to pointer
	short bossNum = 1;
	cout << "You're storming the castle, a troll attacks you from behind like a coward, \nYou brush him back, a fight ensues" << endl;
	while (player->getAlive() == true)
	{
		runTextInfo(bossNum);

		runBattle(bossNum, player, enemy);
		
		runLevelUp();

		bossNum++;
	}
	
	
}

void runAttack(Orc *t_player, Troll *t_enemy)
{
	short enemyMove = t_enemy->radomizeAction();
	if (enemyMove == 0) // Attacks
	{
		t_player->decreaseHealth(t_enemy->attack());
		t_enemy->decreaseHealth(t_player->attack());
	}
	else if (enemyMove == 1)	// Shields
	{
		t_player->decreaseHealth(1);
	}
	else if (enemyMove == 2)	// Dodges
	{

	}

}
void runDefence(Orc *t_player, Troll *t_enemy)
{
	short enemyMove = t_enemy->radomizeAction();
	if (enemyMove == 0) // Attacks
	{
		
	}
	else if (enemyMove == 1)	// Shields
	{

	}
	else if (enemyMove == 2)	// Dodges
	{

	}
}
void runDodge(Orc *t_player, Troll *t_enemy)
{
	short enemyMove = t_enemy->radomizeAction();
	if (enemyMove == 0) // Attacks
	{
	
	}
	else if (enemyMove == 1)	// Shields
	{

	}
	else if (enemyMove == 2)	// Dodges
	{

	}
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
	while (battle == true)
	{
		cout << "What action do you take?" << endl;
		cout << "1: Attack, 2: Shield 3: Dodge" << endl;
		cin >> input;
		
		if (input == 1)
		{
			runAttack(t_player, t_enemy);
		}
		else if (input == 2)
		{
			runDefence(t_player, t_enemy);
		}
		else if (input == 3)
		{
			runDodge(t_player, t_enemy);
		}
	}
}
void runTextInfo(short t_bossNum)
{
	switch (t_bossNum)
	{
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
	}
}