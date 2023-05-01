#include "Ghost.h"
#include "ThePacmanGame.h"

void Ghost::setPosition(int y, int x)
{
	body.set(x, y);
	if (!isInited) {
		initPosition.set(x, y);
	}
}

void Ghost::move()
{
	char charInPosition;

	if (ShouldChangeDirection()) {
		direction = rand() % 4;
	}
	if (theGame->isWall(body.next(direction)))
		direction = STAY;

	if (direction == STAY) {
		body.draw(GHOST_CHAR, color);
		return;
	}

	charInPosition = theGame->getCharAtPosition(body);
	body.draw(charInPosition);
	body.move(direction);
	body.draw(GHOST_CHAR, color);
}

bool Ghost::ShouldChangeDirection() {
	int randNum = rand() % CHANGE_DIRECTION;
	return randNum == 1; // every 1 out of CHANGE_DIRECTION the ghost will change direction
}

void Ghost::reset() {
	direction = STAY;
	body.set(initPosition.getX(), initPosition.getY());
	body.draw(GHOST_CHAR, color);
}