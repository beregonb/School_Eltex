CFLAGS = -Wall -Werror -Wextra
CC = gcc
FILES_ONE = *.c
TEST =  f_memory_struct.c ../test/test.c ../test/test_function.c 

all: ex_one
ex_one: clean
	$(CC) $(CFLAGS) $(FILES_ONE) -o ex_one

fix_ex_one: clean
	$(CC) $(CFLAGS) $(FILES_ONE) -o ex_one -g

.PHONY: style_check style_go clean

test:
	$(CC) $(CFLAGS) $(TEST) -o test -lcheck -lm -lpthread -lrt

style_check:
	clang-format -n --style=google *.c *.h

style_go:
	clang-format -i --style=google *.c *.h

clean:
	rm -rf *.out
	rm -rf *.gch
	rm -rf ex_one