#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024
#define fd 1

int main()
{
    char sChaine[MAX_LENGTH];

    const char *buf = "Bienvenue dans le Shell ENSEA. \n";
    write(fd,buf,strlen(buf));
    buf = "Pour quitter, taper 'exit'. \n";
    write(fd,buf,strlen(buf));
    buf = "enseash % \n";
    write(fd,buf,strlen(buf));

    int pid;
    int status;
    ssize_t pread;
    while(1){
        pread =read(STDIN_FILENO, sChaine, MAX_LENGTH-1);
        sChaine[pread-1] = 0;
        pid = fork();

        if(pid!=0){
            wait(&status);
            EXIT_SUCCESS;
        }
        else{
            execlp(sChaine, sChaine, (char*) NULL);
            EXIT_FAILURE;
        }
        write(STDOUT_FILENO, buf, strlen(buf));
    }
    return 0;
}
