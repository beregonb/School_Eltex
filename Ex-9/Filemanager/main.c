#include "main.h"

int main() {
  WIN_INIT();
  start_program();
  endwin();
  return 0;
}
/**
 * @brief Функция старта программы. Создаются 3 окна: левое окно, правое окно и
 * информационное окно. Инициализируются цвета и задаются параметры окон. Так же
 * инициализируются структуры Directory для левого и правого окон.
 *
 */
void start_program() {
  int height, width, info_height = 3;
  getmaxyx(stdscr, height, width);

  WINDOW *left_win = newwin(height - info_height, width / 2, 0, 0);
  WINDOW *right_win = newwin(height - info_height, width / 2, 0, width / 2);
  WINDOW *info_win = newwin(info_height, width, height - info_height, 0);

  init_pair(2, COLOR_WHITE, COLOR_BLUE);
  init_pair(3, COLOR_WHITE, COLOR_BLACK);
  init_pair(4, COLOR_RED, COLOR_BLACK);

  wattron(left_win, COLOR_PAIR(3));
  wattron(right_win, COLOR_PAIR(3));
  wattron(info_win, COLOR_PAIR(2));

  box(left_win, 0, 0);
  box(right_win, 0, 0);
  box(info_win, 0, 0);

  wrefresh(left_win);
  wrefresh(right_win);
  wrefresh(info_win);

  Directory left_dir = {0}, right_dir = {0};

  strcpy(left_dir.path, ".");
  strcpy(right_dir.path, ".");

  read_directory(left_dir.path, &left_dir);
  read_directory(right_dir.path, &right_dir);

  left_dir.top = 0;
  right_dir.top = 0;

  WINDOW *current_win = left_win;
  Directory *current_dir = &left_dir;

  while (1) {
    int ch = getch();

    switch (ch) {
      case 'q':
      case 'Q':
        free_directory(&left_dir);
        free_directory(&right_dir);
        return;
      case '\t':
        if (current_win == left_win) {
          current_win = right_win;
          current_dir = &right_dir;
        } else {
          current_win = left_win;
          current_dir = &left_dir;
        }
        break;
      case KEY_UP:
        if (current_dir->selected > 0) {
          current_dir->selected--;
          if (current_dir->selected < current_dir->top) {
            current_dir->top = current_dir->selected;
          }
        }
        break;
      case KEY_DOWN:
        if (current_dir->selected < current_dir->count - 1) {
          current_dir->selected++;
          if (current_dir->selected >=
              current_dir->top + getmaxy(current_win) - 3) {
            current_dir->top =
                current_dir->selected - (getmaxy(current_win) - 3) + 1;
          }
        }
        break;
      case '\n': {
        change_directory(current_dir);
        break;
      }
    }

    display_directory(left_win, &left_dir);
    display_directory(right_win, &right_dir);
    print_mem(left_win, right_win);
    print_name(left_win, right_win);
    print_info(info_win);

    wrefresh(info_win);
    napms(50);
  }
}
/**
 * @brief Функция для выбора дирректории. Если выбран ".." - то переход в
 * родительскую дирректорию. Если выбрана дирректория - то переход в эту
 * дирректорию. Так же происходит проверка является ли дирректория дирректорией.
 * И обновляются значнения top и selected
 *
 * @param current_dir Структура Directory
 */
void change_directory(Directory *current_dir) {
  char new_path[PATH_MAX];

  if (strcmp(current_dir->items[current_dir->selected], "..") == 0) {
    snprintf(new_path, sizeof(new_path), "%s/..", current_dir->path);
  } else {
    snprintf(new_path, sizeof(new_path), "%s/%s", current_dir->path,
             current_dir->items[current_dir->selected]);
  }

  struct stat st;
  if (stat(new_path, &st) == 0 && S_ISDIR(st.st_mode)) {
    strncpy(current_dir->path, new_path, PATH_MAX);
    read_directory(current_dir->path, current_dir);
    current_dir->top = 0;
    current_dir->selected = 0;
  }
}

/**
 * @brief Функция read_directory предназначена для считывания содержимого
 * директорий и сохранения его в структуре Directory с началом ".." и
 * отсортированным по имени элементами.
 *
 * @param path начало пути
 * @param dir структура Directory
 * @return -1 если произошла ошибка, 0 в противном случае.
 */
int read_directory(const char *path, Directory *dir) {
  DIR *dp;
  struct dirent *entry;

  free_directory(dir);

  dp = opendir(path);
  if (dp == NULL) {
    perror("opendir");
    return -1;
  }

  dir->items = malloc(sizeof(char *));
  dir->items[0] = strdup("..");
  dir->count = 1;

  while ((entry = readdir(dp)) != NULL) {
    if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
      dir->items = realloc(dir->items, sizeof(char *) * (dir->count + 1));
      dir->items[dir->count] = strdup(entry->d_name);
      dir->count++;
    }
  }
  closedir(dp);

  qsort(&dir->items[1], dir->count - 1, sizeof(char *), compare);

  return 0;
}

/**
 * @brief Функция вывода директории на экран
 *
 * @param win окно вывода
 * @param dir указатель на структуру со списком
 */
void display_directory(WINDOW *win, Directory *dir) {
  int height, width;
  getmaxyx(win, height, width);
  werase(win);
  box(win, 0, 0);

  for (int i = dir->top; i < dir->count && i < dir->top + height - 3; ++i) {
    if (i == dir->selected) {
      wattron(win, COLOR_PAIR(4));
    }
    mvwprintw(win, i - dir->top + 2, 2, "%s", dir->items[i]);
    wattroff(win, COLOR_PAIR(4));
  }
  wrefresh(win);
}

/**
 * @brief Функция compare предназначена для предоставления функции сравнения для
 * qsort, чтобы она могла сортировать массив строк. Использование const
 * обеспечивает безопасность и предотвращает изменение данных, на которые
 * указывают указатели.
 *
 * @param a параметр сравнения, строка
 * @param b параметр сравнения, строка
 * @return Функция strcmp используется для сравнения двух строк. Она возвращает
 * 0, если строки равны, <0, если первая строка меньше второй, >0, если первая
 * строка больше второй.
 */
int compare(const void *a, const void *b) {
  return strcmp(*(const char **)a, *(const char **)b);
}

/**
 * @brief Функция free_directory освобождает память, выделенную для структуры
 * Directory
 *
 * @param dir структура Directory
 */
void free_directory(Directory *dir) {
  if (dir->items) {
    for (int i = 0; i < dir->count; ++i) {
      free(dir->items[i]);
    }
    free(dir->items);
  }
  dir->count = 0;
  dir->selected = 0;
}

/**
 * @brief Печать информации о памяти
 *
 * @param left_win Левое окно
 * @param right_win Правое окно
 */
void print_mem(WINDOW *left_win, WINDOW *right_win) {
  struct statvfs stat;

  int height, width;
  getmaxyx(left_win, height, width);
  getmaxyx(right_win, height, width);

  if (statvfs("/", &stat) != 0) {
    mvwprintw(left_win, height - 2, width - 20, "Error");
    mvwprintw(right_win, height - 2, width - 20, "Error");
  } else {
    unsigned long total_space = stat.f_blocks * stat.f_frsize;
    unsigned long free_space = stat.f_bfree * stat.f_frsize;

    double total_space_gb = total_space / 1024.0 / 1024.0 / 1024.0;
    double free_space_gb = free_space / 1024.0 / 1024.0 / 1024.0;
    double percent_total = free_space_gb / total_space_gb;

    mvwprintw(left_win, height - 2, width - 24, "%.2fG/%.2fG(%.2f%%)",
              free_space_gb, total_space_gb, percent_total * 100);
    mvwprintw(right_win, height - 2, width - 24, "%.2fG/%.2fG(%.2f%%)",
              free_space_gb, total_space_gb, percent_total * 100);
  }
  wrefresh(left_win);
  wrefresh(right_win);
}
/**
 * @brief Печать информационные столбцов панели
 *
 * @param left_win Левое окно
 * @param right_win Правое окно
 */
void print_name(WINDOW *left_win, WINDOW *right_win) {
  int height, width;
  getmaxyx(left_win, height, width);
  getmaxyx(right_win, height, width);

  mvwprintw(left_win, 1, 1, ".n");
  mvwprintw(left_win, 1, width / 3, "Name");
  mvwprintw(left_win, 1, 2 * width / 3, "Size");
  mvwprintw(left_win, 1, width / 1.15, "MT");

  mvwprintw(right_win, 1, 1, ".n");
  mvwprintw(right_win, 1, width / 3, "Name");
  mvwprintw(right_win, 1, 2 * width / 3, "Size");
  mvwprintw(right_win, 1, width / 1.15, "MT");

  mvwprintw(left_win, 0, 2, "%s", getcwd(NULL, PATH_MAX));
  mvwprintw(right_win, 0, 2, "%s", getcwd(NULL, PATH_MAX));

  wrefresh(left_win);
  wrefresh(right_win);
}

/**
 * @brief Печать информационной панели
 *
 * @param win Окно
 */
void print_info(WINDOW *win) {
  int height, width;
  getmaxyx(win, height, width);

  werase(win);
  wattron(win, COLOR_PAIR(3));
  box(win, 0, 0);

  mvwprintw(win, 1, 1, "Information Panel \tTAB - switch window\tq - quit");

  wrefresh(win);
}
