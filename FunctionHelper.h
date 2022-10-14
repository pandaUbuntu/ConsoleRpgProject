#pragma once
#include <algorithm>

using namespace std;

class FunctionHelper
{
public:
	int getRandomNumber(int min, int max) {
		if (min > max) {
			swap(min, max);

			return min + rand() % (max - min + 1);
		}
	}
};

