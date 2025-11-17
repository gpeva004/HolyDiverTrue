#ifndef PLAYER_H
#define PLAYER_H
 


#include <iostream>
#include <string>

using namespace std;

class Player {
private:

	string name;
	int oxygen;
	int lives;	
	int health;
	
public:
	
	
	Player(const string& playerName, int hp, int ox, int lv)
		: name(playerName), health(hp), oxygen(ox), lives(lv) {} // named as "Player", a struct containing relevant player data is declared
	
	int getHealth() const { return health; }
	int getOxygen() const { return oxygen; }
	int getLives() const { return lives; }
	string getName() const { return name; }

	// Setters (optional)
	void setHealth(int hp) { health = hp; }
	void setOxygen(int ox) { oxygen = ox; }
	void setLives(int lv) { lives = lv; }
};
#endif