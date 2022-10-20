#pragma once
#include "Player.h"
class Tank : public Player
{
private:
public:
	Tank(string name, int hp, int energy) : Player(name, hp, energy) {
		this->className = "Tank";
		this->strenght = 25;
		this->agility = 10;
		this->endurance = 45;
	}
};

