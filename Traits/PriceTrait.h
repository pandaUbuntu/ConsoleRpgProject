#pragma once
#include <iostream>
#include <string>

using namespace std;

class PriceTrait
{
protected:
	int price = 0;
public:
	void setPrice(int price) {
		this->price = price;
	}

	int getPrice() {
		return this->price;
	}
};

