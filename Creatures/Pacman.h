#ifndef _PACMAN_H_
#define _PACMAN_H_

#include <cstring>
#include "../Utils/Point.h"

class ThePacmanGame;

const char PACMAN_CHAR = '@';
const int POSSIBLE_DIRECTIONS_NUMBER = 5;

class Pacman {
	Point body;
	Point initPosition;
	bool isInited=false;
	int direction = 4; 
	char arrowKeys[5];
	Color color = GREEN;
	ThePacmanGame* theGame;
public:
	void setGame(ThePacmanGame* _theGame) {
		theGame = _theGame;
	}
	void setPosition(int y, int x);
	Point getBody() {
		return body;
	}
	void setArrowKeys(const char* keys);
	void setColor(Color c) {
		color = c;
	}
	void move();
	int getDirection(char key);
	void setDirection(int dir) {
		direction = dir;
	}
	void reset() {
		isInited = false;
	}
	void resetPosition();
};

#endif