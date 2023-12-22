#include <Pixel.h>

Particle::Particle(uint8_t x, uint8_t y, RGBTriple color) : Pixel(x, y, color)
{

}

Particle::Particle(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b) : Pixel(x, y, r, g, b)
{

}

RGBTriple Pixel::getRGB(uint8_t r, uint8_t c)
{
    return color;
}