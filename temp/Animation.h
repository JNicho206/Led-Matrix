#ifndef _H_ANIMATION_
#define _H_ANIMATION_
#include <Pixel.h>
#include <Matrix.h>
class Animation 
{
    private:
        AnimationPixel*** state;
        MatrixSize size;
    
    public:
        Animation();
        ~Animation();
        void forward(Matrix& mat);
};

class AnimationPixel : Pixel
{
    public:
        AnimationPixel(pxind x, pxind y, RGBTriple c);
        virtual ~AnimationPixel();
        virtual AnimationPixelUpdate update() = 0;
};

class AnimationPixelUpdate 
{
    private: 
        MatrixPair p;
        RGBTriple c;
    
    public:
        AnimationPixelUpdate(pxind _x, pxind _y, RGBTriple _c);
        MatrixPair getPos() { return p; }
        pxind getX() { return p.col; }
        pxind getY() { return p.row; }
        RGBTriple getColor() { return c; }
};

class BlankPixel : AnimationPixel
{
    public:
        AnimationPixelUpdate update() override {};
        ~BlankPixel() {};
};

// class FireworkPixel : AnimationPixel
// {
//     private:
//         uint8_t lifespan, lifetime;
//     public:
//         AnimationPixelUpdate update() override;
//         FireworkPixel();
//         ~FireworkPixel();
// };

class RainbowPixel : AnimationPixel
{
    public:
        RainbowPixel(pxind x, pxind y) : AnimationPixel(x, y, RGBTriple()) {};
        AnimationPixelUpdate update() override;
}

#endif