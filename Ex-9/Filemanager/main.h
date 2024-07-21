#ifndef MAIN_H
#define MAIN_H

#include <dirent.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <unistd.h>

#define WIN_INIT()         \
  {                        \
    initscr();             \
    noecho();              \
    curs_set(0);           \
    keypad(stdscr, TRUE);  \
    start_color();         \
    cbreak();              \
    nodelay(stdscr, TRUE); \
  }

#define PATH_MAX 4096

typedef struct {
  char **items;
  int count;
  int selected;
  int top;
  char path[PATH_MAX];
} Directory;

void start_program();

void print_mem(WINDOW *left_win, WINDOW *right_win);
void print_name(WINDOW *left_win, WINDOW *right_win);
void print_info(WINDOW *win);

int read_directory(const char *path, Directory *dir);
void display_directory(WINDOW *win, Directory *dir);
void change_directory(Directory *current_dir);
void free_directory(Directory *dir);

int compare(const void *a, const void *b);

#endif