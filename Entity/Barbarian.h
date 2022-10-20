#pragma once
#include "Player.h"
class Barbarian : public Player
{
private:
public:
	Barbarian(string name, int hp, int energy) : Player(name, hp, energy) {
		this->className = "Barbarian";
		this->strenght = 40;
		this->agility = 10;
		this->endurance = 30;
	}
};

