#include <stdio.h>
#include "alu.h"

void fibonacci(int n, char verbose);

int main(int argc, char *argv[])
{
    fibonacci(30, 'V');
    return 0;
}

void fibonacci(int n, char verbose)
{
    printf("Printing first %u Fibonacci numbers\n", n);

    int a = 1;
    int b = 1;

    // Print first two numbers
    printf("fibonacci %3u: %10u\n", 1, a);
    printf("fibonacci %3u: %10u\n", 2, b);

    int i;
    for(i = 3; i <= n; i = add(i, 1, verbose))
    {
        int c = a;
        a = add(a, b, verbose);
        b = c;
        printf("fibonacci %3u: %10u\n", i, a);
    }
}
