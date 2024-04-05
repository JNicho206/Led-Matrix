#ifndef _H_PIXEL_
#define _H_PIXEL_
#include <stdint.h>
#include <Color.h>
#include "Arduino.h"
#include "Pair.h"


typedef uint8_t pxind;
typedef uint8_t ttl_t;

#define OFFSET_TL ParticleOffset(-1, 1);
#define OFFSET_T ParticleOffset(0, 1);
#define OFFSET_TR ParticleOffset(1, 1);
#define OFFSET_R ParticleOffset(1, 0);
#define OFFSET_BR ParticleOffset(1, -1);
#define OFFSET_B ParticleOffset(0, -1);
#define OFFSET_BL ParticleOffset(-1, -1);
#define OFFSET_L ParticleOffset(-1, 0);


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

// TODO Minimize Pixelset
class PixelSet
{
    private:
        uint8_t num;
    
    public:
        Pixel* px;
        PixelSet(MatrixPair *locations, uint8_t num);
        uint8_t get_num() { return num; }
};

class ParticleOffset
{
    private:
        int8_t x,y;
    public:
        ParticleOffset(int8_t _x, int8_t _y) : x(_x), y(_y) {};
        uint8_t adj_n();
        int8_t getX() { return x; }
        int8_t getY() { return y; }

};

class Particle : public Pixel
{
    protected:
        ttl_t ttl;
        uint8_t dx;
        uint8_t dy;
    public:
        Particle();
        Particle(pxind x, pxind y, RGBTriple color, ttl_t ttl, uint8_t dx, uint8_t dy);
        Particle(pxind x, pxind y, cval r, cval g, cval b, ttl_t ttl, uint8_t dx, uint8_t dy);
        uint8_t getDX() { return dx; }
        uint8_t getDY() { return dy; }
        void setDX(uint8_t _dx) { dx = _dx; }
        void setDY(uint8_t _dy) { dy = _dy; }
        void tick() { ttl--; }
        void step(bool update_ttl = true);
        ttl_t getTTL() { return ttl; }

};

class FireworkBase : public Particle
{   
    private:
        uint8_t exp_offsets_used = 0;
    public:
        FireworkBase(pxind x, pxind y, RGBTriple color, ttl_t ttl, uint8_t dx, uint8_t dy);
        bool exploded();
        Particle* generate_explosion(uint8_t num_particles);
        void toggle_offset(ParticleOffset& o);
        bool exp_offset_used(ParticleOffset& o);
        Particle from_offset(ParticleOffset& o);

};


#endif