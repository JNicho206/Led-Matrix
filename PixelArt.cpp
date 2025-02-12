#include "PixelArt.h"

// Art8x8::Art8x8(uint16_t c) : PixelArt(8,8)
// {
//     colors = new uint16_t*;
//     for (int i = 0; i < h; i++)
//     {
//         colors[i] = new uint16_t;
//         for (int j = 0; j < w; j++)
//         {
//             colors[i][j] = c;
//         }
//     }
// }

// Art8x8::Art8x8(uint16_t** _colors) : PixelArt(8,8)
// {
//     colors = new uint16_t*;
//     for (int i = 0; i < h; i++)
//     {
//         colors[i] = new uint16_t;
//         for (int j = 0; j < w; j++)
//         {
//             colors[i][j] = _colors[i][j];
//         }
//     }
// }

Art8x8::Art8x8(RGBTriple** c) : PixelArt(8,8)
{
    pxmap = new Pixel*[8];
    for (int i = 0; i < 8; i++)
    {
        pxmap[i] = new Pixel[8];
        for (int j = 0; j < 8; j++)
        {
            pxmap[i][j] = Pixel(i, j, c[i][j]);
        }
    }
}

Art8x8::Art8x8(RGBTriple c[][8]) : PixelArt(8,8)
{
    pxmap = new Pixel*[8];
    for (int i = 0; i < 8; i++)
    {
        pxmap[i] = new Pixel[8];
        for (int j = 0; j < 8; j++)
        {
            pxmap[i][j] = Pixel(i, j, c[i][j]);
        }
    }
}

RGBTriple Art8x8::getPixelColor(uint8_t r, uint8_t c) const
{
    return pxmap[r][c].getRGB();
}

Pixel Art8x8::getPixel(uint8_t r, uint8_t c)
{
    return pxmap[r][c];
}

int Art8x8::getHeight()
{
    return h;
}

int Art8x8::getWidth()
{
    return w;
}

Art8x8::~Art8x8()
{
    for (int i = 0; i < w; i++)
    {
        delete pxmap[i];
    }
    delete pxmap;
}