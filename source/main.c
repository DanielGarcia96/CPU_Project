#include <stdio.h>
#include "alu.h"

short sp = 0;
short r0 = 0;
short r1 = 0;
short r2 = 0;
short r3 = 0;

void fibonacci(short n, char verbose);

int main(int argc, char *argv[])
{
    fibonacci(10, 'V');
    return 0;
}

void fibonacci(short n, char verbose)
{
    printf("Printing first %u Fibonacci numbers\n", n);

    short a = 1;
    short b = 1;

    printf("fibonacci %3u: %10u\n", 1, a);
    printf("fibonacci %3u: %10u\n", 2, b);

    short i;
    for(i = 3; i <= n; i = addsub(i, 1, verbose))
    {
        short c = a;
        a = addsub(a, b, verbose);
        b = c;
        printf("fibonacci %3u: %10u\n", i, a);
    }
}
