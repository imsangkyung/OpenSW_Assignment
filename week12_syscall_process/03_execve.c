#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    if (argc < 2){
        printf("Usage: %s [OPTION] ... \n", argv[0]);
        return 1;
    }

    pid_t child_pid = fork();

    if (child_pid == 0){

        execve(argv[1], &argv[1], NULL);

        exit(1);
    }else{

        int status;
        
        waitpid(child_pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Child exited with status: %d\n", WEXITSTATUS(status));
        }
    }

    return 0;

}