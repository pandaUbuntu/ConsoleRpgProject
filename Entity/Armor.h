#pragma once
#include "../Traits/NameTrait.h"

class Armor : public NameTrait
{
private:
	int defence = 0;
public:
	Armor(string name, int defence) : NameTrait(name) {
		this->defence = defence;
	}

	void setDefence(int defence) { this->defence = defence; }
	int getDefence() { return this->defence; }
};

