#include "ThePacmanGame.h"

void ThePacmanGame::handleObjectCreationFromBoard(int row, int col)
{
	char ch = board[row][col];
	if (ch == '@')
		s.setPosition(row, col);
	//if (ch == '#')
		//s[1].setPosition(row, col);
}
void ThePacmanGame::setBoard(const char* boardToCopy[ROWS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			originalBoard[i][j] = boardToCopy[i][j];
		}
		originalBoard[i][COLS] = '\0';
	}
}
void ThePacmanGame::init()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			gotoxy(j, i);
			if (originalBoard[i][j] == ' ') { // breadcrumb location
				board[i][j] = '-';
			}
			else {
				board[i][j] = originalBoard[i][j];
			}
			cout << board[i][j];
			cout.flush();
			handleObjectCreationFromBoard(i, j);
		}
		board[i][COLS] = '\0';
	}

	s.setGame(this);
	//s[1].setGame(this);
	s.setColor(YELLOW);
	//s[1].setColor(LIGHTBLUE);
	s.setArrowKeys("wsad");
	//s[1].setArrowKeys("8246");
}

int ThePacmanGame::UpdateBoard(const Point& p) {
	if (isWall(p)) {
		return WALL;
	}
	if (isGhost(p)) {
		return GHOST;
	}
	return NORMAL;
}

bool ThePacmanGame::isWall(const Point& p) {
	return board[p.getY()][p.getX()] == '+';
}

bool ThePacmanGame::isGhost(const Point& p) {
	return board[p.getY()][p.getX()] == '$';
}

bool ThePacmanGame::isPoint(const Point& p) {
	return board[p.getY()][p.getX()] == '-';
}

void ThePacmanGame::run()
{
	char key = 0;
	int dir;
	do
	{
		if (_kbhit())
		{
			key = _getch();
			if ((dir = s.getDirection(key)) != -1)
				s.setDirection(dir);
			//else if ((dir = s[1].getDirection(key)) != -1)
				//s[1].setDirection(dir);
		}
		s.move();
		//s[1].move();
		Sleep(100);
	} while (key != ESC);
}