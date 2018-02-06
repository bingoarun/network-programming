#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
extern int errno; //need to read more about this stuff
int main()
{
    int fd = open("foo.txt", O_RDONLY | O_CREAT);
    printf("fd=%d\n",fd);  // 3 is returned as fd for this process because 0 is stdin, 1 is stdout and 2 is stderr
    if (fd == -1 )
    {
        printf("Error number %d\n",errno);
        perror("Program");

    }
    if (close(fd)<0)
    {
        perror("c1");
        exit(1);
    }
    printf("Closed the fd.\n")

}