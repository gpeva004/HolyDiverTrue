#ifndef MAP_H
#define MAP_H

using namespace std;

#include <string>
#include <vector>

class Map {
private:
    int size;
    vector<vector<char>> grid;
    int playerX, playerY; // player position

public:
    Map();
	void generateRandom(int n);
    void print() const;
    void movePlayer(char input); // handle WASD input
};

#endif