#include "Adafruit_NeoMatrix/Adafruit_NeoMatrix.h"
#include <Color.h>

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
        
    public:
        Matrix(uint16_t w, uint16_t h, uint8_t pin, neoPixelType type)
        : Adafruit_NeoMatrix(w, h, pin, type) {}

};