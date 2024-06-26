CFLAGS = -Wall -Werror -Wextra
CC = gcc
FILES_ONE = ex-3_1.c ../Ex-1/functions.c
FILES_TWO = ex-3_2.c
FILES_THREE = ex-3_3.c
FILES_FOUR = ex-3_4.c

ex_one: clean
	$(CC) $(CFLAGS) $(FILES_ONE) -o ex_one
	./ex_one

ex_two: clean
	$(CC) $(CFLAGS) $(FILES_TWO) -o ex_two
	./ex_two

ex_three: clean
	$(CC) $(CFLAGS) $(FILES_THREE) -o ex_three
	./ex_three

ex_four: clean
	$(CC) $(CFLAGS) $(FILES_FOUR) -o ex_four
	./ex_four

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