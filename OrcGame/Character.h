#pragma once

class Character
{
public:

	//Virtual
	void flip();
	virtual void walk();
	virtual short attack() = 0; //pure virtual function

	virtual short getHealth();
	virtual void decreaseHealth(short t_value) = 0;
	//Standard
	bool getAlive();
	void changeAliveStatus();

private:
	bool  isAlive = true;
	
};




