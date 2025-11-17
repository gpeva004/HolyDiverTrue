
#include "GameManager.h"

using namespace std;

int main() {
	GameManager game;
	if (!game.init()) return -1;
	game.run();
	return 0;
}

