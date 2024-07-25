#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid;

  pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (pid == 0) {
    printf("Дочерний процесс pid = %d ppid = %d\n", getpid(), getppid());
    exit(EXIT_SUCCESS);
  } else {
    int status;
    printf("Родительский процесс pid = %d ppid = %d\n", getpid(), getppid());
    waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
      printf("Дочерний процесс %d завершился: %d\n", pid, WEXITSTATUS(status));
    } else {
      printf("Дочерний процесс %d не завершился\n", pid);
    }
  }

  exit(EXIT_SUCCESS);
}