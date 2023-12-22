#ifndef _H_MATRIX_
#define _H_MATRIX
#include <Adafruit_NeoMatrix.h>
#include <PixelArt.h>

#define UPLEFT 0
#define UP 1
#define UPRIGHT 2
#define RIGHT 3
#define DOWNRIGHT 4
#define DOWN 5
#define DOWNLEFT 6
#define LEFT 7

struct MatrixPair
{
    uint8_t row, col;
    MatrixPair(uint8_t r, uint8_t c) : row(r), col(c) {};
};

class Matrix {
    private:
        Adafruit_NeoMatrix *matrix;
    public:
        Matrix(uint16_t w, uint16_t h, uint8_t pin);
        void drawPixelArt(const PixelArt& art);
        int adjacent(int origin, int direction);
        bool isEdge(int row, int col, int direction);
        ~Matrix();
        void clear();
        void show();
        void setBrightness(uint8_t);
        void begin();
        uint8_t toSingle(const MatrixPair& p);
        MatrixPair toPair(uint8_t);
        void setPixel(uint8_t n, uint32_t c);
        void setPixel(uint8_t n, uint8_t r, uint8_t g, uint8_t b);
        void drawRainbow(uint16_t totalTime, uint16_t delay);
        void drawTree();
        void fireworks();
};
#endif