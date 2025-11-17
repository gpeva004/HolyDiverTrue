#ifndef MAP_H
#define MAP_H

using namespace std;

#include <string>
#include <vector>
#include <utility>

class Map {
private:
    int size;
    vector<vector<char>> grid;
	vector<pair<int, int> > enemies; // store enemy positions
    int playerX, playerY; // player position
	int enemyX, enemyY; // enemy position

public:
    Map();
	void generateRandom(int n);
    void print() const;
    void movePlayer(char input); // handle WASD input
};

#endif