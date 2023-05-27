#ifndef _GHOST_H_
#define _GHOST_H_

#include <cstring>
#include "../Utils/Point.h"

class ThePacmanGame;

const char GHOST_CHAR = '$';
const int CHANGE_DIRECTION = 5;

class Ghost {
	Point body = false;
	Point initPosition;
	bool isInited = false;
	int direction = 4;
	Color color;
	ThePacmanGame* theGame;
	bool ShouldChangeDirection();
public:
	void setGame(ThePacmanGame* _theGame) {
		theGame = _theGame;
	}
	void setPosition(int y, int x);
	Point getBody() {
		return body;
	}
	void setColor(Color c) {
		color = c;
	}
	void move();
	void setDirection(int dir) {
		direction = dir;
	}
	void reset();
};

#endif