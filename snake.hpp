#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>

typedef enum {
	LEFT,
	RIGHT, 
	UP,
	DOWN
} Direction;

typedef struct node Node;

struct node {
	public:
		int x, y;
};

class Snake {
	public:
		Snake(int , int , int , int);
		void update(), addNode();
		void setDir(Direction);
		std::vector<Node> nodes;
	private:
		int height, width;
		Direction direction = RIGHT;
};

#endif
