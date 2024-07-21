CFLAGS = -lncurses
CC = gcc
FILES_ONE = main.c

all: ex_one 
ex_one: clean
	$(CC)  $(FILES_ONE) $(CFLAGS) -o file_manager

.PHONY: style_check style_go clean

style_check:
	clang-format -n --style=google *.c

style_go:
	clang-format -i --style=google *.c

clean:
	rm -rf *.out
	rm -rf *.txt
	rm -rf *.gch
	rm -rf file_manager