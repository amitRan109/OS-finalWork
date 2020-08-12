#include <sched.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void set (int policy, int priority);

int main(int argc, char *argv[]) {
    
    if (argc != 3) {
        printf("Error! try different parametes\n");
        exit (EXIT_FAILURE);
    }

    int policy = atoi(argv[1]);
    int priority = atoi(argv[2]);
    set(policy, priority);

    while(1) {
        pid_t pid = getpid();
        printf("%d \n", pid);        
        sleep(10);
    }
    
    exit(EXIT_SUCCESS);
 }

void set (int policy, int priority){
    struct sched_param sp = { .sched_priority = priority };
    int ret = sched_setscheduler(0,policy , &sp);

    if (ret == -1) {
        perror("sched_setscheduler");
        exit (EXIT_FAILURE);
    } 
}
 