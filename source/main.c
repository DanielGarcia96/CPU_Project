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
void init_hex(void);
unsigned char hex_to_byte(char *str);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: cpu [HEX-PROGRAM]\n");
        return 1;
    }

    char *code = argv[1];
    size_t code_len = strlen(code);
    if (code_len % 2 != 0)
    {
        fprintf(stderr, "USAGE: cpu [HEX-PROGRAM]\n\n");
        fprintf(stderr, "HEX-PROGRAM must have an even number of characters.\n");
        return 1;
    }

    init_hex();

    int byte;
    while (code_len > 0)
    {
        printf("%d\n", (int)hex_to_byte(code));
        code += 2;
        code_len -= 2;
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

char hex[256];

void init_hex(void)
{
    for (int i = 0; i < 256; i++)
    {
        if (i >= '0' && i <= '9')
        {
            hex[i] = i - '0';
        }
        else if (i >= 'A' && i <= 'F')
        {
            hex[i] = i - 'A' + 10;
        }
        else if (i >= 'a' && i <= 'f')
        {
            hex[i] = i - 'a' + 10;
        }
        else
        {
            hex[i] = 0xFF;
        }
    }
}

// Assumes at least two characters in input string
unsigned char hex_to_byte(char *str)
{
    unsigned char value_0 = hex[str[0]];
    unsigned char value_1 = hex[str[1]];

    if (value_0 == 0xFF || value_1 == 0xFF)
    {
        fprintf(stderr, "USAGE: cpu [HEX-PROGRAM]\n\n");
        fprintf(stderr, "HEX-PROGRAM must contain only hexadecimal characters.\n");
        exit(1);
    }

    return (value_0 << 4) | value_1;
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
