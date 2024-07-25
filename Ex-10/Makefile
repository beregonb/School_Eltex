CFLAGS = -Wall -Werror -Wextra
CC = gcc
FILES_ONE = ex-1.c
FILES_TWO = ex-2.c
FILES_THREE = ex-3.c

all: ex_one ex_two ex_three
ex_one: clean
	$(CC)  $(FILES_ONE) $(CFLAGS) -o ex_one

ex_two: clean
	$(CC)  $(FILES_TWO) $(CFLAGS) -o ex_two

ex_three: clean
	$(CC)  $(FILES_THREE) $(CFLAGS) -o ex_three

.PHONY: style_check style_go clean

style_check:
	clang-format -n --style=google *.c

style_go:
	clang-format -i --style=google *.c

clean:
	rm -rf *.out
	rm -rf *.txt
	rm -rf *.gch
	rm -rf ex_one ex_two ex_three