#include <limits.h>
#include "alu.h"

// U100 prototype
int addsub(addSub packet, char verbose)
{
    // Need to do twos_complement in the case of subtraction
    if(packet.op == 'S')
    {
        packet.b = ~packet.b;
        addSub result = { 'A', packet.t, packet.b, 1 };
        packet.b = addsub(result, verbose);
    }

    // Set up a loop control variable, see how big an integer is in this architecture
    int i, int_size = sizeof(int) * CHAR_BIT;

    // Loop through every bit in the number
    for(i = 0; i < int_size; i++)
    {
        // Copy any carry outs
        int c = packet.a & packet.b;

        // Shift it forward one so it adds to the right bit
        c <<= 1;

        // Xor to get the first binary addition
        packet.a ^= packet.b;

        // Copy the carry out into b
        packet.b = c;
    }
    
    // Return the result
    return packet.a;
}

// U112 prototype
void MUX1(int op[], int sel)
{
    
}

// U113 prototype
void MUX2(int op[], int sel)
{
    
}
