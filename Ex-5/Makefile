CFLAGS = -fno-stack-protector -no-pie -g
CC = gcc
FILES_ONE = ex-5.c

all: ex_one
ex_one: clean input
	$(CC) $(CFLAGS) $(FILES_ONE) -o ex_one
	./ex_one < input.txt

input:
	$(CC) file.c -o file
	./file
.PHONY: style_check style_go clean

style_check:
	clang-format -n --style=google *.c

style_go:
	clang-format -i --style=google *.c

clean:
	rm -rf *.out
	rm -rf *.gch
	rm -rf ex_one
	rm -rf file
	rm -rf input.txt