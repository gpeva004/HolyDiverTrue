#include <iostream>
#include <string>

using namespace std;

class Player {
private:

	string name;
	int health;
	int oxygen;
	int lives;

public:

	Player(const string& playerName, int hp, int ox, int lv)
		: name(playerName), health(hp), oxygen(ox), lives(lv) { // named as "Player", a struct containing relevant player data is declared
	}
};