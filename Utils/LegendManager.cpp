#include "LegendManager.h"

void LegendManager::PrintLife(int current) {
	for (int i = 0; i < 3; i++) {
		if (i < current) {
			life[i * 2] = 3;
			life[i * 2 + 1] = ' ';
		}
		else {
			life[i * 2] = ' ';
			life[i * 2 + 1] = ' ';
		}
	}
	livesPos.draw(life, RED);
}

void LegendManager::BlinkLives(int current) { // will make animation of blinking heart when pacman is dead
	for (int i = 0; i < 5; i++) {
		PrintLife(current + 1);
		Sleep(200);
		PrintLife(current);
		Sleep(200);
	}
}

void LegendManager::PrintPoints(int currentPoints) {
	sprintf_s(points, "%d", currentPoints);
	pointsPos.draw(points, rand() % 15); // random color
}