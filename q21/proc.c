#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
#include<signal.h>  


int main (){
    printf ("%d\n",getpid());
    while (1);
    return 0;
}