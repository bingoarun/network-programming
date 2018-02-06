#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    int sz;
    int fd = open("foo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    sz = write(fd,"abcdefhjij",11);
    close(fd);

}