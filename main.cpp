#include <iostream>
#include "interface.hpp"

int main() {
	Interface in;
	in.run();
	in.cleanup();
	std::cout << "Bye (:" << std::endl;
	return 0;
}
