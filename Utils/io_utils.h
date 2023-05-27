#ifndef _IO_UTILS_H_
#define _IO_UTILS_H_

#include "Color.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y);
void setTextColor(Color);
void setTextColor(int);
short GetColor();
void resetColor(short shortColorToSet);
void hideCursor();
void clear_screen();

#endif