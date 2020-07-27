#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>  
#include<signal.h> 

int num =0;

void handler (int sig) {
   switch (sig) {
   case SIGINT:
      num ++;
      break;
   
   case SIGUSR1:
      printf("%d\n", num);   
      break;
   }
}

int main (){
   printf ("%d \n",getpid());
   signal(SIGINT, handler);
   signal(SIGUSR1, handler);
   while (1);
   return 0;
}