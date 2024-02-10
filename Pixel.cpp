#include <Pixel.h>

Particle::Particle(pxind _x, pxind _y, RGBTriple _color, ttl_t _ttl, uint8_t _dx, uint8_t _dy)
 : Pixel(_x, _y, _color),
    dx(_dx), dy(_dy), ttl(_ttl)
{

}

Particle::Particle(pxind _x, pxind _y, cval _r, cval _g, cval _b, ttl_t _ttl, uint8_t _dx, uint8_t _dy)
 : Pixel(_x, _y, _r, _g, _b),
    dx(_dx), dy(_dy), ttl(_ttl)
{

}

void Particle::step(bool update_ttl = true)
{
    setX(getX() + getDX());
    setY(getY() + getDY());

    if (update_ttl) tick();
}

RGBTriple Pixel::getRGB()
{
    return color;
}

FireworkBase::FireworkBase(pxind _x, pxind _y, RGBTriple _color, ttl_t _ttl, uint8_t _dx, uint8_t _dy) 
 : Particle(_x, _y, _color, _ttl, _dx, _dy)
{

}

bool FireworkBase::exploded()
{
    return ttl == 0;
}

Particle* FireworkBase::generate_explosion(uint8_t num_particles)
{
    
}