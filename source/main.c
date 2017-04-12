#include <stdio.h>
#include "alu.h"

void fibonacci(int n, char verbose);

int main(int argc, char *argv[])
{
    fibonacci(30, 'V');
    return 0;
}

// Function to test the accuracy of my addsub function
void fibonacci(int n, char verbose)
{
    printf("Printing first %u Fibonacci numbers\n", n);

    addSub i = { 'A', 'U', 3, 1 };
    addSub packet = { 'A', 'U', 2, 1 };

    // Print first two numbers
    printf("fibonacci %3u: %10u\n", 1, packet.b);
    printf("fibonacci %3u: %10u\n", 2, packet.a);

    for(; i.a <= n; i.a = addsub(i, verbose))
    {
        int c = packet.a;
        packet.a = addsub(packet, verbose);
        packet.b = c;
        printf("fibonacci %3u: %10u\n", i.a, packet.a);
    }
}
