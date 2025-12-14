#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int mysystem(const char* command) {
    if (command == NULL){
        return 1;
    }

    pid_t child_pid = fork();

    if (child_pid == 0){
        execl("/bin/sh", "sh", "-c", command, (char *)NULL);

        exit(127);
    }else{
        int status;

        if (waitpid(child_pid, &status, 0) == -1){
            return -1
        }

        return status;
    }
}

int main(void){

    system("ls -l | wc -l");
    system("find . -name '*.c");

    mysystem("ls -l | wc -l");
    mysystem("find . -name '*.c");

    pritnf("Good Bye~\n");

    return 0;


}