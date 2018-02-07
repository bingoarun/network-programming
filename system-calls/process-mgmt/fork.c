#include<stdio.h>
#include<unistd.h>
int main()
{
    
    int id=fork();
    printf("Parent Process ID is %d\n",getppid());
    printf("Process ID is %d\n",getpid());
    printf("Child ID is %d\n",id);
    switch(id){
        case -1:
            printf("Fork failed");
            break;
        case 0: // id is 0 returned to client on success
            printf("Child created");
            break;
        default:
            printf("Parent process\n\n");

    }
}

/* OUTPUT

[arun@dell process-mgmt]$ ./a.out 
Parent Process ID is 9183
Process ID is 21114
Child ID is 21115
Parent process

Parent Process ID is 21114
Process ID is 21115
Child ID is 0
Child created

*/