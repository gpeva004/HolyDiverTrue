#include "Player.h"
using namespace std;

Player::Player(const string& playerName, int hp, int ox, int lv)
	: name(playerName), health(hp), oxygen(ox), lives(lv), treasures(0) {
}
int Player::getHealth() const { return health; }
int Player::getOxygen() const { return oxygen; }
int Player::getLives() const { return lives; }
string Player::getName() const { return name; }
int Player::getTreasures() const { return treasures; }


void Player::setHealth(int hp) { health = hp; }
void Player::setOxygen(int ox) {
    oxygen = ox;
    if (oxygen > 100) oxygen = 100;
}

void Player::setLives(int lv) { lives = lv; }


