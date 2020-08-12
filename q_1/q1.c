#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>

char globBuf[65536];            /* 1. allocated in uninitialized data section external*/
int primes[] = { 2, 3, 5, 7 };  /* 2. allocated in initialized data section external*/

static int
square(int x)                   /* 3. allocated in text section local symbol*/
{
    int result;                 /* 4. allocated in stack section*/

    result = x * x;
    return result;              /* 5. the value passed via register */
}

static void
doCalc(int val)                 /* 6. allocated in text section local symbol */
{
    printf("The square of %d is %d\n", val, square(val));

    if (val < 1000) {
        int t;                  /* 7. allocated in stack section*/

        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

int
main(int argc, char* argv[])    /* allocated in text section local symbol*/
{
    static int key = 9973;      /* allocated in allocated in initialized data section, local symbol */
    static char mbuf[10240000]; /* allocated in allocated in uninitialized data section, local symbol*/
    char* p;                    /* allocated in stack section */


    doCalc(key);

    exit(EXIT_SUCCESS);
}

