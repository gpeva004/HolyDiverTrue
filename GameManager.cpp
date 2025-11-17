#include "GameManager.h"
#include "Map.h"
#include "Player.h"
#include <iostream>
#include <conio.h>

using namespace std;

GameManager::GameManager() : running(false) {}

bool GameManager::init() {
    map.generateRandom(20); // build a 20x20 map in code
    
    running = true;
    return true;
}
// Main game loop
void GameManager::run() {
    
    while (running) {
        system("cls");
        map.print();
		// Display player stats trying to add later, give the value for the player in somewhere.
        //cout << "Player: " << player.getName()
        //    << " | HP: " << player.getHealth()
        //    << " | Oxygen: " << player.getOxygen()
		//	<< " | Lives: " << player.getLives() << endl;

        cout << "Move with WASD, q to quit: ";
		char input = _getch(); // get input without Enter

        if (input == 'q') {
            cout << endl;
            cout << "Quitting game..." << endl;
            running = false;
        }
        else {
            map.movePlayer(input);
        }
    }
}

void GameManager::handleInput(char input) {
    if (input == 'q') {

		
        running = false;
        
    }
}

void GameManager::update(char input) {
    map.movePlayer(input); // delegate movement to Map
}

void GameManager::render() const {
    map.print();
}