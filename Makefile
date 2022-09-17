CC := clang++
CFILES := main.cpp interface.cpp snake.cpp
HFILES := interface.hpp snake.hpp
FILES := $(CFILES) $(HFILES) Makefile
OUT := main
LIBS := `pkg-config --cflags --libs ncurses`
ARGS := $(LIBS) -O0 -ggdb3 -Wall -Wextra -o $(OUT)

main: $(FILES)
	$(CC) $(ARGS) $(CFILES)

clean:
	rm $(OUT)
