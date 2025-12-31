#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
private:
    int x;
    int y;
    int enemyDmg;
    std::string type;

public:
    Enemy(int posX, int posY, int dmg, const std::string& t);

    int getX() const;
    int getY() const;
    int getEnemyDmg() const;
    std::string getType() const;

    void setPosition(int newX, int newY);
};

#endif
