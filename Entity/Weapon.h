#pragma once
#include "../Traits/NameTrait.h"
#include "../Traits/PriceTrait.h"

class Weapon : public NameTrait, public PriceTrait
{
private:
	int damage = 0;
public:
	Weapon(string name, int damage) : NameTrait(name) {
		this->damage = damage;
		this->price = damage * FunctionHelper::getRandomNumber(10, 20);
	}

	void setDamage(int damage) { this->damage = damage; }
	int getDamage() { return this->damage; }

	void showData() {
		cout << "Name: " << this->name << ". Damage: " << this->damage << ". Price: " << this->price << ". " << endl;
	}
};

