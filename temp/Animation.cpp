#include <Animation.h>

Animation::Animation(MatrixSize s)
{
    size = s;
    state = new AnimationPixel*[s.h];
    for (int r = 0; r < s.h; i++)
    {
        state[r] = new AnimationPixel[s.w];
        for (int c = 0; c < s.w; c++)
        {
            state[r][c] = new AnimationPixel;
        }
    }
}

Animation::~Animation()
{
    for (int r = 0; r < size.h; r++)
    {
        for (int c = 0; c < size.w)
        {
            delete state[r][c];
        }
        delete [] state[r];
    }
    delete state;
}

AnimationPixel::AnimationPixel(pxind x, pxind y, RGBTriple c) : Pixel(x,y,c) 
{

}

Animation::~Animation() {}

void Animation::forward(Matrix& mat) 
{
    mat.clear();
    for (int x = 0; x < size.w; x++)
    {
        for (int y = 0; y < size.h; y++)
        {
            AnimationPixelUpdate updte = state[x][y].update();
            mat.updatePixel(updte);
        }
    }
}

// AnimationPixelUpdate FireworkPixel::update() override
// {

// }

AnimationPixelUpdate RainbowPixel::update() override 
{
    return AnimationPixelUpdate(getX(), getY(), RGBTriple(random(0, 200), random(0,200), random(0,200)));
}