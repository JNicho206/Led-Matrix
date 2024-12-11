#ifndef _H_PAIR_
#define _H_PAIR_
#include <stdint.h>

struct MatrixPair
{
    uint8_t row, col;
    MatrixPair(uint8_t r, uint8_t c) : row(r), col(c) {};
    MatrixPair() : row(0), col(0) {};
};

#endif