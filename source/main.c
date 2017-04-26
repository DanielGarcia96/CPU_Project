#include <stdio.h>
#include "alu.h"
#include "mem.h"

reg8_t r0 = 0;
reg8_t r1 = 0;
reg8_t r2 = 0;
reg8_t r3 = 0;
reg16_t sp = 0xE00;
reg8_t alu_output = 0;

char Data[4096];
char memoryArray[16][4096] = {};

void fibonacci(uint8_t n);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: cpu [HEX-PROGRAM]\n");
        return 1;
    }

    // RW variables
    char address[10];
    char inputAddr[10];
    char inputData []= "abcdefghi444444444444444444444";
    int i = 0;

    char* returnData;
    
    char *code = argv[1];
    int byte;
    int offset = 0;
    while ((offset = sscanf(code, "%02X", &byte)) != EOF)
    {
        code += offset;
        // Process current byte
    }
    
    // fetch, decode, execute loop goes here
    /*
        while ( there are instructions left)
        {
            decode instructions
            execute instructions
            decide which output needs to be retrieved:
                e.g. printf("%u\n", alu_output);
            update the clock
        }
    */
    return 0;
}

void fibonacci(reg8_t n)
{
    printf("Printing first %u Fibonacci numbers\n", n);

    reg8_t a = 1;
    reg8_t b = 1;

    printf("fibonacci %3u: %10u\n", 1, a);
    printf("fibonacci %3u: %10u\n", 2, b);

    bit_t v = 0, c = 0;
    for(reg8_t i = 3; i <= n && !v && !c; i = alu_add_sub(i, 1, 0, &v, &c))
    {
        reg8_t prev_a = a;
        a = alu_add_sub(a, b, 0, &v, &c);
        b = prev_a;
        printf("fibonacci %3u: %10u\n", i, a);
    }
}
