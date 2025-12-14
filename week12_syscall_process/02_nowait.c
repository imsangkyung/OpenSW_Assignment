#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == 0){
        sleep(1);

        printf("Child process PID: %lu \n", (unsigned long)getpid());
        printf("Child process PPID: %lu \n", (unsigned long)getppid());
        
        return 7;

    }
    else{

            printf("Parnet process PID: %lu \n", (unsigned long)getpid());
            printf("Parnet process PPID: %lu \n", (unsigned long)getppid());
            
            exit(0);
        
    }
}