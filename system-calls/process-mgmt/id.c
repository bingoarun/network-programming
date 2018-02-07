#include<unistd.h>
#include<stdio.h>
void main()
{
    printf("Process ID: %d",getpid());
    printf("Parent process: %d",getppid()); //prints process ID of shell 'echo $$'

}