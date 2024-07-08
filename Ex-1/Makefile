CFLAGS = -Wall -Werror -Wextra
CC = gcc
FILES_ONE = ex-1_1.c functions.c
FILES_TWO = ex-1_2.c functions.c
FILES_THREE = ex-1_3.c functions.c
FILES_FOUR = ex-1_4.c functions.c

all: ex_one ex_two ex_three ex_four
ex_one: clean
	$(CC) $(CFLAGS) $(FILES_ONE) -o ex_one

ex_two: clean
	$(CC) $(CFLAGS) $(FILES_TWO) -o ex_two

ex_three: clean
	$(CC) $(CFLAGS) $(FILES_THREE) -o ex_three

ex_four: clean
	$(CC) $(CFLAGS) $(FILES_FOUR) -o ex_four

.PHONY: style_check style_go clean

style_check:
	clang-format -n --style=google *.c *.h

style_go:
	clang-format -i --style=google *.c *.h

clean:
	rm -rf *.out
	rm -rf *.gch
	rm -rf ex_one
	rm -rf ex_two
	rm -rf ex_three
	rm -rf ex_four