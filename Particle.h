#include <Color.h>
#include <Matrix.h>



class Particle {
    public:
        Particle();
        Particle(int r, int g, int b, int pos, int speed, int lifetime);
        void setColor(Color c);
        int move();
        void initPos(int origin, Matrix m);
        
    private:
        int speed;
        int pos;
        int lifetime;
        int* momentum = new int[2];
        Color color;
        void setPos(int p);
        bool done();

};