#ifndef _MENU_H_
#define _MENU_H_

#include "io_utils.h"
#include "ThePacmanGame.h"

using namespace std;

enum MenuOption {START=1, COLORCHANGE =2,INSTRUCTIONS=8,EXIT=9};
enum WaitingKeysOptions{ESC=27,ANY=0};
void Start();
void ShowMenu();
void GetUserInput();
void HandleUserChoice(int userChoice);
void PrintInstructions();
void ShowGameOver();
void ShowGameWin();
void ShowGamePaused();
void WaitForKey(WaitingKeysOptions option, void(*func)() = NULL);
#endif