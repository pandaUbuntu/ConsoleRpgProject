#include <iostream>
#include <conio.h>
#include <ctime>
#include "Service/Engine.h"
#include "Service/Event.h"
#include "Service/FunctionHelper.h"

using namespace std;

int main()
{
	srand(time(0));
	Engine* engine = new Engine();

	string name = "";
	int type = 0;

	cout << "Enter name: ";
	cin >> name;

	cout << "Choose your class: 1 - Barbarian, 2 - Rogue, 3 - Tank";
	cin >> type;

	Player* player = engine->createPlayer(name, type);
	Event* events = new Event(engine, player);

	bool isGame = true;

	while (isGame) {
		int chance = FunctionHelper::getRandomNumber(1, 100);
		//int chance = 1; // test

		if (chance <= 5) {
			cout << "Room with shop\n";
			events->shop();
		}
		else if (chance > 6 && chance <= 45) {
			cout << "Room with monster\n";
			events->fightWithMonster();
		}
		else if (chance > 46 && chance <= 70) {
			cout << "Random encounter\n";
			events->randomEvent();
		}
		else {
			cout << "Empty room\n";
		}

		cout << "Press 'c' to continue \n";
		cout << "Press 'q' to exit \n";

		char symbol = _getch();

		if (symbol == 'q') {
			isGame == false;
		}
		cout << "\033[2J\033[1;1H";
		
	}

	return 1;
}
