#include "GhostManager.h"

void GhostManager::addGhost(int y, int x) {
	ghosts[currentGhosts].setPosition(y, x);
	ghosts[currentGhosts].setGame(theGame);
	ghosts[currentGhosts].setColor(COLORS_FOR_GHOSTS[currentGhosts % NUMBER_OF_COLORS]);
	currentGhosts++;
}

void GhostManager::MoveGhosts() {
	if (!shouldMove) { // ghosts move only half pace of pacman
		shouldMove = true;
		return;
	}

	for (int i = 0; i < currentGhosts; i++) { // move all ghosts
		ghosts[i].move();
	}
	shouldMove = false;
}

bool GhostManager::isGhostEatPacman(const Point& p) {
	for (int i = 0; i < currentGhosts; i++) {
		if (ghosts[i].getBody().isEqual(p))
			return true;
	}
	return false;
}