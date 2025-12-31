#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>
#include "Map.h"
#include "Player.h"
#include "Enemy.h"

class GameManager {
private:
    Map map;
    bool running;
    std::vector<Enemy> enemies;
    Player player;

public:
    GameManager();

    bool init();
    void run();
	void spawnEnemies();
	void moveEnemies();
    void handlePlayerMovement(char input);
    void render() const;
    void restart();
	void gameOver();
    void nextLevel();
};

#endif
