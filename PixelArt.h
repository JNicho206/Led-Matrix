#include <cstdint>

class PixelArt
{
    protected:
        int w, h;
        uint16_t** colors;
    public:
        PixelArt(int w, int h) : w(w), h(h);
        virtual int getWidth() = 0;
        virtual int getHeight() = 0;
        virtual int getPixel() = 0;
        virtual ~PixelArt() = 0;
}

class Art8x8 : public PixelArt
{
    public:
        Art8x8(uint16_t c);
        Art8x8(uint16_t** colors);
        int getPixel(int r, int c);
        int getWidth();
        int getHeight();
        ~Art8x8();

}