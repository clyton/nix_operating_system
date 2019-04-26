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
/**
 * @brief ...
 * 
 * @param argc p_argc:...
 * @param argv ${p_argv:...}
 * @return int
 */
main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "%s <file1> <file2>", argv[0]);
        exit(-1);
    }
    
    int BUF_SIZE = 512;
    char buf[BUF_SIZE];
    char* source = argv[1];
    char* destination = argv[2];
    int sourcefd = open(source, O_RDONLY);
    int destfd = open(destination, O_CREAT|O_WRONLY, S_IRWXU);
    
    int bufread = 0; // no. of bytes read 
    while (bufread = read(sourcefd, buf, BUF_SIZE) , bufread != 0) {
        write(destfd, buf, bufread);
    }
    close(sourcefd);
    close(destfd);
    
}

