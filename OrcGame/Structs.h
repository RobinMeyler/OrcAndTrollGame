#pragma once
#include "Orc.h"
#include "Troll.h"


struct LootTable
{
	
	short axe = 2;
	short sword = 4;
	short mace = 6;
	short kingsDagger = 10;

	short healthPack = 10;
	short mediPack = 5;

	short shield = 4;
	short forceField = 8;

	short invis = 6;
	short smoke = 3;

	short returnAtk() {
		std::srand(std::time(0));
		short random = rand() % 4;
		short toRet = 0;
		if (random == 1)
		{
			toRet = axe;
			std::cout << "You have recieved the Axe" << std::endl;
		}
		else if (random == 2)
		{
			toRet = sword;
			std::cout << "You have recieved the Sword" << std::endl;
		}
		else if (random == 3)
		{
			toRet = mace;
			std::cout << "You have recieved the Mace" << std::endl;
		}
		else if (random == 3)
		{
			toRet = kingsDagger;
			std::cout << "You have recieved the King's Dagger" << std::endl;
		}
		return toRet;
	};
	short returnDef() {
		std::srand(std::time(0));
		short random = rand() % 2;
		short toRet = 0;
		if (random == 1)
		{
			toRet = shield;
			std::cout << "You have recieved the Shield" << std::endl;
		}
		else if (random == 2)
		{
			toRet = forceField;
			std::cout << "You have recieved the ForceField" << std::endl;
		}
		
		return toRet;
	};
	short returnHP() {
		std::srand(std::time(0));
		short random = rand() % 2;
		short toRet = 0;
		if (random == 1)
		{
			toRet = healthPack;
			std::cout << "You have recieved the HealthPack" << std::endl;
		}
		else if (random == 2)
		{
			toRet = mediPack;
			std::cout << "You have recieved the MediPack" << std::endl;
		}

		return toRet;
	};
	short returnDodge() {
		std::srand(std::time(0));
		short random = rand() % 2;
		short toRet = 0;
		if (random == 1)
		{
			toRet = invis;
			std::cout << "You have recieved the Invisiblity" << std::endl;
		}
		else if (random == 2)
		{
			toRet = smoke;
			std::cout << "You have recieved the Smoke" << std::endl;
		}

		return toRet;
	};

};