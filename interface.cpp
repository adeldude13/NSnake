#include <iostream>
#include <ncurses.h>

#include "apple.hpp"
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
	notimeout(stdscr, TRUE);
	snake = new Snake(width/2, height/2, width, height);
	apple = new Apple;
}

void Interface::cleanup() {
	endwin();
}

void Interface::run() {
	apple->respawn(width, height);
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
	if(snake->nodes[0].x == apple->x && snake->nodes[0].y == apple->y) {
		apple->respawn(width, height);
		snake->addNode();
	}
	snake->update();
}

void Interface::render() {
	clear();
	char v = 'H';
	for(int i=0; i<(int)snake->nodes.size();i++) {
		move(snake->nodes[i].y, snake->nodes[i].x);
		addch(v);
		v = 'N';
	}
	move(apple->y, apple->x);
	addch('A');
}
