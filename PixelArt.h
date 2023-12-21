//#include <cstdint>
#ifndef _H_PIXELART_
#define _H_PIXELART_
#include <stdint.h>
#include <Color.h>
class PixelArt
{
    protected:
        int w, h;
        RGBTriple** colors;
    public:
        PixelArt(int w, int h) : w(w), h(h) {};
        virtual int getWidth() = 0;
        virtual int getHeight() = 0;
        virtual RGBTriple getPixel(int r, int c) = 0;
        virtual ~PixelArt() {};
};

class Art8x8 : public PixelArt
{
    public:
        // Art8x8(uint16_t c);
        // Art8x8(uint16_t** colors);
        Art8x8(RGBTriple** colors);
        Art8x8(RGBTriple colors[][8]);
        RGBTriple getPixel(int r, int c);
        int getWidth();
        int getHeight();
        ~Art8x8();

};
#endif