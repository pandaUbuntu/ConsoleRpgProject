#pragma once
#include "Base�haracteristics.h"

class Monster : public Base�haracteristics
{
private:
	int damage = 0;
	int armor = 0;
	int rewardExperience = 0;
public:
	Monster(string name, int hp, int energy, int level) : Base�haracteristics(name, hp, energy) {
		this->damage = level * (2 + (1 + rand() % 10));
		this->armor = level * (2 + (1 + rand() % 10));
		this->rewardExperience = level * (50 + rand() % 100);
		this->level = level;
	}

	void setDamage(int damage) { this->damage = damage;  }
	int getDamage() { return this->damage; }

	void setArmor(int armor) { this->armor = armor; }
	int getArmor() { return this->armor; }

	void setRewardExperience(int rewardExperience) { this->rewardExperience = rewardExperience; }
	int getRewardExperience() { return this->rewardExperience; }
};

