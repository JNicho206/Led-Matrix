#include <Color.h>
#include <Particle.h>

class Firework {
    private:
        int pos;
        int height;
        Color* colors;
        int num_colors;
        int num_particles;
        Particle* particles;
        int particle_speed;
        int speed;
        int size;
        bool exploded;
        void explode();
        int update_particles();

    public:
        Firework();
        Firework(int pos, int height, int speed, int size, int num_particles, int particle_speed, Color* colors, int num_colors);
        ~Firework();
        int move();
        bool done();
};