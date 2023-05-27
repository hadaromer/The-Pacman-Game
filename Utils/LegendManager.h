#ifndef _LEGEND_MANAGER_H_
#define _LEGEND_MANAGER_H_

#include <cstring>
#include "Point.h"

const int HEART_SYMBOL = 3;
const char POINTS_POSITION = 'P';
const char LIFE_POSITION = 'H';

class LegendManager {
	Point pointsPos;
	Point livesPos;
	char life[7] = { HEART_SYMBOL,' ',HEART_SYMBOL,' ',HEART_SYMBOL,' ','\0' }; // for life view
	char points[6]; // for points view
public:
	void setPointsPos(int y, int x) {
		pointsPos.set(x, y);
	}
	void setLivesPos(int y, int x) {
		livesPos.set(x, y);
	}
	void PrintLife(int curretLife);
	void BlinkLives(int currentLife);
	void PrintPoints(int currentPoints);
};

#endif