#pragma once
#include "../Traits/NameTrait.h"
#include "../Traits/PriceTrait.h"

class Armor : public NameTrait, public PriceTrait
{
private:
	int defence = 0;
public:
	Armor(string name, int defence) : NameTrait(name) {
		this->defence = defence;
		this->price = defence * FunctionHelper::getRandomNumber(10, 20);
	}

	void setDefence(int defence) { this->defence = defence; }
	int getDefence() { return this->defence; }

	void showData() {
		cout << "Name: " << this->name << ". Defence: " << this->defence << ". Price: " << this->price << ". " << endl;
	}
};

