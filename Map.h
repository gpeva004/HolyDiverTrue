#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

class Enemy;

class Map {
private:
    int size;
    std::vector<std::vector<char>> grid;

    int playerX;
    int playerY;

public:
    Map();

    void generateRandom(int n);
    void print(const std::vector<Enemy>& enemies) const;
    void movePlayer(char input);

    int getSize() const { return size; }

    char getTile(int x, int y) const { return grid[y][x]; }
    bool isWalkable(int x, int y) const { return grid[y][x] != '#'; }

    

    int getPlayerX() const { return playerX; }
    int getPlayerY() const { return playerY; }

    void setTile(int x, int y, char value) { grid[y][x] = value; }
    void clear();
};

#endif
