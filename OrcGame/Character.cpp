#include "Character.h"
#include <iostream>
using namespace std;


void Character::flip()
{ 
	cout << "I know how to flip and I will flipping do it" << endl; 
}

 void Character::walk()
{ 
	cout << "just in case they are too young to walk yet" << endl;
}

 short Character::randomizeAction()
 {
	 short random = rand() % 3;
	 return random;
 }


 bool Character::getAlive()
 { 
	 return isAlive;
 }

 void Character::changeAliveStatus()
 {
	 if (isAlive == true) 
	 { 
		 isAlive = false;
	 }
	 else
	 {
		 isAlive = true;
	 }
 }

 short Character::getHealth()
 {
	 return 0;
 }

 
