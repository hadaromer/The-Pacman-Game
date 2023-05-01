#ifndef _GHOS_MANAGER_H_
#define _GHOS_MANAGER_H_

#include <cstring>
#include "Ghost.h"

class ThePacmanGame;

const Color COLORS_FOR_GHOSTS[4] = { RED,MAGENTA, LIGHTBLUE, BROWN };
const int NUMBER_OF_COLORS = 4;

class GhostManager {
	int numberOfGhosts;
	Ghost* ghosts;
	int currentGhosts = 0;
	bool shouldMove = false;
	ThePacmanGame* theGame;
public:
	GhostManager(int _numberOfGhosts, ThePacmanGame* _theGame) : numberOfGhosts(_numberOfGhosts), theGame(_theGame) {
		ghosts = new Ghost[numberOfGhosts];
	}
	~GhostManager() { delete[]ghosts; }
	void setGame(ThePacmanGame* _theGame) {
		theGame = _theGame;
	}
	void addGhost(int y, int x);
	void MoveGhosts();
	bool isGhostEatPacman(const Point& p);
	void reset() {
		currentGhosts = 0;
	}
	void resetPosition() {
		for (int i = 0; i < currentGhosts; i++) {
			ghosts[i].reset();
		}
	}
};

#endif