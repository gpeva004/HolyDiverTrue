#include "Enemy.h"

using namespace std;

Enemy::Enemy(int posX, int posY, int dmg, const string& t) 
	: x(posX), y(posY), enemyDmg(dmg), type(t) {
}
int Enemy::getX() const { return x; }
int Enemy::getY() const { return y; }
int Enemy::getEnemyDmg() const { return enemyDmg; }
string Enemy::getType() const { return type; }

void Enemy::setPosition(int newX, int newY) { 
	x = newX; 
	y = newY; 
}
