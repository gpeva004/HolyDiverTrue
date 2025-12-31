#include "GameManager.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <conio.h>

using namespace std;

GameManager::GameManager() : running(false), player("Player", 100, 100, 3){}

bool GameManager::init() {


    map.generateRandom(20); // build a 20x20 map in code
    
	spawnEnemies(); // spawn enemies on the map

    running = true; 
    return true;
}
// Main game loop
void GameManager::run() {
    
    while (running) {
        system("cls");
        moveEnemies();
        map.print(enemies);
		// Display player stats trying to add later, give the value for the player in somewhere.
		
        cout << "Player: " << player.getName()
            << " | HP: " << player.getHealth()
            << " | Oxygen: " << player.getOxygen()
			<< " | Lives: " << player.getLives() << endl;

        cout << "Move with WASD\nTo quit press q\nTo restart game press r: ";
		char input = _getch(); // get input without Enter

        if (input == 'q') {
            
            cout << "Quitting game..." << endl;
            running = false;
        }
        else if (input == 'r') {
            restart();
        }

        else {
            handlePlayerMovement(input);
        }
    }
}




void GameManager::render() const {
    map.print(enemies);
}
void GameManager::handlePlayerMovement(char input) {

    int oldX = map.getPlayerX(); 
    int oldY = map.getPlayerY(); 

    map.movePlayer(input); 

    int newX = map.getPlayerX(); 
    int newY = map.getPlayerY();
    
    // Check for oxygen tank
    if (map.getTile(newX, newY) == 'O') {
        cout << "You found an oxygen tank! Oxygen restored.\n";

		player.setOxygen(100);  // 100 oxygen restored back to 100

        // Remove the tank from the map
        map.setTile(newX, newY, '.');
        cout << "Press any key to continue...";
        char input = _getch();
    }
    // Check if player stepped on treasure
    if (map.getTile(newX, newY) == 'T') {
        cout << "You found a treasure!\n";

        player.addTreasures();

        // Remove treasure from map
        map.setTile(newX, newY, '.');

        cout << "Treasures collected: " << player.getTreasures() << "/3\n";

        cout << "Press any key to continue...";
        char input = _getch();
    }
    if (player.getTreasures() >= 3) {
        cout << "You collected all treasures! You win!\n";
        nextLevel();
        return;
	}

    // Check enemy collision 
    for (auto& e : enemies) { 

        if (e.getX() == newX && e.getY() == newY) {
            cout << "Enemy " << e.getType()
                << " hits you for " << e.getEnemyDmg() << " damage!\n";
            cout << "Press any key to continue...";
            char input = _getch(); // to pause action, to see monster is dmg you

            player.setHealth(player.getHealth() - e.getEnemyDmg());

            if (player.getHealth() <= 0) {
                cout << "You died!" << endl;
                gameOver();
                return;
            }
        }
        
    } 
	// oxygen decrease
	int newOxygen = player.getOxygen() - 5;
    if (newOxygen < 0) newOxygen = 0;
	player.setOxygen(newOxygen);

    if (player.getOxygen() <= 0) {
        

		player.setHealth(player.getHealth() - 10);
        if (player.getHealth() <= 0) {
            cout << "You died due to lack of oxygen!" << endl;
            gameOver();
            return;
		}
	}
}
void GameManager::spawnEnemies() {
    enemies.clear(); 

    int countStationary = 0; 
    int countWandering = 0; 

    while (countStationary < 3) {

        int x = rand() % map.getSize(); 
        int y = rand() % map.getSize(); 

        if (!map.isWalkable(x, y)) continue; // Prevent overlapping enemies 

        bool occupied = false; 
        for (auto& e : enemies) 
            if (e.getX() == x && e.getY() == y) 
                occupied = true; 
        if (occupied) continue;

        enemies.push_back(Enemy(x, y, 10, "Monster")); 
        countStationary++; } 

    while (countWandering < 2) { 
        int x = rand() % map.getSize(); 
        int y = rand() % map.getSize(); 

        if (!map.isWalkable(x, y)) continue; 

        bool occupied = false; 
        for (auto& e : enemies) 
            if (e.getX() == x && e.getY() == y) 
                occupied = true; 

        if (occupied) continue; 

        enemies.push_back(Enemy(x, y, 5, "Wanderer")); 
        countWandering++; 
    } 
}
void GameManager::moveEnemies() { 
    for (auto& e : enemies) { 
        if (e.getType() == "Wanderer") { 

            int dir = rand() % 4; 

            int newX = e.getX(); 
            int newY = e.getY(); 

            if (dir == 0) newY--; 
            if (dir == 1) newY++; 
            if (dir == 2) newX--; 
            if (dir == 3) newX++; 

            // stay inside map 
            if (newX < 0 || newX >= map.getSize()) continue; 
            if (newY < 0 || newY >= map.getSize()) continue; 
            // avoid walls 
            if (map.getTile(newX, newY) == '#') continue; 
            
            if (map.isWalkable(newX, newY)) { 
                e.setPosition(newX, newY); 
            }
        } 
    } 
}
void GameManager::restart() {
    cout << "Restarting game...\n";
    
    map.clear();

    // Reset player
    player = Player("Player", 100, 100, 3);

    // Reset map
    init();
}
void GameManager::gameOver() {
    system("cls");
    cout << "=====================\n";
    cout << "      GAME OVER      \n";
    cout << "=====================\n\n";

    cout << "Press R to restart or Q to quit.\n";

    while (true) {
        char input = _getch();

        if (input == 'r' || input == 'R') {
            restart();
            return;   // go back to game loop
        }

        if (input == 'q' || input == 'Q') {
            running = false;
            return;
        }
    }
}
void GameManager::nextLevel() {
    system("cls");
    cout << "=== LEVEL COMPLETE! ===\n";
    cout << "Moving to the next level...\n";

    // Reset map
    map.clear();

    // Reset treasures
    player.resetTreasures();

    // Generate new map
    map.generateRandom(20);

    // Respawn enemies
    enemies.clear();

    // 3 stationary enemies
    for (int i = 0; i < 3; i++) {
        int x = rand() % map.getSize();
        int y = rand() % map.getSize();

        if (map.getTile(x, y) == '#') { i--; continue; }
        if (x == map.getPlayerX() && y == map.getPlayerY()) { i--; continue; }

        enemies.push_back(Enemy(x, y, 10, "Monster"));
    }

    // 2 wandering enemies
    for (int i = 0; i < 2; i++) {
        int x = rand() % map.getSize();
        int y = rand() % map.getSize();

        if (map.getTile(x, y) == '#') { i--; continue; }
        if (x == map.getPlayerX() && y == map.getPlayerY()) { i--; continue; }

        enemies.push_back(Enemy(x, y, 5, "Wanderer"));
    }

    cout << "Press any key to continue...";
    char input = _getch();
}
