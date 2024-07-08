CFLAGS = -Wall -Werror -Wextra
CC = gcc
FILES_ONE = ex-2_1.c
FILES_TWO = ex-2_2.c
FILES_THREE = ex-2_3.c
FILES_FOUR = ex-2_4.c

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
	clang-format -n --style=google *.c

style_go:
	clang-format -i --style=google *.c

clean:
	rm -rf *.out
	rm -rf *.gch
	rm -rf ex_one
	rm -rf ex_two
	rm -rf ex_three
	rm -rf ex_four