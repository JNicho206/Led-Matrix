#ifndef _H_MATRIX_
#define _H_MATRIX_
#include <Adafruit_NeoMatrix.h>
#include <PixelArt.h>
#include "Pixel.h"
#include "Color.h"
#include "Arduino.h"
#include "Pair.h"
#include <FastLED.h>
// #include <Animation.h>

#define UPLEFT 0
#define UP 1
#define UPRIGHT 2
#define RIGHT 3
#define DOWNRIGHT 4
#define DOWN 5
#define DOWNLEFT 6
#define LEFT 7


class Matrix {
    private:
        Adafruit_NeoMatrix *matrix;
        uint16_t width;
        uint16_t height;
        void _setPixel(uint8_t n, RGBTriple c);
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
        void fillScreen(uint16_t c);
        void setCursor(int x, int y);
        void setTextWrap(bool b);
        void print(const __FlashStringHelper * f);
        uint8_t toSingle(const MatrixPair& p);
        uint8_t toSingle(pxind x, pxind y);
        MatrixPair toPair(uint8_t);
        void setPixel(uint8_t n, uint32_t c);
        void setPixel(uint8_t n, uint8_t r, uint8_t g, uint8_t b);
        void setPixel(uint8_t n, RGBTriple c);
        void setPixel(uint16_t n, Color c);
        void setPixel(uint8_t n, Pixel p);
        void setPixel(uint8_t row, uint8_t col, uint32_t c);
        void setPixel(uint8_t row, uint8_t col, uint8_t r, uint8_t g, uint8_t b);
        void setPixel(uint8_t row, uint8_t col, RGBTriple c);
        void drawPixel(Pixel& p);
        void drawPixel(Pixel& p, RGBTriple c);
        void drawPixelSet(PixelSet& set);
        void drawPixelSet(MatrixPair* locations, uint8_t n, RGBTriple c);
        void drawRainbow(uint16_t totalTime, uint16_t delay);
        void drawRainbow();
        void drawTree();
        void fireworks();
        void rainbowGrad(uint8_t iterations);
        void drawParticle(Particle& p);
        void drawLight(Light& l);
        void sparseLights(Colors& colors);
        void sparseLights(void);
        void plasma(uint16_t time);
        // void updatePixel(AnimationPixelUpdate pxUpdate);
};
#endif