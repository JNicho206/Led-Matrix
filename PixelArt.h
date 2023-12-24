//#include <cstdint>
#ifndef _H_PIXELART_
#define _H_PIXELART_
#include <stdint.h>
#include <Color.h>
#include <Pixel.h>
class PixelArt
{
    protected:
        int w, h;
        Pixel** pxmap;
    public:
        PixelArt(int w, int h) : w(w), h(h) {};
        virtual int getWidth() = 0;
        virtual int getHeight() = 0;
        virtual RGBTriple getPixelColor(uint8_t r, uint8_t c) = 0;
        virtual Pixel getPixel(uint8_t r, uint8_t c);
        virtual ~PixelArt() {};
};

class Art8x8 : public PixelArt
{
    public:
        // Art8x8(uint16_t c);
        // Art8x8(uint16_t** colors);
        Art8x8(RGBTriple** colors);
        Art8x8(RGBTriple colors[][8]);
        Pixel getPixel(uint8_t r, uint8_t c) override;
        RGBTriple getPixelColor(uint8_t r, uint8_t c) override;
        int getWidth() override;
        int getHeight() override;
        virtual ~Art8x8();

};
#endif