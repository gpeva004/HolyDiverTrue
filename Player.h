#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int oxygen;
    int lives;
    int health;
    int treasures;

public:
    Player(const std::string& playerName, int hp, int ox, int lv);

    int getHealth() const;
    int getOxygen() const;
    int getLives() const;
    std::string getName() const;
	int getTreasures() const;

    void setHealth(int hp);
    void setOxygen(int ox);
    void setLives(int lv);
    void addTreasures() { treasures++; }
    void resetTreasures() { treasures = 0; }
};

#endif
