#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <time.h>
using namespace std;

Map::Map() : size(0), playerX(0), playerY(0){
  
}
// Generate a random map with walls, player
void Map::generateRandom(int n) {
    
    /*Load a map from files
    maybebaby
	ifstream file("Levels/Map1.txt");
    */

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

    // Place oxygen tanks 3 oxygens
    for (int i = 0; i < 3; i++) {
        int x = rand() % (size - 2) + 1;
        int y = rand() % (size - 2) + 1;

        if (grid[y][x] == '#') { i--; continue; }  // avoid walls
        if (x == playerX && y == playerY) { i--; continue; }

        grid[y][x] = 'O';  // O = oxygen tank
    }
    // Place 3 treasures)
    for (int i = 0; i < 3; i++) {
        int x = rand() % (size - 2) + 1;
        int y = rand() % (size - 2) + 1;

        if (grid[y][x] == '#') { i--; continue; }
        if (x == playerX && y == playerY) { i--; continue; }

        grid[y][x] = 'T';  // Treasure
    }

}
//Print the map to console
void Map::print(const vector<Enemy>& enemies) const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {

            if (i == playerY && j == playerX) {
				cout << 'P'; // prints player to the map
				continue;
            }
            
            bool isEnemy = false; 
             
            for (const auto& e : enemies) {
                if (e.getX() == j && e.getY() == i) { 

                    // Print based on enemy type 
                    if (e.getType() == "Wanderer") 
                        cout << 'E'; 
                    else 
                        cout << 'M'; 
                    isEnemy = true; 
                    break; 
                }
            }

            if (!isEnemy) 
                cout << grid[i][j];

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
    
    //if (grid[newY][newX] == 'T'){
    //    cout << "You found a treasure!" << endl;
    //}
}
void Map::clear() {
    grid.clear();
    size = 0;
    playerX = 0;
    playerY = 0;
}
