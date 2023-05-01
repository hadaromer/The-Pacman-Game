#include "ThePacmanGame.h"

void ThePacmanGame::handleObjectCreationFromBoard(int row, int col)
{
	char ch = originalBoard[row][col];
	if (ch == PACMAN_CHAR)
		pacman.setPosition(row, col);
	if (ch == GHOST_CHAR)
		ghostManager.addGhost(row, col);
	if (ch == POINTS_POSITION)
		legendManager.setPointsPos(row, col);
	if (ch == LIFE_POSITION)
		legendManager.setLivesPos(row, col);
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
	gameState = RUN;
	points = 0;
	life = 3;
	remainingBreadcrumbs = 0;
	pacman.setGame(this);
	pacman.setArrowKeys(ARROW_KEYS);
	ghostManager.setGame(this);
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			gotoxy(j, i);
			if (originalBoard[i][j] == BLANK && i < END_BOARD_ROWS) { // breadcrumb location
				board[i][j] = BREADCRUMB_SYMBOL;
				remainingBreadcrumbs++;
			}
			else if (originalBoard[i][j] == WALL_CHAR) {
				board[i][j] = originalBoard[i][j];
			}
			else if (i == END_BOARD_ROWS) {
				board[i][j] = originalBoard[i][j];
			}
			else {
				board[i][j] = BLANK;
			}
			handleObjectCreationFromBoard(i, j);
		}
		board[i][COLS] = '\0';
	}
	PrintBoard(true);
	legendManager.PrintLife(life);
	legendManager.PrintPoints(points);
}

void ThePacmanGame::PauseGame()
{
	ShowGamePaused();
	PrintBoard(false);
}

void ThePacmanGame::UpdateBoardBreadcrumbs() {
	Point p = pacman.getBody();
	if (isPoint(p)) {
		points++;
		remainingBreadcrumbs--;
		board[p.getY()][p.getX()] = BLANK;
	}
}

bool ThePacmanGame::isWall(const Point& p) {
	return board[p.getY()][p.getX()] == WALL_CHAR;
}

bool ThePacmanGame::isPoint(const Point& p) {
	return board[p.getY()][p.getX()] == BREADCRUMB_SYMBOL;
}

char ThePacmanGame::getCharAtPosition(const Point& p) {
	if (isPoint(p)) {
		return BREADCRUMB_SYMBOL;
	}
	return BLANK;
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
			if ((dir = pacman.getDirection(key)) != -1)
				pacman.setDirection(dir);
			if (key == ESC)
				PauseGame();
		}

		pacman.move();
		if (ghostManager.isGhostEatPacman(pacman.getBody())) {
			LoseLife();
			Sleep(1000);
			if (life == 0) { // no more life, pacman loses :(
				gameState = LOSE;
			}
		}
		ghostManager.MoveGhosts();
		legendManager.PrintPoints(points);
		UpdateBoardBreadcrumbs();

		if (remainingBreadcrumbs == 0) { // pacman wins :)
			gameState = WIN;
		}

		Sleep(100);
	} while (gameState == RUN);
	HandleGameEnded();
}

void ThePacmanGame::LoseLife() {
	life--;
	PrintBoard(true);
	legendManager.BlinkLives(life);
}

void ThePacmanGame::PrintBoard(bool resetPlaces) { // resetPlaces for reset creatures (e.g: pacman died)
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			gotoxy(j, i);
			if (board[i][j] == WALL_CHAR && COLORFUL)
				setTextColor(BLUE);
			cout << board[i][j];
			cout.flush();
			if (board[i][j] == WALL_CHAR && COLORFUL)
				setTextColor(WHITE);
		}
	}
	if (resetPlaces) {
		pacman.resetPosition();
		ghostManager.resetPosition();
	}
	legendManager.PrintLife(life);
	legendManager.PrintPoints(points);
}

void ThePacmanGame::HandleGameEnded() {
	pacman.reset();
	ghostManager.reset();
	switch (gameState)
	{
	case LOSE:
		ShowGameOver();
		break;
	case WIN:
		ShowGameWin();
		break;
	}
}