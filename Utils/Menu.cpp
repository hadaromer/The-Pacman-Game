#include "Menu.h"
#include "../Boards/_board.h"
#include "../Boards/Board.h"

ThePacmanGame game;
short CONSOLE_DEFAULT;

void Start() {
	CONSOLE_DEFAULT = GetColor();
	srand(time(NULL)); // set random
	ShowMenu();
}

void ShowMenu() {
	hideCursor();
	
	setTextColor(YELLOW);
	cout << R"(
  __  __ _____  _      ____   _    ____ __  __    _    _   _ 
 |  \/  |_   _|/ \    |  _ \ / \  / ___|  \/  |  / \  | \ | |
 | |\/| | | | / _ \   | |_) / _ \| |   | |\/| | / _ \ |  \| |
 | |  | | | |/ ___ \  |  __/ ___ \ |___| |  | |/ ___ \| |\  |
 |_|  |_| |_/_/   \_\ |_| /_/   \_\____|_|  |_/_/   \_\_| \_|

)" << endl;
	setTextColor(GREEN);
	cout << "(1) Start a new game" << endl;
	if (COLORFUL) {
		setTextColor(WHITE);
		cout << "(2) For Colorless experience :(" << endl;
	}
	else {
		cout << "(2) For ColorFul experience :)" << endl;
	}
	setTextColor(BLUE);
	cout << "(8) Present instructions and keys" << endl;
	setTextColor(RED);
	cout << "(9) EXIT" << endl << endl;
	setTextColor(WHITE);
	GetUserInput();
}

void GetUserInput() {
	int userChoice;
	char key = 0;

	do
	{
		key = _getch();

	} while (key == 0);

	userChoice = (int)key - '0';
	HandleUserChoice(userChoice);
}

void HandleUserChoice(int userChoice) {
	switch (userChoice)
	{
	case START:
		clear_screen();
		game.setBoard(board_example);
		game.init();
		game.run();
		break;
	case COLOR_CHANGE:
		COLORFUL = !COLORFUL;
		if (!COLORFUL) {
			resetColor(CONSOLE_DEFAULT);
		}
		clear_screen();
		ShowMenu();
		break;
	case INSTRUCTIONS:
		PrintInstructions();
		break;
	case EXIT:
		exit(1);
	default:
		cout << "Wrong Input." << endl;
		GetUserInput();
	}
}

void PrintInstructions() {
	clear_screen();
	cout << R"(
Instructions Pacman

##Goal##
Guide Pacman around the maze and eat all the little white dots whilst avoiding those nasty ghosts.

##Controls##
LEFT  | a or A
RIGHT | d or D
UP    | w or W
Down  | x or X
STAY  | s or S

ESC: Pause/unpause game

Press any key to return to menu.
)" << endl;
	WaitForKey(ANY, ShowMenu);
}

void ShowGameOver() {
	clear_screen();
	cout << R"(

   _____              __  __   ______ 
  / ____|     /\     |  \/  | |  ____|
 | |  __     /  \    | \  / | | |__   
 | | |_ |   / /\ \   | |\/| | |  __|  
 | |__| |  / ____ \  | |  | | | |____ 
  \_____| /_/    \_\ |_|  |_| |______|
                                      
                                      
   ____   __      __  ______   _____  
  / __ \  \ \    / / |  ____| |  __ \ 
 | |  | |  \ \  / /  | |__    | |__) |
 | |  | |   \ \/ /   |  __|   |  _  / 
 | |__| |    \  /    | |____  | | \ \ 
  \____/      \/     |______| |_|  \_\
                                      
                                      
)" << "Press any key to return to menu." << endl;

	WaitForKey(ANY, ShowMenu);
}

void ShowGameWin() {
	clear_screen();
	cout << R"(

 __      __  _____    _____   _______    ____    _____   __     __
 \ \    / / |_   _|  / ____| |__   __|  / __ \  |  __ \  \ \   / /
  \ \  / /    | |   | |         | |    | |  | | | |__) |  \ \_/ / 
   \ \/ /     | |   | |         | |    | |  | | |  _  /    \   /  
    \  /     _| |_  | |____     | |    | |__| | | | \ \     | |   
     \/     |_____|  \_____|    |_|     \____/  |_|  \_\    |_|   
                                      
                                      
)" << "Press any key to return to menu." << endl;

	WaitForKey(ANY, ShowMenu);
}

void ShowGamePaused() {
	clear_screen();
	cout << R"(


   _____                                                                         _ 
  / ____|                                                                       | |
 | |  __    __ _   _ __ ___     ___     _ __     __ _   _   _   ___    ___    __| |
 | | |_ |  / _` | | '_ ` _ \   / _ \   | '_ \   / _` | | | | | / __|  / _ \  / _` |
 | |__| | | (_| | | | | | | | |  __/   | |_) | | (_| | | |_| | \__ \ |  __/ | (_| |
  \_____|  \__,_| |_| |_| |_|  \___|   | .__/   \__,_|  \__,_| |___/  \___|  \__,_|
                                       | |                                         
                                       |_|                                         
                                      
)" << "press ESC again to continue" << endl;

	WaitForKey(ESC);
}
/*
the function will wait either for esc or any key
if the function gets a void func it will call it later
*/
void WaitForKey(WaitingKeysOptions option, void(*func)()) {
	char key = 0;
	do
	{
		key = _getch();

	} while ((option == ESC && key != ESC) || (option == ANY && key == 0));
	clear_screen();
	if (func != NULL)
		func();
}
