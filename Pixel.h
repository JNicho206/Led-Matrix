#ifndef _H_PIXEL_
#define _H_PIXEL_
#include <stdint.h>
#include <Color.h>

class Pixel
{
    protected:
        uint8_t x,y;
        RGBTriple color;
    
    public:
        Pixel() : x(0), y(0), color(RGBTriple()) {};
        Pixel(uint8_t _x, uint8_t _y, RGBTriple _c) : x(_x), y(_y), color(_c) {};
        Pixel(uint8_t _x, uint8_t _y, uint8_t r, uint8_t g, uint8_t b) : x(_x), y(_y), color(RGBTriple(r,g,b)) {};
        virtual RGBTriple getRGB(uint8_t r, uint8_t c);
};

class Particle : Pixel
{
    private:
        uint8_t counter;
    public:
        Particle(uint8_t x, uint8_t y, RGBTriple color);
        Particle(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b);
}

#endif