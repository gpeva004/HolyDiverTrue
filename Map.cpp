#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <time.h>
using namespace std;

Map::Map() : size(0), playerX(0), playerY(0), enemyX(0), enemyY(0) {
  
}
// Generate a random map with walls, player, and enemies
void Map::generateRandom(int n) {
    size = n;
    grid.resize(size, vector<char>(size, '.'));

    // Add borders
    for (int i = 0; i < size; ++i) {
        grid[0][i] = '#';
        grid[size - 1][i] = '#';
        grid[i][0] = '#';
        grid[i][size - 1] = '#';
    }
    
    // Random walls inside map
        srand(time(NULL));
    for (int i = 1; i < size - 1; ++i) {
        
        for (int j = 1; j < size - 1; ++j) {
            
            if (rand() % 5 == 0) grid[i][j] = '#'; // 20% chance of wall
        }
    }

    // Place player
    playerX = 10;
    playerY = 10;
    grid[playerY][playerX] = '.';

	// Place enemy to random spots
	
    enemies.clear();
    for (int i = 0; i < 3; ++i) {
        int ex = rand() % (size - 2) + 1;
        int ey = rand() % (size - 2) + 1;
        enemies.push_back({ ey, ex });
        grid[ey][ex] = '.'; // Ensure enemy is not placed on a wall
    }
}
//Print the map to console
void Map::print() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == playerY && j == playerX) {
				cout << 'P'; // prints player to the map
            }
            else {
                bool isEnemy = false;
                for (const auto& enemy : enemies) {
                    if (i == enemy.first && j == enemy.second) {
						cout << 'E'; // prints enemy to the map
                        isEnemy = true;
                        break;
                    }
                }
                if (!isEnemy)
                    cout << grid[i][j];
            }
        }
        cout << endl;
    }
}
// Move player based on input
void Map::movePlayer(char input) {
    int newX = playerX;
    int newY = playerY;

    

    if (input == 'w') newY--;
    else if (input == 's') newY++;
    else if (input == 'a') newX--;
    else if (input == 'd') newX++;

    // check collision
    if (grid[newY][newX] != '#') {
        playerX = newX;
        playerY = newY;
    }
} 