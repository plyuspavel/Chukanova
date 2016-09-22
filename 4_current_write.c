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

    if (mknod(name, S_IFIFO|0666, 0) < 0 && errno != EEXIST) //Инициализация fifo
    {
        printf("Can't create fifo\n");
        exit(-1);
    }



    if ((fd = open(name, O_WRONLY)) < 0) //Открытие fifo для записи
    {
        printf("Can't write\n");
        exit(-1);

    }

    size = write(fd, str, 7);         //Запись в fifo

    if (size != 7)
        printf("Can't write 7");

    printf("Parent has wrote str in file\n");

    return 0;
}