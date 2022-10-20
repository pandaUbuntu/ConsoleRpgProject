#pragma once
#include <algorithm>

using namespace std;

class FunctionHelper
{
public:
	static int getRandomNumber(int min, int max) {
		if (min > max) {
			swap(min, max);

			return min + rand() % (max - min + 1);
		}
	}

	static int getArrayLastKey(int size) {
		return size - 1;
	}
};

