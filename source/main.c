#include <stdio.h>
#include "alu.h"

uint16_t sp;
uint8_t r0;
uint8_t r1;
uint8_t r2;
uint8_t r3;

void fibonacci(uint8_t n);

int main(int argc, char *argv[])
{
    fibonacci(10);
    return 0;
}

void fibonacci(uint8_t n)
{
    printf("Printing first %u Fibonacci numbers\n", n);

    uint8_t a = 1;
    uint8_t b = 1;

    printf("fibonacci %3u: %10u\n", 1, a);
    printf("fibonacci %3u: %10u\n", 2, b);

    uint8_t i, overflow = 0, carry_out = 0;
    for(i = 3; i <= n && !overflow && !carry_out; i = alu_add_sub(i, 1, 0, &overflow, &carry_out))
    {
        uint8_t c = a;
        a = alu_add_sub(a, b, 0, &overflow, &carry_out);
        b = c;
        printf("fibonacci %3u: %10u\n", i, a);
    }
}
