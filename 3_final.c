#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>



int main()
{
    int fd[2];

    int fd2[2];
    pid_t chpid;
    size_t size;
    char str[] = "Hello!";
    char str2[] = "Hi!";
    char restr[10];
    if (pipe(fd) < 0)
    {
        printf("Can't open file\n");
        exit(-1);
    }

    if (pipe(fd2) < 0)
    {
        printf("Can't open file\n");
        exit(-1);
    }

    chpid = fork();

    if(chpid < 0)
    {
        printf("Error\n");
        exit(-1);
    }
    else if (chpid > 0)
    {
        close(fd[0]);
        close(fd2[1]);
        
        size = write(fd[1], str, 7);
        if (size != 7)
            printf("Can't write all\n");
        
        printf("Parent wrote\n");

        
        size = read(fd2[0], restr, 4);
        printf("Parent read <%s>\n", restr);
        
        printf("parrent end\n");
        close(fd2[0]);
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        close(fd2[0]);
        size = read(fd[0], restr, 7);
        printf("child read <%s>\n", restr);
        

        
        size = write(fd2[1], str2, 4);
        if (size != 4)
            printf("Can't write all\n");
        
        printf("Child wrote\n");
        close(fd2[1]);
        close(fd[0]);
    }

    return 0;
};
