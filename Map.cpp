#include "Map.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>

using namespace std;

Map::Map() : size(0), playerX(0), playerY(0) {
  
}

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

    // Random walls inside
    for (int i = 1; i < size - 1; ++i) {
        for (int j = 1; j < size - 1; ++j) {
            if (rand() % 5 == 0) grid[i][j] = '#'; // 20% chance of wall
        }
    }

    // Place player
    playerX = 10;
    playerY = 10;
    grid[playerY][playerX] = '.';
}
void Map::print() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == playerY && j == playerX)
                cout << 'P'; // draw player
            else
                cout << grid[i][j];
        }
        cout << endl;
    }
}
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