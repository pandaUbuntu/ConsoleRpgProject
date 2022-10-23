#pragma once
#include "../Entity/Player.h"

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

	void levelUp() override {
		this->hpMax +=	70;
		this->hp = this->hpMax;

		this->strenght += 10;
		this->agility += 5;
		this->endurance += 5;
	}
};

