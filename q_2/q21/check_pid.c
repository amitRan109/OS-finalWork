#include <stdio.h> 
#include <stdlib.h> 
#include <signal.h>  
#include <errno.h> 
#include <string.h>

void _kill (pid_t pid) {
    kill(pid,0);
    switch(errno) {
        case 0: 
            printf("Process %d exists\n",pid);
            break;
        case ESRCH: 
            printf("process %d does not exists\n",pid); 
            break;
        case EPERM: 
            printf("process %d exists but we have no permission\n",pid);
            break;
    }
}

int main (int argc, char* argv[]){
    if (argc < 2) {
        printf ("error: enter number\n");
    }
    else {
        pid_t pid = atoi(argv[1]);
        _kill(pid);
    }
    
    return 0;
}