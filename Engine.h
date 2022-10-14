#pragma once
#include <vector>
#include "Tank.h"
#include "Rogue.h"
#include "Barbarian.h"
#include "FunctionHelper.h"
#include "Monster.h"

using namespace std;

class Engine
{
private:
	FunctionHelper* fH = NULL;
	vector<string> monsterName{"Terrorcat", "Poisonhound", "Gallfoot", "Smoggirl", "Blazesnake"};

	string getRandomName(vector<string> list) {
		return list[this->fH->getRandomNumber(0, list.size())];
	}

public:
	Engine(FunctionHelper* fH) {
		this->fH = fH;
	}

	Monster* generateMonster(int level) {
		return new Monster(this->getRandomName(this->monsterName), ((80 + fH->getRandomNumber(10, 50)) * level), ((10 + fH->getRandomNumber(1, 5)) * level), level);
	}

	Player* createPlayer(string name, int choosenType) {
		Player* player = NULL;

		if (choosenType == 1) {
			player = new Barbarian(name, 400, 80);
		}
		else if (choosenType == 2) {
			player = new Rogue(name, 350, 120);
		}
		else {
			player = new Tank(name, 500, 40);
		}

		return player;
	}
};

