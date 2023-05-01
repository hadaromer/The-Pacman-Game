#include "Point.h"

void Point::move() {
	int dir = rand() % 4; 
	move(dir);
}

void Point::move(int dir) {
	switch (dir) {
	case UP:
		--y;
		if (y < 0) {
			if (canCrossWalls)
				y = 23;
			else
				y = 0;
		}
		break;
	case DOWN: 
		++y;
		if (y > 23) {
			if (canCrossWalls)
				y = 0;
			else
				y = 23;
		}
		break;
	case LEFT:
		--x;
		if (x < 0) {
			if (canCrossWalls)
				x = 79;
			else
				x = 0;
		}
		break;
	case RIGHT: 
		++x;
		if (x > 79) {
			if (canCrossWalls)
				x = 0;
			else
				x = 79;
		}
		break;
	}
}

bool Point::isEqual(const Point& p) {
	return y == p.getY() && x == p.getX();
}