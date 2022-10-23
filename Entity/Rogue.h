#pragma once
#include "../Entity/Player.h"
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

	void levelUp() override {
		this->hpMax += 50;
		this->hp = this->hpMax;

		this->strenght += 5;
		this->agility += 10;
		this->endurance += 5;
	}
};

