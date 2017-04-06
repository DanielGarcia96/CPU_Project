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
    int a = 1;
    int b = 1;
    n = sub(n, 2, verbose);

    // Print first two numbers
    printf("%u\n%u\n", a, b);

    int i;
    for(i = 0; i < n; i = add(i, 1, verbose))
    {
        int c = a;
        a = add(a, b, verbose);
        b = c;
        printf("%u\n", a);
    }
}
