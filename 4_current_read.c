#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>


int main() {
    pid_t chpid;
    char name[] = "aaa.fifo";
    char str[] = "Hello!";
    char restr[7];
    size_t size;
    int fd;

    if (mknod(name, S_IFIFO | 0666, 0) < 0 && errno != EEXIST) { //Инициализируем fifo
        printf("Can't create fifo\n");
        exit(-1);
    }


    if ((fd = open(name, O_RDONLY)) < 0)        //Открываем fifo
    {
        printf("Can't open file fifo\n");
        exit(-1);
    }

    size = read(fd, restr, 7);                  //Считываем fifo
    printf("Child has read restr: <%s>\n", restr);
}