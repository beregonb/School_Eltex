CC = gcc
FLAG = -fPIC -c
FLAG_DINAM = -shared -o
FLAG_RUN=LD_LIBRARY_PATH=$$PWD:$$LD_LIBRARY_PATH 

FILE_SUM = sum.c
FILE_SUB = subtraction.c
FILE_DIV = division.c
FILE_MUL = multiplication.c
FILE_OTHER = print_menu.c
FILE_MAIN = main.c $(FILE_OTHER)

all: run

run: libcalc.so calc
	$(FLAG_RUN)./calc

calc: $(FILE_MAIN) libcalc.so
	$(CC) $(FILE_MAIN) -o calc -L. -lcalc

libcalc.so: sum.o subtraction.o multiplication.o division.o
	$(CC) $(FLAG_DINAM) libcalc.so sum.o subtraction.o multiplication.o division.o
	$(MAKE) clean_lib

sum.o: $(FILE_SUM)
	$(CC) $(FLAG) $(FILE_SUM) -o sum.o

subtraction.o: $(FILE_SUB)
	$(CC) $(FLAG) $(FILE_SUB) -o subtraction.o

multiplication.o: $(FILE_MUL)
	$(CC) $(FLAG) $(FILE_MUL) -o multiplication.o

division.o: $(FILE_DIV)
	$(CC) $(FLAG) $(FILE_DIV) -o division.o

clean: clean_lib
	rm -rf libcalc.so calc

clean_lib:
	rm -rf *.o

style_check:
	clang-format -n --style=google *.c *.h

style_go:
	clang-format -i --style=google *.c *.h

.PHONY: all clean clean_lib
