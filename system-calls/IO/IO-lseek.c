#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int fd = open("foo.txt",O_RDONLY);
    char arr[10];
    read (fd,arr,10);
    printf("%s\n",arr);
    lseek(fd,5,SEEK_SET); // explore SEEK_CUR and SEEK_end
    read (fd,arr,10);
    printf("%s\n",arr);
    close(fd);
}