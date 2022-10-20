#include <iostream>
#include "Service/Engine.h"

using namespace std;

int main()
{
	Engine* engine = new Engine();

	Player* player = engine->createPlayer("asd", 1);
	Monster* mob = engine->generateMonster(1);
	
	return 1;
}
