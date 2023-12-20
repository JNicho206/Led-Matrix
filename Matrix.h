#include <Adafruit_NeoMatrix.h>
#include <Color.h>
#include <PixelArt.h>

#define UPLEFT 0
#define UP 1
#define UPRIGHT 2
#define RIGHT 3
#define DOWNRIGHT 4
#define DOWN 5
#define DOWNLEFT 6
#define LEFT 7

class Matrix : public Adafruit_NeoMatrix {
    private:
        Adafruit_NeoMatrix *matrix;
    public:
        Matrix(uint16_t w, uint16_t h, uint8_t pin);
        void drawPixelArt(const PixelArt& art);
        int adjacent(int origin, int direction);
        bool isEdge(int row, int col, int direction);
        ~Matrix();
};