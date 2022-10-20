#pragma once
#include "Player.h"
class Rogue : public Player
{
private:
public:
	Rogue(string name, int hp, int energy) : Player(name, hp, energy) {
		this->className = "Rogue";
		this->strenght = 15;
		this->agility = 45;
		this->endurance = 20;
	}
};

