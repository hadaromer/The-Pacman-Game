#ifndef _THESNAKESGAME_H_
#define _THESNAKESGAME_H_

#include "io_utils.h"
#include "Pacman.h"

enum { ROWS = 25, COLS = 80 };
enum { GHOST, WALL, NORMAL };
class ThePacmanGame {
	enum { ESC = 27 };
	Pacman s;
	char originalBoard[ROWS][COLS + 1];	// this is the original board that we got (we need COLS+1 because we handle it as null terminated char*)
	char board[ROWS][COLS + 1];	// this is the actual board we play on, i.e. changes on board are done here
	void handleObjectCreationFromBoard(int row, int col); // '@' , '#' are the start points of the Snakes
public:
	void setBoard(const char* boardToCopy[ROWS]); //copy board sent to us into originalBoard, setArrowKeys, setColor
	void init(); //copy original board to actual board and set Snakes Start point
	int UpdateBoard(const Point& p); // update the board 
	bool isWall(const Point& p);
	bool isGhost(const Point& p);
	bool isPoint(const Point& p);
	void run(); // run 2 Snakes with Keyboard
};

#endif