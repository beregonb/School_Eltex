CFLAGS = -Wall -Werror -Wextra
CC = gcc
FILES_ONE = ex-1_1.c functions.c
FILES_TWO = ex-1_2.c functions.c
FILES_THREE = ex-1_3.c functions.c
FILES_FOUR = ex-1_4.c functions.c

ex_one:
	$(CC) $(CFLAGS) $(FILES_ONE) -o ex_one
	./ex_one

ex_two:
	$(CC) $(CFLAGS) $(FILES_TWO) -o ex_two
	./ex_two

ex_three:
	$(CC) $(CFLAGS) $(FILES_THREE) -o ex_three
	./ex_three

ex_four:
	$(CC) $(CFLAGS) $(FILES_FOUR) -o ex_four
	./ex_four

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