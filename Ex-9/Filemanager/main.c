#include "main.h"
int main(){
    initscr();                                                                 
    noecho();                                                                  
    curs_set(0);                                                               
    keypad(stdscr, TRUE);                                                      
    start_color();                                                             
    cbreak();                                                                  
    nodelay(stdscr, TRUE);  
    start_program();
    endwin();
}


void start_program() {
    int panel_height = LINES - 3;  
    int info_height = 3;        

    WINDOW *left_win = newwin(panel_height, COLS / 2, 0, 0);
    WINDOW *right_win = newwin(panel_height, COLS / 2, 0, COLS / 2);
    WINDOW *info_win = newwin(info_height, COLS, LINES - info_height, 0);

    init_pair(1, COLOR_RED, COLOR_BLACK);  
    init_pair(2, COLOR_WHITE, COLOR_BLUE);  
    init_pair(3, COLOR_WHITE, COLOR_BLACK);

    wattron(left_win, COLOR_PAIR(3));
    wattron(right_win, COLOR_PAIR(3));
    wattron(info_win, COLOR_PAIR(2));

    box(left_win, 0, 0);
    box(right_win, 0, 0);
    box(info_win, 0, 0);

    wrefresh(left_win);
    wrefresh(right_win);
    wrefresh(info_win);

    WINDOW *wind = left_win;

    char start_dir_left[1024] = ".";
    char start_dir_right[1024] = ".";

    int target_left = 0;
    int target_right = 0;

    int num_files_left = 0;
    int num_files_right = 0;

    while (1) {
        num_files_left = count_files(start_dir_left) + 1;
        num_files_right = count_files(start_dir_right) + 1;
        
        int ch = getch();

        switch (ch) {
            case 'q':
                return;
            case '\t':
                wind = (wind == left_win) ? right_win : left_win;
                break;
            case KEY_UP:
                if (wind == left_win && target_left > 0) {
                    target_left--;
                } else if (wind == right_win && target_right > 0) {
                    target_right--;
                }
                break;
            case KEY_DOWN:
                if (wind == left_win && target_left < num_files_left - 1) {
                    target_left++;
                } else if (wind == right_win && target_right < num_files_right - 1) {
                    target_right++;
                }
                break;
            case '\n':
                if (wind == left_win) {
                    if (target_left == 0) {
                        move_up_directory(start_dir_left);
                        target_left = 0;
                    } else {
                        open_d(start_dir_left, target_left);
                    }
                } else {
                    if (target_right == 0) {
                        move_up_directory(start_dir_right);
                        target_right = 0;
                    }
                }
                break;  
        }
        

        werase(left_win);
        werase(right_win);

        box(left_win, 0, 0);
        box(right_win, 0, 0);

        print_mem(left_win, right_win);
        print_name(left_win, right_win);
        print_dir(start_dir_left, left_win, target_left);
        print_dir(start_dir_right, right_win, target_right);

        wrefresh(left_win);
        wrefresh(right_win);
        wrefresh(wind);
        napms(50);
    }
}

int count_files(char *path) {
    int count = 0;
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return 0;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_name[0] != '.') {
            count++;
        }
    }

    closedir(dp);
    return count;
}
void print_dir(char *path, WINDOW *window_dir, int target) {
    int height, width;
    getmaxyx(window_dir, height, width);

    struct dirent *entry;
    struct stat file_stat;
    
    DIR *dp = opendir(path);

    int y = 3;
    int index = 0;

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    if (target == 0) {
        wattron(window_dir, COLOR_PAIR(1));
    } else {
        wattron(window_dir, COLOR_PAIR(3));
    }

    mvwprintw(window_dir, y, 2, "/..");

    wattroff(window_dir, COLOR_PAIR(1));
    wattroff(window_dir, COLOR_PAIR(3));

    y++;
    index++;

    while ((entry = readdir(dp))) {
        if (entry->d_name[0] == '.') continue; 

        char file_path[1024];
        snprintf(file_path, sizeof(file_path), "%s/%s", path, entry->d_name);

        if (stat(file_path, &file_stat) == -1) {
            perror("stat");
            continue;
        }

        char time_buf[100];
        struct tm *tm_info = localtime(&file_stat.st_mtime);
        strftime(time_buf, sizeof(time_buf), "%B %d %H:%M", tm_info);

        if (index == target) {
            wattron(window_dir, COLOR_PAIR(1)); 
        } else {
            wattron(window_dir, COLOR_PAIR(3));
        }

        mvwprintw(window_dir, y, 2, "%s", entry->d_name);
        mvwprintw(window_dir, y, width / 1.41, "%ld", file_stat.st_size);
        mvwprintw(window_dir, y++, width / 1.21, "%s", time_buf);

        wattroff(window_dir, COLOR_PAIR(1));
        wattroff(window_dir, COLOR_PAIR(3));
        
        index++;
    }

    closedir(dp);
    wrefresh(window_dir);
}




void print_mem(WINDOW *left_win, WINDOW *right_win){
    struct statvfs stat;

    int height, width;
    getmaxyx(left_win, height, width);
    getmaxyx(right_win, height, width);
    
    if(statvfs("/", &stat) != 0){
        mvwprintw(left_win, height - 2, width - 20, "Error");
        mvwprintw(right_win, height - 2, width - 20, "Error");
        wrefresh(left_win);  
    }

    unsigned long total_space = stat.f_blocks * stat.f_frsize;
    unsigned long free_space = stat.f_bfree * stat.f_frsize;

    double total_space_gb = total_space / 1024.0 / 1024.0 / 1024.0;
    double free_space_gb = free_space / 1024.0 / 1024.0 / 1024.0;
    double persent_total = free_space_gb / total_space_gb;

    mvwprintw(left_win, height - 2, width - 24, "%.2fG/%.2fG(%.2f%%)", free_space_gb, total_space_gb, persent_total * 100);
    mvwprintw(right_win, height - 2, width - 24, "%.2fG/%.2fG(%.2f%%)", free_space_gb, total_space_gb, persent_total * 100);
}

void print_name(WINDOW *left_win, WINDOW *right_win){
    int height, width;
    getmaxyx(left_win, height, width);
    getmaxyx(right_win, height, width);

    mvwprintw(left_win, 1, width - width + 1, ".n");
    mvwprintw(left_win, 1, width / 2.7, "Name");
    mvwprintw(left_win, 1, width / 1.4, "Size");
    mvwprintw(left_win, 1, width / 1.2, "Modify time");

    mvwprintw(right_win, 1, width - width + 1, ".n");
    mvwprintw(right_win, 1, width / 2.7, "Name");
    mvwprintw(right_win, 1, width / 1.4, "Size");
    mvwprintw(right_win, 1, width / 1.2, "Modify time");

    wrefresh(left_win);
    wrefresh(right_win);
}

void move_up_directory(char *dir){
    if(strcmp(dir, ".") == 0){
        strcat(dir, "./");
    } else {
        strcat(dir, "../");
    }
}

void open_d(char *start_dir_left, int target_left){

    DIR *dp = opendir(start_dir_left);

    struct dirent *entry;

    

}