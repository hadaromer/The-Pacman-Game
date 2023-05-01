#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include "io_utils.h"

using namespace std;
enum DIRECTION { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3, STAY = 4 };
extern bool COLORFUL;

class Point {
	int x = 1, y = 1;
	bool canCrossWalls = true;
public:
	Point(bool _canCrossWalls) : canCrossWalls(_canCrossWalls) {}
	Point() {}
	int getX() const {
		return x;
	}
	int getY() const {
		return y;
	}
	void set(int _x, int _y) {
		x = _x;
		y = _y;
	}
	void draw(char ch) {
		gotoxy(x, y);
		cout << ch;
		cout.flush();
	}
	void draw(char s, Color color) {
		setTextColor(color);
		draw(s);
		setTextColor(WHITE);

	}
	void draw(char* s) {
		gotoxy(x, y);
		cout << s;
		cout.flush();
	}
	void draw(char* s, int color) {
		setTextColor(color);
		draw(s);
		setTextColor(WHITE);
	}
	void move();
	void move(int direction);
	Point next(int direction) {
		Point next = *this;
		next.move(direction);
		return next;
	}
	bool isEqual(const Point& p);
};

#endif