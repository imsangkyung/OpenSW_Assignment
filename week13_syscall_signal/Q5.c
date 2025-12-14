#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

struct two_double{
    double a;
    double b;
};
struct two_double data;

void sigint_handler(int _signo){
    printf("%f, %f\n", data.a, data.b);
    alarm(1);
}

int main(){
    struct sigaction sa_sigalarm;
    struct two_double zeros = {0.0, 0.0}, ones = {1.0, 1.0};

    sigset_t mask_set, old_set;

    sigemptyset(&mask_set);
    sigaddset(&mask_set, SIGALRM);


    sa_sigalarm.sa_handler = sigint_handler;
    sigemptyset(&sa_sigalarm.sa_mask);
    sa_sigalarm.sa_flags = 0;
    if (sigaction(SIGALRM, &sa_sigalarm, NULL) == -1){
        perror("sigaction error: ");
        exit(0);
    }

    alarm(1);
    while(1){
        sigprocmask(SIG_BLOCK, &mask_set, &old_set);
        data = zeros;
        sigprocmask(SIG_SETMASK, &old_set, NULL);

        sigprocmask(SIG_BLOCK, &mask_set, &old_set);
        data = ones;
        sigprocmask(SIG_SETMASK, &old_set, NULL);
    }

    return 0;
}
