#include <stdlib.h>
#include <stdio.h>

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void sigint_handler(int sig)
{
    int status;

    printf("[SIGINT handler]------------\n");
    pid_t pid = fork();
    if ( pid == 0 ){

        char *argv[] = {"ls", NULL};
        execve("/bin/ls", argv, NULL);

    }else {
        wait(&status);
    }
}

void sigquit_handler(int sig)
{
    int status;

    printf("[SIGQUIT handler] -------------\n");
    pid_t pid = fork();

    if (pid == 0){
        char *argv[] = {"date", NULL};
        execve("/bin/date", argv, NULL);
    } else{
        wait(&status);
    }

}

void sigalarm_handler(int sig)
{
    int status;

    printf("[SIGALARM handler] --------------\n");
    pid_t pid = fork();
    
    if (pid == 0){
        char *argv[] = {"whoami", NULL};
        execve("/bin/whoami", argv, NULL);
    } else {
        wait(&status);
    }
    alarm(3);
    
}

int main()
{
    struct sigaction sa_int;
    struct sigaction sa_quit;
    struct sigaction sa_alarm;

    sa_int.sa_handler = sigint_handler;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;

    sa_quit.sa_handler = sigquit_handler;
    sigemptyset(&sa_quit.sa_mask);
    sa_quit.sa_flags = 0;

    sa_alarm.sa_handler = sigalarm_handler;
    sigemptyset(&sa_alarm.sa_mask);
    sa_alarm.sa_flags = 0;

    sigaction(SIGINT, &sa_int, NULL);
    sigaction(SIGQUIT, &sa_quit, NULL);
    sigaction(SIGALRM, &sa_alarm, NULL);

    alarm(3);


    for (;;)
    {
        sleep(1);  
    }

    return 0;
}