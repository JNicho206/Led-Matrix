#ifndef _H_PIXEL_
#define _H_PIXEL_
#include <stdint.h>
#include <Color.h>

typedef uint8_t pxind;
typedef uint8_t ttl_t;

class Pixel
{
    protected:
        uint8_t x,y;
        RGBTriple color;
    
    public:
        Pixel() : x(0), y(0), color(RGBTriple()) {};
        Pixel(pxind _x, pxind _y, RGBTriple _c) : x(_x), y(_y), color(_c) {};
        Pixel(pxind _x, pxind _y, cval _r, cval _g, cval _b) : x(_x), y(_y), color(RGBTriple(_r,_g,_b)) {};
        RGBTriple getRGB();
        void setX(pxind _x) { x = _x; }
        void setY(pxind _y) { y = _y; }
        uint8_t getX() { return x; }
        uint8_t getY() { return y; }
};

class Particle : Pixel
{
    protected:
        ttl_t ttl;
        uint8_t dx;
        uint8_t dy;
    public:
        Particle(pxind x, pxind y, RGBTriple color, ttl_t ttl, uint8_t dx, uint8_t dy);
        Particle(pxind x, pxind y, cval r, cval g, cval b, ttl_t ttl, uint8_t dx, uint8_t dy);
        uint8_t getDX() { return dx; }
        uint8_t getDY() { return dy; }
        void setDX(uint8_t _dx) { dx = _dx; }
        void setDY(uint8_t _dy) { dy = _dy; }
        void tick() { ttl--; }
        void step(bool update_ttl = true);

};

class FireworkBase: Particle
{   
    public:
        FireworkBase(pxind x, pxind y, RGBTriple color, ttl_t ttl, uint8_t dx, uint8_t dy);
        bool exploded();
        Particle* generate_explosion(uint8_t num_particles);

};


#endif