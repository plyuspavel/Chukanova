#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct mystr
    {
        double a;
        char str[20];
    }* pstr;

    key_t key;
    int shmid;
    key = ftok("asm.s", 0);
    if ((shmid = shmget(key, sizeof(struct mystr), 0666|IPC_CREAT)) < 0)
    {
        printf("Can't create shm\n");
    }

    if ((pstr = (struct mystr*) shmat(shmid, NULL, 0)) == NULL)
    {
        printf("Can't at to shm");
        exit(-1);
    }

    pstr->a = 5.95;
    strcpy(pstr->str, "Hello!");
    shmdt(pstr);
    printf("Process 1 finished\n");
    return 0;
}