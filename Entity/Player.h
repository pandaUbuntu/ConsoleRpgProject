#pragma once
#include "Entity/BaseÑharacteristics.h"
#include "Service/FunctionHelper.h"
#include "Entity/Weapon.h"
#include "Entity/Armor.h"

class Player : public BaseÑharacteristics
{
protected:
	int strenght = 0;
	int agility = 0;
	int endurance = 0;
	int exp = 0;
	int levelCup = 1000;
	string className = "";
	Weapon* weapon = NULL;
	Armor* armor = NULL;

public:
	Player(string name, int hp, int energy) : BaseÑharacteristics(name, hp, energy) {}

	void setWeapon(Weapon* weapon) { this->weapon = weapon; }
	Weapon* getWeapon() { return this->weapon; }

	void setArmor(Armor* armor) { this->armor = armor; }
	Armor* getArmor() { return this->armor; }

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

	int getDamage() {
		int damage = (this->strenght / 5) * 3;

		if (this->weapon == NULL) {
			damage += this->weapon->getDamage();
		}

		if (FunctionHelper::getRandomNumber(1, 100) < this->agility / 5) {
			damage *= 2;
		}

		return damage;
	}

	int getDefence() {
		int defence = (this->endurance / 5) * 3;

		if (this->armor == NULL) {
			defence += this->armor->getDefence();
		}

		return defence;
	}
};

