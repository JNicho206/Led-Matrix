#ifndef _H_COLOR_
#define _H_COLOR_
#include <stdint.h>
#define MAX_RED 255
#define MAX_BLUE 255
#define MAX_GREEN 255
#define MIN_RED 0
#define MIN_BLUE 0
#define MIN_GREEN 0

typedef uint8_t cval;

class RGBTriple
{
    private:
        uint8_t r, g, b;
    public:
        RGBTriple() : r(0), g(0), b(0) {};
        RGBTriple(uint8_t _r, uint8_t _g, uint8_t _b) : r(_r), g(_g), b(_b) {};
        uint8_t getR() const;
        uint8_t getG() const;
        uint8_t getB() const;
};

struct ColorSetNode
{
    RGBTriple c;
    struct ColorSetNode* next;
};

/**
 * @brief Allocates memory on the heap and must be freed.
 * 
 * @return ColorSetNode* -- a linked list of colors representing the rainbow
 */
ColorSetNode* rainbowColors();
#endif