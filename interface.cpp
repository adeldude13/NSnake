#include <iostream>
#include <ncurses.h>

#include "interface.hpp"
#include "snake.hpp"

Interface::Interface() {
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	halfdelay(1);
	getmaxyx(stdscr, height, width);
	snake = new Snake(10, 10, width, height);
}

void Interface::cleanup() {
	endwin();
}

void Interface::run() {
	while(isRunning) {
		input();
		update();
		render();
	}
}

void Interface::input() {
	inp = getch();
}

void Interface::update() {
	switch(inp) {
		case 'w':
			snake->setDir(UP);
			break;
		case 'a':
			snake->setDir(LEFT);
			break;
		case 's':
			snake->setDir(DOWN);
			break;
		case 'd':
			snake->setDir(RIGHT);
			break;
		case 'q':
			isRunning = false;
			break;
	}
	snake->update();
}

void Interface::render() {
	clear();
	char v = 'H';
	for(int i=0; i<(int)snake->nodes.size();i++) {
		move(snake->nodes[i].y, snake->nodes[i].x);
		addch(v);
		v = 'A';
	}
}
