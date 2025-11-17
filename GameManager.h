#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

using namespace std;

#include "Map.h"
#include "Player.h"

  

class GameManager {
private:
    Map map;
    bool running;

public:
    GameManager();
    bool init();                           // load map, setup game
    void run();                            // main loop
    void handleInput(char input);          // process input
    void update(char input);               // update game state
    void render() const;                   // draw map
    
    
    };

#endif
