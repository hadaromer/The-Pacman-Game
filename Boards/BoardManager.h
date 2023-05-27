#ifndef _BOARD_MANAGER_H_
#define _BOARD_MANAGER_H_

#include "Board.h"

class BoardManager {
	int numberOfBoards = 0;
	Board* boards;
public:
	BoardManager(){
		// read how many boards file you have 
		// numberOfBoards++ for each file
		// allocate memoery for boards: boards = Board[numberOfBoards];
		// for each board get its values
		// sort the boards alphabetic - mergesort quicksort 
	}
	~BoardManager() { delete[]boards; }
	// getBoardByName 
	// getBoards
	// getBoardById
};


#endif