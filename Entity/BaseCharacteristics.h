#pragma once
#include "../Traits/NameTrait.h"

class BaseCharacteristics : public NameTrait
{
protected:
	int hp = 0;
	int hpMax = 0;
	int energy = 0;
	int energyMax = 0;
	int level = 1;
public:
	BaseCharacteristics(string name, int hp, int energy) : NameTrait(name) {
		this->hp = hp;
		this->hpMax = hp;
		this->energy = energy;
		this->energyMax = energy;
	}

	void setHp(int hp) {
		if (hp > this->hpMax) {
			this->hp = this->hpMax;
		}
		else {
			this->hp = hp;
		}
	}

	void damageHp(int countHp) {
		if (this->hp - countHp > 0) {
			this->hp = this->hp - countHp;
		}
		else {
			this->hp = 0;
		}
	}
	int getHp() {
		return this->hp;
	}

	void setEnergy(int energy) {
		if (energy > this->energyMax) {
			this->energy = this->energyMax;
		}
		else {
			this->energy = energy;
		}
	}

	int getEnergy() {
		return this->energy;
	}

	void setHpMax(int maxHP) { this->hpMax = maxHP; }
	int getHpMax() { return this->hpMax; }
	int getEnergyMax() { return this->energyMax; }

	void setLevel(int level) { this->level = level; }
	void addLevel() { this->level++; }
	int getLevel() { return this->level; }
};

