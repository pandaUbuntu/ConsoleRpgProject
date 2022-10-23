#pragma once
#include <vector>
#include "../Entity/Tank.h"
#include "../Entity/Rogue.h"
#include "../Entity/Barbarian.h"
#include "../Service/FunctionHelper.h"
#include "../Entity/Monster.h"

using namespace std;

class Engine
{
private:
	vector<string> monsterName{"Terrorcat", "Poisonhound", "Gallfoot", "Smoggirl", "Blazesnake"};
	vector<string> armorName{"Leather Armor", "Steel cuirass", "Mithril mail", "Wooden fullplate", "Magic robe"};
	vector<string> weaponName{"Knife", "Sword", "Spear", "Halberd", "Bow"};

	string getRandomName(vector<string> list) {
		return list[FunctionHelper::getRandomNumber(0, FunctionHelper::getArrayLastKey(list.size()))];
	}

public:
	Engine() {
	}

	Monster* generateMonster(int level) {
		return new Monster(this->getRandomName(this->monsterName), ((80 + FunctionHelper::getRandomNumber(10, 50)) * level), ((10 + FunctionHelper::getRandomNumber(1, 5)) * level), level);
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

	Weapon* generateWeapon() {
		return new Weapon(this->getRandomName(this->weaponName), FunctionHelper::getRandomNumber(3, 20));
	}

	Armor* generateArmor() {
		return new Armor(this->getRandomName(this->armorName), FunctionHelper::getRandomNumber(3, 20));
	}
};

