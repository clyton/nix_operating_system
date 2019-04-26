#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int
main()
{
    close(STDOUT_FILENO);
    open("y", O_CREAT|O_WRONLY, S_IRWXU);
    
    char *lsarg[1] = {"/bin/ls"};
    char *env[] = {NULL};
    execve("/bin/ls", lsarg, env);
    perror("execve");
    exit(EXIT_FAILURE);
}
