#include <Firework.h>

Firework::Firework() {

}

Firework::Firework(int p, int h, int spd, int sz, int num_p, int p_spd, Color* cls, int num_c) 
    :  pos(p), height(h), speed(spd), size(sz), num_particles(num_p), colors(nullptr), 
    particles(nullptr), particle_speed(p_spd), exploded(false), num_colors(num_c) {
}

Firework::~Firework() {
    if (particles != nullptr)
    {
        delete[] particles;
    }
}

int Firework::move()
{
    if (exploded)
    {
        if (this->update_particles() == 0) 
        {
            return -1;
        }
    }
    else if (pos >= height)
    {
        explode();
        return 1;
    }
}

void Firework::explode() {
    exploded = true;
    particles = new Particle[num_particles];
    
    if (num_colors == 1) {
        for (int i = 0; i < num_particles; i++)
        {
            particles[i].setColor(colors[0]);
            particles[i].initPos(pos);

        }
    }
}

int Firework::update_particles()
{
    int n = num_particles;
    bool done;
    for (int i = 0; i < num_particles; i++)
    {
       done = particles[i].move();
       if (done) {
         num_particles--; 
       }   
    }
    return num_particles; 
}