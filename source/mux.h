#ifndef MUX_H
#define MUX_H

#include <stdint.h>
#include <stdlib.h>

static uint8_t mux_4_to_1(uint8_t input[4], uint8_t select)
{
    if (select >= 4)
    {
        fprintf(stderr, "'select' control signal out of bounds.\n");
        exit(1);
    }

    return input[select];
}

static uint8_t mux_8_to_1(uint8_t input[8], uint8_t select)
{
    if (select >= 8)
    {
        fprintf(stderr, "'select' control signal out of bounds.\n");
        exit(1);
    }

    return input[select];
}

#endif
