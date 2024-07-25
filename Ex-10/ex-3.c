#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid;
  char str_command[256];

  while (1) {
    printf("Введите команду: ");
    fgets(str_command, sizeof(str_command), stdin);

    str_command[strcspn(str_command, "\n")] = 0;

    if (strcmp(str_command, "exit") == 0) {
      break;
    }

    pid = fork();
    if (pid == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
    }

    if (pid == 0) {
      char *args[10];
      char *token = strtok(str_command, " ");
      int i = 0;
      while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
      }
      args[i] = NULL;

      char path[256] = "/bin/";
      strcat(path, args[0]);

      execv(path, args);

      perror("execv");
      exit(EXIT_FAILURE);
    } else {
      int status;
      waitpid(pid, &status, 0);
    }
  }

  return 0;
}
