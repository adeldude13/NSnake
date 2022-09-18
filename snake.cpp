#include "snake.hpp"

Snake::Snake(int px, int py, int maxwidth, int maxheight) : nodes(1) {
	nodes[0].x = px;
	nodes[0].y = py;
	height = maxheight;
	width = maxwidth;
}

void Snake::update() {
	int *ux = &(nodes[0].x);
	int *uy = &(nodes[0].y);
	int tempx = *ux, tempy = *uy;
	for(int i=1; i<(int)nodes.size();i++) {
		int ftempx = nodes[i].x, ftempy = nodes[i].y;
		nodes[i].x = tempx;
		nodes[i].y = tempy;
		tempx = ftempx;
		tempy = ftempy;
	}
	switch(direction) {
		case RIGHT:
			*ux = *ux + 1;
			break;
		case LEFT:
			*ux = *ux - 1;
			break;
		case UP:
			*uy = *uy - 1;
			break;
		case DOWN:
			*uy = *uy + 1;
			break;
	}
}

void Snake::addNode() {
	Node v = nodes[nodes.size()-1];
	switch(direction) {
		case RIGHT:
			v.x--;
			break;
		case LEFT:
			v.x++;
			break;
		case UP:
			v.y--;
			break;
		case DOWN:
			v.y++;
			break;
	}
	nodes.push_back(v);
}

void Snake::setDir(Direction nd) {
	direction = nd;
}
