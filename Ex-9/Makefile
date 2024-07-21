CFLAGS = -Wall -Werror -Wextra
CC = gcc
FILES_ONE = ex-9_1.c 

all: ex_one 
ex_one: clean
	$(CC) $(CFLAGS) $(FILES_ONE) -o ex_one

ex_two: clean
	$(CC) $(CFLAGS) $(FILES_TWO) -o ex_two

.PHONY: style_check style_go clean

style_check:
	clang-format -n --style=google *.c

style_go:
	clang-format -i --style=google *.c

clean:
	rm -rf *.out
	rm -rf *.txt
	rm -rf *.gch
	rm -rf ex_one