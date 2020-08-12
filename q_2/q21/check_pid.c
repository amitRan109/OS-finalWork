#include <stdio.h> 
#include <stdlib.h> 
#include <signal.h>  
#include <errno.h> 
#include <string.h>

void _kill (pid_t pid) { //check if the pid exists
    kill(pid,0); //send a signal to the process
    switch(errno) { 
        case 0: 
            printf("Process %d exists.\n",pid);
            break;
        case ESRCH: 
            printf("Process %d does not exists.\n",pid); 
            break;
        case EPERM: 
            printf("Process %d exists but we have no permission.\n",pid);
            break;
    }
}

int main (int argc, char* argv[]){
    if (argc < 2) { //check if we got a pid
        printf ("error: not enough arguments\n");
    }
    else {
        pid_t pid = atoi(argv[1]);
        _kill(pid);
    }
    
    exit(EXIT_SUCCESS);
}