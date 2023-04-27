#include "Pacman.h"
#include "ThePacmanGame.h"
void Pacman::setPosition(int y, int x)
{
	//for (int i = 0; i < SIZE; i++)
		body.set(x, y);
}
void Pacman::move()
{
	if (direction == 4)
		return;
		body.draw(' ');
		//for (int i = SIZE - 1; i > 0; --i)
			//body[i] = body[i - 1];

		if (theGame->isWall(body.next(direction)))
			direction = 4;

		body.move(direction);
		setTextColor(color);
		body.draw('@');
}
int Pacman::getDirection(char key)
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		if (key == arrowKeys[i])
			return i;
	}
	return -1;
}