#pragma once

class Character
{
public:

	//Virtual
	void flip();
	virtual void walk();
	virtual short attack() = 0; //pure virtual function
	virtual short getShield() = 0;
	virtual short getHealth() = 0;
	virtual short getDodge() = 0;
	virtual void decreaseHealth(short t_value) = 0;
	virtual void weakenShield(short t_value) = 0;
	
	//Standard
	virtual bool getAlive();
	void changeAliveStatus();

private:
	bool  isAlive = true;
	
};




