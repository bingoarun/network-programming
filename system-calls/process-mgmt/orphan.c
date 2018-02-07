// Program to demonstrate Orphan process
// Ref: https://stackoverflow.com/questions/15183427/getpid-and-getppid-return-two-different-values
// Orphan process is adopted by the init process (whose PID is 1)

#include <stdio.h>
#include <unistd.h>

int main(){

    int id ;
    id = fork() ;
    printf("id value : %d\n",id);
    if ( id == 0 ) // Returned 0 for child process; code executed in child
    {
    sleep(1); // To make parent process die before the child process
    printf ( "Child : Hello I am the child process\n");
    printf ( "Child : My PID: %d\n", getpid());
    printf ( "Child : Parent’s PID: %d\n", getppid());
    }
    else  // Return id>0 for parent processes; code executed in parent
    {
    printf ( "Parent : Hello I am the parent process\n" ) ;
    printf ( "Parent : My PID: %d\n", getpid());
    printf ( "Parent : Parent’s PID: %d\n", getppid());
    printf ( "Parent : Child’s PID: %d\n", id);
    
    } 

}

/*
Ouput - 

[arun@iblldvarunpr process-mgmt]$ ./a.out 
id value : 22363
Parent : Hello I am the parent process
Parent : My PID: 22362
Parent : Parent’s PID: 9183
Parent : Child’s PID: 22363
id value : 0
[arun@iblldvarunpr process-mgmt]$ Child : Hello I am the child process
Child : My PID: 22363
Child : Parent’s PID: 1

[arun@iblldvarunpr process-mgmt]$ 
*/