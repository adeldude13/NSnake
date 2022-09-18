#include "apple.hpp"
#include <random>
#include <time.h>

Apple::Apple() {
	srand(time(NULL));
}

void Apple::respawn(int width, int height) {
	x = rand() % width;
	y = rand() % height;
}
