#include "PixelArt.h"

Art8x8::Art8x8(uint16_t c) : PixelArt(8,8)
{
    colors = new uint16_t*;
    for (int i = 0; i < h; i++)
    {
        colors[i] = new uint16_t;
        for (int j = 0; j < w; j++)
        {
            colors[i][j] = c;
        }
    }
}

Art8x8::Art8x8(uint16_t** _colors) : PixelArt(8,8)
{
    colors = new uint16_t*;
    for (int i = 0; i < h; i++)
    {
        colors[i] = new u_int16_t;
        for (int j = 0; j < w; j++)
        {
            colors[i][j] = _colors[i][j];
        }
    }
}

int Art8x8::getPixel(int r, int c)
{
    if (r >= h || r < 0 || c >= w || c < 0) { return -1; }
    return colors[r][c];
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
        delete colors[i];
    }
    delete colors;
}