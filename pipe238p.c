#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/* ls |grep "main" |wc */

int
main(int argc, char* argv[])
 {
  char* arg[3][3] = {{"ls", NULL}, {"grep", "main", NULL}, {"wc", NULL}};

  const int WRITE_END = 1;
  const int READ_END = 0;

  int fd[2];
  pipe(fd);
  if(fork() == 0) {
    close(fd[READ_END]);

    dup2(fd[WRITE_END], STDOUT_FILENO);
    close(fd[WRITE_END]);

    execvp(arg[0][0], arg[0]);
  }

  int fd2[2];
  pipe(fd2);
  if (fork() == 0) {

    dup2(fd[READ_END], STDIN_FILENO);
    close(fd[READ_END]);
    close(fd[WRITE_END]);

    dup2(fd2[WRITE_END], STDOUT_FILENO);
    close(fd2[WRITE_END]);
    close(fd2[READ_END]);

    wait(NULL);
    execvp(arg[1][0], arg[1]);

  }

  if (fork() == 0) {
    dup2(fd2[READ_END], STDIN_FILENO);
    close(fd2[READ_END]);
    close(fd2[WRITE_END]);
    close(fd[READ_END]);
    close(fd[WRITE_END]);

    wait(NULL);
    execvp(arg[2][0], arg[2]);
    
  }
  close(fd[READ_END]);
  close(fd[WRITE_END]);
  close(fd2[READ_END]);
  close(fd2[WRITE_END]);
  wait(NULL);

 }
