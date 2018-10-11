#pragma once
#include <iostream>
#include "Orc.h"
#include "Troll.h"
#include "Structs.h"

using namespace std;

void runTextInfo(short t_bossNum, Character *t_char[]);				// Function declarations
void runTextBattle(short t_bossNum);
short runAttack(Character *t_char[]);
short runDefence(Character *t_char[]);
short runDodge(Character *t_char[]);
void runLevelUp(LootTable *itemPointers, Character *t_char[]);
void runBattle(short t_bossNum, Character *t_char[] );

int main()
{
	
	LootTable item;								// Loot table and pointer
	LootTable *itemPointers = &item;
	Character *gameCharacters[2];						// Pointer to an array of characters
	Character **gameCharactersArrPnt = gameCharacters;		// Pointer to a pointer of the array
	gameCharacters[0] = &Orc(1);									// Declaring the characters
	gameCharacters[1] = &Troll(4, 2, 2, 0);

	std::cout << "Your hp: " << gameCharacters[0]->getHealth() 
				<< " Atk: " << gameCharacters[0]->attack()
				<< " Def: " << gameCharacters[0]->getShield() 
				<< " Dodge: " << gameCharacters[0]->getDodge() << std::endl;

	// Orc **superPTR = &player;  // Example of a pointer to pointer
	short bossNum = 1;
	cout << "You're storming the castle, a troll attacks you from behind like a coward, \nYou brush him back, a fight ensues" << endl;
	while (gameCharacters[0]->getAlive() == true)
	{
		runTextInfo(bossNum, gameCharactersArrPnt);								// Setting current boss stats and outputting their info
		std::cout << "Enemy Stats hp: " << gameCharacters[1]->getHealth() 
				<< " Atk: " << gameCharacters[1]->attack()
				<< " Def: " << gameCharacters[1]->getShield() 
				<< " Dodge: " << gameCharacters[1]->getDodge() << std::endl;

		runBattle(bossNum, gameCharactersArrPnt);					// Battle loop, passing the double pointer and current boss number
		
		if (gameCharacters[0]->getAlive() == false)				// Checking if you have died
		{
			break;
		}
		runLevelUp(itemPointers, gameCharacters);			// run to the loot chest

		bossNum++;												// Next boss
	}
	
	std::cout << "Game Over" << std::endl;
	system("PAUSE");
}
void runBattle(short t_bossNum, Character *t_char[])
{
	bool battle = true;
	short input = 0;
	short stringReturn{ 0 };
	
	std::cout << "-----------------------------------------------------------------" << std::endl;
	while (battle == true)
	{
		cout << "What action do you take?" << endl;
		cout << "1: Attack, 2: Shield 3: Dodge" << endl;
		cin >> input;

		if (input == 1)
		{
			stringReturn = runAttack(t_char);					// Swaps to the specific function based on the user's input
		}
		else if (input == 2)
		{
			stringReturn = runDefence(t_char);
		}
		else if (input == 3)
		{
			stringReturn = runDodge(t_char);

		}
		runTextBattle(stringReturn);					// Battle info
		std::cout << std::endl;
		std::cout << "-----------------------------------------------------------------" << std::endl;
	
		std::cout << "Your health left: " << t_char[0]->getHealth() << std::endl;
		if (t_char[1]->getHealth() > 0) {													// Enemy health
			std::cout << "Enemys health left: " << t_char[1]->getHealth() << std::endl;
		}
		if (t_char[1]->getAlive() == false)					// Characters alive?
		{
			battle = false;
		}
		if (t_char[0]->getAlive() == false)
		{
			break;
		}
	}
}
short runAttack(Character *t_char[])
{
	short enemyMove = t_char[1]->randomizeAction();				// Randomize enemy action

	short stringDecider{ 0 };
	if (enemyMove == 0) // Attacks
	{
		t_char[0]->decreaseHealth(t_char[1]->attack());
		t_char[1]->decreaseHealth(t_char[0]->attack());
		stringDecider = 0;
	}
	else if (enemyMove == 1)	// Shields
	{
		if (t_char[1]->getShield() >= t_char[0]->attack())			// If the shield is strong
		{
			t_char[0]->decreaseHealth(1);
			t_char[1]->weakenShield(t_char[0]->attack());
			stringDecider = 1;
		}
		else
		{
			t_char[1]->decreaseHealth(t_char[0]->attack() - t_char[1]->getShield());		// IF the shield is broken
			stringDecider = 9;
		}
		
	}
	else if (enemyMove == 2)	// Dodges
	{
		if (rand() % t_char[0]->getDodge() + 1 < t_char[1]->getDodge())
		{
			t_char[0]->decreaseHealth(1);
			stringDecider = 2;
		}
		else
		{
			t_char[1]->decreaseHealth(t_char[0]->attack() * 0.5);
			stringDecider = 10;
		}

	}
	return stringDecider;
}


short runDefence(Character *t_char[])
{
	short enemyMove = t_char[1]->randomizeAction();
	short stringDecider{ 0 };
	if (enemyMove == 0) // Attacks
	{
		if (t_char[0]->getShield() >= t_char[1]->attack())
		{
			t_char[1]->decreaseHealth(2);
			if (t_char[1]->getAlive() == true)
			{
				t_char[0]->weakenShield(t_char[1]->attack());
			}
			stringDecider = 3;
		}
		else
		{
			t_char[0]->decreaseHealth(t_char[1]->attack() - t_char[0]->getShield());
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
short runDodge(Character *t_char[])
{
	short enemyMove = t_char[1]->randomizeAction();
	short stringDecider{ 0 };
	if (enemyMove == 0) // Attacks
	{
		if (rand() % (t_char[0]->getDodge()) + 1 < t_char[0]->getDodge())
		{
			t_char[0]->decreaseHealth(2);
			stringDecider = 6;
		}
		else
		{
			t_char[0]->decreaseHealth(t_char[0]->attack() * 0.5);
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
void runLevelUp(LootTable *itemPointers, Character *t_char[])
{
	short input = 0;
	short newStats = 0;
	cout << "You have beaten the beast, you find yourself with a bit of time and a loot chest, why not, huh?" << endl;
	cout << "Which stat would you like to increase?" << endl;
	cout << "Take a chance at the loot chest, results my vary?" << endl;
	cout << "1: Attack, 2: Shield 3: Dodge 4: Hp" << endl;
	cin >> input;
	while (input < 1 && input > 4)
	{
		cout << "1: Attack, 2: Shield 3: Dodge 4: Hp" << endl;
		cin >> input;
	}
	if (input == 1)				// Randomizes the loot based on the user's input and increases the player's stats based on that
	{
		newStats = itemPointers->returnAtk();
		t_char[0]->setStats(t_char[0]->getHealth(),t_char[0]->attack()+newStats, t_char[0]->getShield(), t_char[0]->getDodge());
	}
	else if (input == 2)
	{
		newStats = itemPointers->returnDef();
		t_char[0]->setStats(t_char[0]->getHealth(), t_char[0]->attack(), t_char[0]->getShield() + newStats, t_char[0]->getDodge());
	}
	else if (input == 3)
	{
		newStats = itemPointers->returnDodge();
		t_char[0]->setStats(t_char[0]->getHealth(), t_char[0]->attack(), t_char[0]->getShield(), t_char[0]->getDodge() + newStats);
	}
	else if (input == 4)
	{
		newStats = itemPointers->returnHP();
		t_char[0]->setStats(t_char[0]->getHealth() + newStats, t_char[0]->attack(), t_char[0]->getShield(), t_char[0]->getDodge());
	}
	std::cout << "Your stat has been increased" << std::endl;
	std::cout << "Your hp: " << t_char[0]->getHealth() << " Atk: " << t_char[0]->attack()  
						<< " Def: " << t_char[0]->getShield() << " Dodge: " << t_char[0]->getDodge() << std::endl;
}

void runTextInfo(short t_bossNum, Character *t_char[])
{
	switch (t_bossNum)
	{
	case 1:
		std::cout << "" << std::endl;
		t_char[1]->setStats(4,2,2,0);
		break;
	case 2:
		std::cout << "" << std::endl;
		t_char[1]->setStats(6,2,4,1);
		break;
	case 3:
		std::cout << "" << std::endl;
		t_char[1]->setStats(4,3,2,2);
		break;
	case 4:
		std::cout << "" << std::endl;
		t_char[1]->setStats(8,3,6,2);
		break;
	case 5:
		std::cout << "" << std::endl;
		t_char[1]->setStats(12,4,8,3);
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