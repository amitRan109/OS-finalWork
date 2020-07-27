#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
#include<signal.h>

void send_msg (pid_t pid, int sig_type , int count){
    int reg;
    switch (sig_type)
    {
    case 2:
        for (int i=0; i < count; i++){
            reg = kill (pid, SIGINT);
            sleep(0.1);
        }
        break;
    case 10:
        for (int i=0; i < count; i++){
            reg = kill (pid, SIGUSR1);
        }
        break;
    default:
        printf ("error in sig type\n");
        break;
    }
    
}

int main (int argc, char* argv[]){
    if (argc < 4) printf ("error\n");
    else {
        pid_t serv_pid = atoi(argv[1]); 
        int sig_type = atoi(argv[2]); 
        int count = atoi(argv[3]);
        send_msg (serv_pid, sig_type, count);
    }
    return 0;
}