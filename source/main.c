#include <stdio.h>
#include "alu.h"

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

    short i;
    for(i = 3; i <= n; i = addsub(i, 1, verbose))
    {
        short c = a;
        a = addsub(a, b, verbose);
        b = c;
        printf("fibonacci %3u: %10u\n", i, a);
    }
}
