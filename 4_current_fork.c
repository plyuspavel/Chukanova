#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>


int main()
{
    pid_t chpid;
    char name[] = "aaa.fifo";
    char str[] = "Hello!";
    char restr[7];
    size_t size;
    int fd;

    if (mknod(name, S_IFIFO|0666, 0) < 0 && errno != EEXIST)
    {
        printf("Can't create fifo\n");
        exit(-1);
    }

    chpid = fork();
    
    if (chpid < 0)
    {
        printf("Error fork");
        exit(-1);
    }
     

    if (chpid > 0)
    {
        if ((fd = open(name, O_WRONLY)) < 0)
        {
            printf("Can't write\n");
            exit(-1);

        }

        size = write(fd, str, 7);

        if (size != 7)
            printf("Can't write 7");

        printf("Parent has wrote str in file\n");

    }
    else
    {
        if ((fd = open(name, O_RDONLY)) < 0)
        {
            printf("Can't open file fifo\n");
            exit(-1);
        }

        size = read(fd, restr, 7);
        printf("Child has read restr: <%s>\n", restr);

    }


    return 0;
}