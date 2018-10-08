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
		//short emyShield = 
		if (t_enemy->getShield() >= t_player->attack())
		{
			t_player->decreaseHealth(1);
			t_enemy->weakenShield(t_player->attack());
			stringDecider = 1;
		}
		else
		{
			t_enemy->decreaseHealth(t_player->attack() - t_enemy->getShield());
			stringDecider = 9;
		}
		
	}
	else if (enemyMove == 2)	// Dodges
	{
		if (rand() % t_player->getDodge() + 1 < t_enemy->getDodge())
		{
			t_player->decreaseHealth(1);
			stringDecider = 2;
		}
		else
		{
			t_enemy->decreaseHealth(t_player->attack() * 0.5);
			stringDecider = 10;
		}

	}
	return stringDecider;
}


short runDefence(Orc *t_player, Troll *t_enemy)
{
	short enemyMove = t_enemy->radomizeAction();
	short stringDecider{ 0 };
	if (enemyMove == 0) // Attacks
	{
		if (t_player->getShield() >= t_enemy->attack())
		{
			t_enemy->decreaseHealth(2);
			if (t_enemy->getAlive() == true)
			{
				t_player->weakenShield(t_enemy->attack());
			}
			stringDecider = 3;
		}
		else
		{
			t_player->decreaseHealth(t_enemy->attack() - t_player->getShield());
			stringDecider = 11;
		}
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
		if (rand() % (t_enemy->getDodge()) + 1 < t_player->getDodge())
		{
			t_enemy->decreaseHealth(2);
			stringDecider = 6;
		}
		else
		{
			t_player->decreaseHealth(t_enemy->attack() * 0.5);
			stringDecider = 12;
		}
		
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
		std::cout << std::endl;
		std::cout << "Your health left: " << t_player->getHealth() << std::endl;
		std::cout << "Enemys health left: " << t_enemy->getHealth() << std::endl;
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
		t_enemy->setBossStats(4,2,2,0);
		break;
	case 2:
		std::cout << "" << std::endl;
		t_enemy->setBossStats(6,2,4,1);
		break;
	case 3:
		std::cout << "" << std::endl;
		t_enemy->setBossStats(4,3,2,2);
		break;
	case 4:
		std::cout << "" << std::endl;
		t_enemy->setBossStats(8,3,6,2);
		break;
	case 5:
		std::cout << "" << std::endl;
		t_enemy->setBossStats(12,4,8,3);
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
		std::cout << "The enemy shields your attack, the recoil hurts you a bit" << std::endl;
		break;
	case 2:
		std::cout << "The enemy dodges your attack, you hurt yourself with the follow through" << std::endl;
		break;
	case 3:
		std::cout << "You shield the enemies attack, your shield is damaged but the Troll has hurt himself" << std::endl;
		break;
	case 4:
		std::cout << "You size each other up, holding your shields with vigor, nothing happens" << std::endl;
		break;
	case 5:
		std::cout << "He dodges your block, terrifying, nothing happens" << std::endl;
		break;
	case 6:
		std::cout << "You dodge the Troll's attack, both his feels and health are hurt" << std::endl;
		break;
	case 7:
		std::cout << "He shields your dodge, you both look confused and embarrassed" << std::endl;
		break;
	case 8:
		std::cout << "You out dodge each other, who is a most slippery? only the gods will know" << std::endl;
		break;
	case 9:
		std::cout << "The Troll's shield breaks, you take some follow through damage" << std::endl;
		break;
	case 10:
		std::cout << "The enemy's dodge was unsuccessful, he takes some damage" << std::endl;
		break;
	case 11:
		std::cout << "Your shield can't handle the force, you take some damage" << std::endl;
		break;
	case 12:
		std::cout << "Your dodge was unsuccessful, you are hurt" << std::endl;
		break;
	}
}