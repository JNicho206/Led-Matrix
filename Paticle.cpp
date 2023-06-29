#include <Particle.h>


Particle::Particle() : speed(1), pos(random(8)), lifetime(2) {
    color.red = random(256);
    color.blue = random(256);
    color.green = random(256);

}

Particle::Particle(int r, int g, int b, int p, int spd, int lifetm)
    : pos(p), speed(spd), lifetime(lifetm)
{
    color.red = r;
    color.blue = b;
    color.green = g;
}

void Particle::initPos(int origin, Matrix m)
{
    
    m.drawPixel()
}

void Particle::setColor(Color c)
{
    color.red = c.red;
    color.blue = c.blue;
    color.green = c.green;
}

int Particle::move() {

    if (this->done())
    {   
        return 1;
    }
    else 
    {

        lifetime--;
        return 0;
    }
}

bool Particle::done() 
{
    return lifetime >= 0 ? false : true;
}

void Particle::setPos(int p)
{   

}