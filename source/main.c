#include <stdio.h>
#include "alu.h"

reg_t sp = 0;
reg_t r0 = 0;
reg_t r1 = 0;
reg_t r2 = 0;
reg_t r3 = 0;

void fibonacci(reg_t n, char verbose);

int main(int argc, char *argv[])
{
    fibonacci(10, 'V');
    return 0;
}

void fibonacci(reg_t n, char verbose)
{
    printf("Printing first %u Fibonacci numbers\n", n);

    reg_t a = 1;
    reg_t b = 1;

    printf("fibonacci %3u: %10u\n", 1, a);
    printf("fibonacci %3u: %10u\n", 2, b);

    reg_t i;
    for(i = 3; i <= n; i = addsub(i, 1, verbose))
    {
        reg_t c = a;
        a = addsub(a, b, verbose);
        b = c;
        printf("fibonacci %3u: %10u\n", i, a);
    }
}
