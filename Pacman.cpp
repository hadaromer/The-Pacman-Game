#include "Pacman.h"
#include "ThePacmanGame.h"
void Pacman::setPosition(int y, int x)
{
	body.set(x, y);
	if (!isInited) {
		initPosition.set(x, y);
	}
}

void Pacman::setArrowKeys(const char* keys) {
	arrowKeys[0] = keys[0]; // up
	arrowKeys[1] = keys[1]; // down
	arrowKeys[2] = keys[2]; // left
	arrowKeys[3] = keys[3]; // right 
	arrowKeys[4] = keys[4]; // stay
}

void Pacman::move()
{
	if (direction == STAY) {
		body.draw(PACMAN_CHAR, color);
		return;
	}

	body.draw(' ');

	if (theGame->isWall(body.next(direction)))
		direction = 4;

	body.move(direction);
	body.draw(PACMAN_CHAR, color);
}
int Pacman::getDirection(char key)
{
	if (key < 'a') key += 32; // upper to lower 
	for (int i = 0; i < POSSIBLE_DIRECTIONS_NUMBER; i++)
	{
		if (key == arrowKeys[i])
			return i;
	}
	return -1;
}

void Pacman::resetPosition() {
	direction = STAY;
	body.set(initPosition.getX(), initPosition.getY());
	body.draw(PACMAN_CHAR, color);
}