#pragma once
#include "Traits/NameTrait.h"

class Weapon : public NameTrait
{
private:
	int damage = 0;
public:
	Weapon(string name, int damage) : NameTrait(name) {
		this->damage = damage;
	}

	void setDamage(int damage) { this->damage = damage; }
	int getDamage() { return this->damage; }
};

