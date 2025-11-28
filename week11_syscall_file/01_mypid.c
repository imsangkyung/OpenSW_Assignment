#include <unistd.h>

#include <stdio.h>

int main(){

    pid_t my_pid = getpid();

    printf("pid:    %lu\n", (long)my_pid);

    return 0;
}