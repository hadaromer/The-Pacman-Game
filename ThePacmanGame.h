#ifndef _THESNAKESGAME_H_
#define _THESNAKESGAME_H_

#include "Utils/io_utils.h"
#include "Creatures/Pacman.h"
#include "Creatures/GhostManager.h"
#include "Utils/LegendManager.h"
#include "Utils/Menu.h"

enum { ROWS = 25, COLS = 80, END_BOARD_ROWS = 24};
const char ARROW_KEYS[] = "wxads";
const int BREADCRUMB_SYMBOL = 4;
const char WALL_CHAR = '#';
const char BLANK = ' ';

enum GameState {RUN,LOSE,WIN};
class ThePacmanGame {
	enum { ESC = 27 };
	Pacman pacman;
	GhostManager ghostManager = {2,this};
	LegendManager legendManager;
	int remainingBreadcrumbs;
	int points;
	int life;
	GameState gameState;
	char originalBoard[ROWS][COLS + 1];	// this is the original board that we got (we need COLS+1 because we handle it as null terminated char*)
	char board[ROWS][COLS + 1];	// this is the actual board we play on, i.e. changes on board are done here
	void handleObjectCreationFromBoard(int row, int col); 
	void LoseLife();
	bool isPoint(const Point& p);
	void UpdateBoardBreadcrumbs(); // update the board 
	void PrintBoard(bool resetPlaces); // print current board
	void HandleGameEnded();
public:
	void setBoard(const char* boardToCopy[ROWS]); //copy board sent to us into originalBoard, setArrowKeys, setColor
	void init(); //copy original board to actual board and set Snakes Start point
	void PauseGame(); 
	bool isWall(const Point& p);
	char getCharAtPosition(const Point& p);
	void run(); // run the game

};

#endif