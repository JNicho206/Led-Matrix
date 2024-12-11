#ifndef _H_PIXEL_
#define _H_PIXEL_
#include <stdint.h>
#include <Color.h>
#include "Arduino.h"
#include "Pair.h"


typedef uint8_t pxind;
typedef uint32_t ttl_t;

#define OFFSET_TL ParticleOffset(-1, 1);
#define OFFSET_T ParticleOffset(0, 1);
#define OFFSET_TR ParticleOffset(1, 1);
#define OFFSET_R ParticleOffset(1, 0);
#define OFFSET_BR ParticleOffset(1, -1);
#define OFFSET_B ParticleOffset(0, -1);
#define OFFSET_BL ParticleOffset(-1, -1);
#define OFFSET_L ParticleOffset(-1, 0);


/**
 * @brief Pixels are leds with static brightness and position 
 * 
 */
class Pixel
{
    protected:
        uint8_t x,y;
        RGBTriple rgb;
    
    public:
        Pixel() : x(0), y(0), rgb(RGBTriple()) {};
        Pixel(pxind _x, pxind _y, RGBTriple _c) : x(_x), y(_y), rgb(_c) {};
        Pixel(pxind _x, pxind _y, cval _r, cval _g, cval _b) : x(_x), y(_y), rgb(RGBTriple(_r,_g,_b)) {};
        RGBTriple getRGB();
        void setRGB(RGBTriple c) { rgb = c; };
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

/**
 * @brief Light class extends Pixel, adding brightness (via Color), ttl, a boolean for increasing brightness
 * 
 */
class Light : public Pixel {
    protected:
        bool increasing;
        ttl_t ttl;
        Color color;
    public:
        Light();
        Light(pxind x, pxind y, Color c, ttl_t ttl);
        void setInc(bool v) { increasing = v; }
        bool getInc() { return increasing; }
        void setBrightness(double b);
        void setBrightness();
        void incBrightness(double n);
        void decBrightness(double n);
        double getBrightness() { return color.getBrightness(); };
        ttl_t getTTL() { return ttl; };
        void setTTL(ttl_t t) { ttl = t; };
        Color getColor() { return color; };
        void setColor(Color c) { color = c; };
        RGBTriple getRGB() { return color.getRGB(); } const;
        void step(bool update_ttl = true);
        void tick() { ttl--; };
};

/**
 * @brief Particle class extends Light, adding dx and dy.
 * 
 */
class Particle : public Light
{
    protected:
        uint8_t dx;
        uint8_t dy;
    public:
        Particle();
        Particle(pxind x, pxind y, RGBTriple rgb, ttl_t ttl, uint8_t dx, uint8_t dy);
        Particle(pxind x, pxind y, cval r, cval g, cval b, ttl_t ttl, uint8_t dx, uint8_t dy);
        uint8_t getDX() { return dx; }
        uint8_t getDY() { return dy; }
        void setDX(uint8_t _dx) { dx = _dx; }
        void setDY(uint8_t _dy) { dy = _dy; }
        void step(bool update_ttl = true);

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