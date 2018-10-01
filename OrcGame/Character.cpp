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