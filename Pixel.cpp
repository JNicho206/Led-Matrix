#include <Pixel.h>

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

Particle::Particle() : Pixel(0,0, RGBTriple(0,0,0)), dx(0), dy(0), ttl(0) {}

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
        while (!exp_offset_used(offset)) {offset = rand_offset();}
        toggle_offset(offset);

        Particle p = from_offset(offset);
        particles[num_particles--] = p; 
    }

    return particles;
}

uint8_t ParticleOffset::adj_n()
{
    // TL
    if (x == -1 && y == 1)
    {
        return 1;
    }
    // T
    if (x == 0 && y == 1)
    {
        return 2;
    }
    // TR
    if (x == 1 && y == 1)
    {
        return 3;
    }
    // R
    if (x == 1 && y == 0)
    {
        return 4;
    }
    // BR
    if (x == 1 && y == -1)
    {
        return 5;
    }
    // B
    if (x == 0 && y == -1)
    {
        return 6;
    }
    // BL
    if (x == -1 && y == -1)
    {
        return 7;
    }
    // L
    if (x == -1 && y == 0)
    {
        return 8;
    }
    return 0;
}