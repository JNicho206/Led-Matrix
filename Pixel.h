#ifndef _H_PIXEL_
#define _H_PIXEL_
#include <stdint.h>
#include <Color.h>

typedef uint8_t pxind;

class Pixel
{
    protected:
        uint8_t x,y;
        RGBTriple color;
    
    public:
        Pixel() : x(0), y(0), color(RGBTriple()) {};
        Pixel(pxind _x, pxind _y, RGBTriple _c) : x(_x), y(_y), color(_c) {};
        Pixel(pxind _x, pxind _y, cval r, cval g, cval b) : x(_x), y(_y), color(RGBTriple(r,g,b)) {};
        virtual RGBTriple getRGB(pxind r, pxind c);
        uint8_t getX() { return x; }
        uint8_t getY() { return y; }
};

class Particle : Pixel
{
    private:
        uint8_t counter;
    public:
        Particle(pxind x, pxind y, RGBTriple color);
        Particle(pxind x, pxind y, cval r, cval g, cval b);
};



#endif