#pragma once
#include <iostream>
#include <string>

using namespace std;

class NameTrait
{
protected:
	string name = "";
public:
	NameTrait(string name) {
		this->name = name;
	}

	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return this->name;
	}
};

