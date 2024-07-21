#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <sys/statvfs.h>
#include <sys/stat.h>
#include <time.h>


#define WIN_INIT()                                                             \
  {                                                                            \
    initscr();                                                                 \
    noecho();                                                                  \
    curs_set(0);                                                               \
    keypad(stdscr, TRUE);                                                      \
    start_color();                                                             \
    cbreak();                                                                  \
    nodelay(stdscr, TRUE);                                                     \
  }

void start_program();
void print_mem(WINDOW *left_win, WINDOW *right_win);
void print_name(WINDOW *left_win, WINDOW *right_win);
void print_dir(char *path, WINDOW *window_dir, int target);
int count_files(char *path);
void move_up_directory(char *dir);
void open_d(char *start_dir_left, int target_left);

#endif