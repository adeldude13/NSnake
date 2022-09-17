#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "snake.hpp"

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
};


#endif
