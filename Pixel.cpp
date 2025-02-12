#include <Pixel.h>

// PIXEL CLASS METHODS

RGBTriple Pixel::getRGB()
{
    return rgb;
}

// PIXELSET CLASS METHODS

PixelSet::PixelSet(MatrixPair* locations, uint8_t _num) : num(_num)
{
    for (uint8_t i = 0; i < _num; i++)
    {
        px[i] = Pixel(locations[i].row, locations[i].col, RGBTriple(255,0,0));
    }
}

// PARTICLEOFFSET CLASS METHODS

ParticleOffset rand_offset()
{
    uint8_t choice = random(0, 7);

    switch (choice)
    {
        case 0:
            return OFFSET_TL;
        case 1:
            return OFFSET_T;
        case 2:
            return OFFSET_TR;
        case 3:
            return OFFSET_R;
        case 4:
            return OFFSET_BR;
        case 5:
            return OFFSET_B;
        case 6:
            return OFFSET_BL;
        case 7:
            return OFFSET_L;
    }
}

uint8_t ParticleOffset::adj_n()
{
    // TL
    if (x == -1 && y == 1)
    {
        return 0;
    }
    // T
    if (x == 0 && y == 1)
    {
        return 1;
    }
    // TR
    if (x == 1 && y == 1)
    {
        return 2;
    }
    // R
    if (x == 1 && y == 0)
    {
        return 3;
    }
    // BR
    if (x == 1 && y == -1)
    {
        return 4;
    }
    // B
    if (x == 0 && y == -1)
    {
        return 5;
    }
    // BL
    if (x == -1 && y == -1)
    {
        return 6;
    }
    // L
    if (x == -1 && y == 0)
    {
        return 7;
    }
}

// LIGHT CLASS METHODS

Light::Light() : Pixel(0,0, RGBTriple(255,255,255)), increasing(true), ttl(0), color(Color(255,255,255)) {};

Light::Light(pxind _x, pxind _y, Color _c, ttl_t _ttl) : Pixel(_x, _y, _c.getBaseRGB()), increasing(true), ttl(_ttl), color(_c) {};

void Light::incBrightness(double n)
{
    color.increaseBrightness(n);
}

void Light::decBrightness(double n)
{
    color.decreaseBrightness(n);
}

void Light::setBrightness(double n)
{
    color.setBrightness(n);
}

// PARTICLE CLASS METHODS

Particle::Particle() : Light(0,0, Color(), 0), dx(0), dy(0) {}

Particle::Particle(pxind _x, pxind _y, RGBTriple _rgb, ttl_t _ttl, uint8_t _dx, uint8_t _dy)
 : Light(_x, _y, Color(_rgb.getR(), _rgb.getG(), _rgb.getB()), _ttl),
    dx(_dx), dy(_dy)
{
}

Particle::Particle(pxind _x, pxind _y, cval _r, cval _g, cval _b, ttl_t _ttl, uint8_t _dx, uint8_t _dy)
 : Light(_x, _y, Color(_r, _g, _b), _ttl),
    dx(_dx), dy(_dy)
{

}

void Particle::step(bool update_ttl = true)
{
    setX(getX() + getDX());
    setY(getY() + getDY());

    if (update_ttl) tick();
}

// FIREWORKBASE CLASS METHODS

FireworkBase::FireworkBase(pxind _x, pxind _y, RGBTriple _color, ttl_t _ttl, uint8_t _dx, uint8_t _dy) 
 : Particle(_x, _y, _color, _ttl, _dx, _dy)
{}

bool FireworkBase::exploded()
{
    return ttl == 0;
}

bool FireworkBase::exp_offset_used(ParticleOffset& o)
{
    return (exp_offsets_used >> (o.adj_n() - 1)) & 1;
}

void FireworkBase::toggle_offset(ParticleOffset& o)
{
    uint8_t OFFSET_SHIFT = o.adj_n() - 1;
    exp_offsets_used |= 1 << OFFSET_SHIFT;
}

Particle FireworkBase::from_offset(ParticleOffset& o)
{
    pxind new_x = this->getX() + o.getX();
    pxind new_y = this->getY() + o.getY();
    RGBTriple new_c = this->getRGB();
    uint8_t new_dx = o.getX();
    uint8_t new_dy = o.getY();
    ttl_t new_ttl = 3;

    Particle p = Particle(new_x, new_y, new_c, new_ttl, new_dx, new_dy);
    return p;
}

Particle* FireworkBase::generate_explosion(uint8_t num_particles)
{
    if (num_particles > 8) num_particles = 8;

    Particle* particles = new Particle[num_particles];

    while (num_particles)
    {
        ParticleOffset offset = rand_offset();
        // while (!exp_offset_used(offset)) {offset = rand_offset();}
        // toggle_offset(offset);

        Particle p = from_offset(offset);
        particles[--num_particles] = p; 
    }

    return particles;
}

