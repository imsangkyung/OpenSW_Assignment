#include <unistd.h>

#include <stdio.h>

int main(){

    pid_t my_pid = getpid();
    pid_t my_parent_pid = getppid();

    printf("pid: %lu\n", (long)my_pid);
    printf("ppid: %lu\n", (long)my_parent_pid);

    return 0;
}