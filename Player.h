#pragma once
#include "BaseÑharacteristics.h"

class Player : public BaseÑharacteristics
{
protected:
	int strenght = 0;
	int agility = 0;
	int endurance = 0;
	int exp = 0;
	int levelCup = 1000;
	string className = "";
public:
	Player(string name, int hp, int energy) : BaseÑharacteristics(name, hp, energy) {

	}

	void setStrenght(int strenght) { this->strenght = strenght; }
	int getStrenght() { return this->strenght; }
	void addStrenght(int strenght) { this->strenght += strenght; }

	void setAgility(int agility) { this->agility = agility; }
	int getAgility() { return this->agility; }
	void addAgility(int agility) { this->agility += agility; }

	void setEndurance(int endurance) { this->endurance = endurance; }
	int getEndurance() { return this->endurance; }
	void addEndurance(int endurance) { this->endurance += endurance; }

	void addExp(int exp) {
		if (exp + this->exp >= this->levelCup) {
			this->exp = (exp + this->exp) - this->levelCup;

			this->level++;
			this->levelCup = 1000 * this->level;
		}
		else {
			this->exp += exp;
		}
	}
	int getExp() { return this->exp; }
	int getLevelCup() { return this->levelCup; }
};

