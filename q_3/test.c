#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <errno.h> 


int main(int argc, char *argv[]) {
    // if (argc < 3) {
    //     printf("no enough param\n");
    //     exit (EXIT_FAILURE);
    // }
    // pid_t pid = atoi(argv[3]);
    // if (pid == 0) pid = getppid();

    // int priority = atoi(argv[2]);

    struct sched_param sp = { .sched_priority = 50 };
    int ret = sched_setscheduler(4423,SCHED_RR, &sp);

    switch (errno)
    {
    case EINVAL:
        printf("The priority or policy isn't a valid value. \n");        break;
    case EPERM:
        printf("The calling process doesn't have sufficient privilege to set the priority. \n");        break; 
    case ESRCH:
        printf("The process pid doesn'\n");        break;
    default:
        printf("OK\n");
    }

    // if (ret == -1) {
    //     perror("sched_setscheduler");
    //     exit (EXIT_FAILURE);
    // }
    
    exit(EXIT_SUCCESS);
 }