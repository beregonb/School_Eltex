CC = gcc

FILE_SUM = sum.c
FILE_SUB = subtraction.c
FILE_DIV = division.c
FILE_MUL = multiplication.c
FILE_OTHER = print_menu.c
FILE_MAIN = main.c $(FILE_OTHER)

all: libcalc.a calc

calc:
	$(CC) $(FILE_MAIN) -o calc -L. -lcalc

libcalc.a: sum.o subtraction.o multiplication.o division.o
	ar rc libcalc.a sum.o subtraction.o multiplication.o division.o
	$(MAKE) clean_lib

sum.o: $(FILE_SUM)
	$(CC) -c $(FILE_SUM)

sub.o: $(FILE_SUB)
	$(CC) -c $(FILE_SUB)

mul.o: $(FILE_MUL)
	$(CC) -c $(FILE_MUL)

div.o: $(FILE_DIV)
	$(CC) -c $(FILE_DIV)

clean: clean_lib
	rm -rf libcalc.a
	rm -rf calc

clean_lib:
	rm -rf *.o

style_check:
	clang-format -n --style=google *.c

style_go:
	clang-format -i --style=google *.c

.PHONY: all clean clean_lib
