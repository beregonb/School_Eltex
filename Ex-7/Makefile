CC = gcc
FLAG= -c
FLAG_STATIC= ar rc

FILE_SUM = sum.c
FILE_SUB = subtraction.c
FILE_DIV = division.c
FILE_MUL = multiplication.c
FILE_OTHER = print_menu.c
FILE_MAIN = main.c $(FILE_OTHER)

all: libcalc.a calc
	./calc

calc:
	$(CC) $(FILE_MAIN) -o calc -L. -lcalc

libcalc.a: sum.o subtraction.o multiplication.o division.o
	$(FLAG_STATIC) libcalc.a sum.o subtraction.o multiplication.o division.o
	$(MAKE) clean_lib

sum.o: $(FILE_SUM)
	$(CC) $(FLAG) $(FILE_SUM)

subtraction.o: $(FILE_SUB)
	$(CC) $(FLAG) $(FILE_SUB)

multiplication.o: $(FILE_MUL)
	$(CC) $(FLAG) $(FILE_MUL)

division.o: $(FILE_DIV)
	$(CC) $(FLAG) $(FILE_DIV)

clean: clean_lib
	rm -rf libcalc.a
	rm -rf calc

clean_lib:
	rm -rf *.o

style_check:
	clang-format -n --style=google *.c *.h

style_go:
	clang-format -i --style=google *.c *.h

.PHONY: all clean clean_lib
