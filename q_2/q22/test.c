#include<stdio.h> 
#include<signal.h> 

void handler (int sig){
    printf("signal type %d\n", sig);
}

int main () {
    signal(SIGINT, handler);
    while(1);
    return 0;
}