#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "snake.hpp"
#include "apple.hpp"

class Interface {
	public:
		Interface();
		void run();
		void cleanup();
		void input(), update(), render();
	private:
		int inp;
		bool isRunning = true;
		int height, width;
		Snake *snake;
		Apple *apple;
};


#endif
