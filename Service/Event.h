#pragma once
#include "../Entity/Player.h"
#include "../Service/Engine.h"
#include "../Entity/Weapon.h"
#include "../Entity/Armor.h"
#include <vector>


class Event {
private:
	Player* player = NULL;
	Engine* engine = NULL;

	vector<Weapon*> createAssortmentWeaponShop() {
		vector<Weapon*> list;

		for (int i = 0; i < FunctionHelper::getRandomNumber(3, 7); i++) {
			list.push_back(this->engine->generateWeapon());
		}

		return list;
	}

	vector<Armor*> createAssortmentArmorShop() {
		vector<Armor*> list;

		for (int i = 0; i < FunctionHelper::getRandomNumber(3, 7); i++) {
			list.push_back(this->engine->generateArmor());
		}

		return list;
	}

	void showAssortmentWeaponList(vector<Weapon*> list) {
		for (int i = 0; i < list.size(); i++) {
			cout << i + 1 << ". ";
			list[i]->showData();
		}
	}

	void showAssortmentArmorList(vector<Armor*> list) {
		for (int i = 0; i < list.size(); i++) {
			cout << i + 1 << ". ";
			list[i]->showData();
		}
	}

	bool checkChoice(int position, int size) {
		if (position >= 0 && position < size) {
			return true;
		}

		return false;
	}
public:
	Event(Engine* engine) {
		this->engine = engine;
	}

	void shop(int type) {
		int choice = 0;
		FunctionHelper::enterInt("Select a product?");
		if (type == 1)
		{
			cout << "Armor Shop.\n";
			vector<Armor*> list = this->createAssortmentArmorShop();
			this->showAssortmentArmorList(list);
			cin >> choice;

			if (this->checkChoice(choice-1, list.size)) {
				if (this->player->checkPossibilityPurchase(list[choice - 1]->getPrice())) {
					this->player->reduceMoney(list[choice - 1]->getPrice());
					this->player->setArmor(list[choice - 1]);

					cout << "you have successfully made a purchase";
				}
				else {
					cout << "You don't have enough money\n";
				}
			}
			else {
				cout << "You have selected the wrong product\n";
			}
		}
		else {
			cout << "Weapon Shop.\n";
			vector<Weapon*> list = this->createAssortmentWeaponShop();
			this->showAssortmentWeaponList(list);

			cin >> choice;

			if (this->checkChoice(choice - 1, list.size)) {
				if (this->player->checkPossibilityPurchase(list[choice - 1]->getPrice())) {
					this->player->reduceMoney(list[choice - 1]->getPrice());
					this->player->setWeapon(list[choice - 1]);

					cout << "you have successfully made a purchase";
				}
				else {
					cout << "You don't have enough money\n";
				}
			}
			else {
				cout << "You have selected the wrong product\n";
			}
		}
	}

	void randomEvent() {
		int random = FunctionHelper::getRandomNumber(1, 5);

		if (random == 1) {
			cout << "Add Hp" << endl;
			this->player->setHpMax(this->player->getHpMax() + 100);
			this->player->setHp(this->player->getHpMax());
		}
		else if (random == 2) {
			cout << "Add STR" << endl;
			this->player->addStrenght(10);
		}
		else if (random == 3) {
			cout << "Add AGL" << endl;
			this->player->addAgility(10);
		}
		else if (random == 4) {
			cout << "Add END" << endl;
			this->player->addEndurance(10);
		}
		else if (random == 5) {
			cout << "Add EXP" << endl;
			this->player->addExp(100);
		}
		else {
			cout << "Add Money" << endl;
			this->player->addMoney(560);
		}
	}

	bool fightWithMonster() {
		Monster* mob = this->engine->generateMonster(this->player->getLevel());
	}
};