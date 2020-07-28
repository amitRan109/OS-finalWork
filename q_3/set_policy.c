#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

void set (int pid, int priority, int policy){
    struct sched_param sp = { .sched_priority = priority };
    int ret = sched_setscheduler(pid, policy, &sp);
    if (ret == -1) {
        perror("sched_setscheduler");
        return 1;
    }
}

int main(int argc, char *argv[])
{
    pid_t pid = getpid();
    if (pid == 0) pid = getppid();
    int policy = atoi(argv[1]);
    int priority = atoi(argv[2]);
    set (pid, priority, policy);
    return 0;
 }