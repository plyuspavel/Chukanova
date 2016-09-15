
int open(const char* pathname, int flags, mode_t mode)

O_APPEND
O_RDONLY
O_RDWR
O_CREAT Если нет файла, то создает файл
O_EXCL Если не первое открытие файла, то ошибка

mode - права доступа

rwxrwxrwx
110110110 = 0666
100100100

int close(int fd)
int write(int fd, void* buffer, size_t nbyte) возвращает или -1 или кол-во записанных байтов



