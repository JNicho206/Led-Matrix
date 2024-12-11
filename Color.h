#ifndef _H_COLOR_
#define _H_COLOR_
#include <stdint.h>
#include <Arduino.h>
#define MAX_RED 255
#define MAX_BLUE 255
#define MAX_GREEN 255
#define MIN_RED 0
#define MIN_BLUE 0
#define MIN_GREEN 0

typedef uint8_t cval;

class RGBTriple
{
    private:
        cval r, g, b;
    public:
        RGBTriple() : r(0), g(0), b(0) {};
        RGBTriple(uint8_t _r, uint8_t _g, uint8_t _b) : r(_r), g(_g), b(_b) {};
        uint8_t getR() const;
        uint8_t getG() const;
        uint8_t getB() const;
        double getRGRatio() const { return double(r) / double(g); };
        double getRBRatio() const { return double(r) / double(b); };
        double getGBRatio() const { return double(g) / double(b); };
        double getGRRatio() const { return double(g) / double(r); };
        double getBRRatio() const { return double(b) / double(r); };
        double getBGRatio() const { return double(b) / double(g);  };

        void dim(uint8_t amount);
        void brighten(uint8_t amount);
};

class Color
{
    private:
        RGBTriple base;
        double brightness;
    
    public:
        Color();
        Color(cval _r, cval _g, cval _b);
        RGBTriple getRGB() const;
        double getBrightness() const;
        void increaseBrightness(double amount);
        void decreaseBrightness(double amount);
        void setBrightness(double percent);
        RGBTriple getBaseRGB() const { return base; };
};

class Colors
{
    private:
        Color* colors;
        uint16_t size;
        uint16_t max_size;
        uint16_t iter_idx;

    public:
        Colors();
        ~Colors() { if (colors != nullptr) delete[] colors; };
        void addColor(const Color& _c);
        Color getRandom() const;
        void iter_next();
        Color iter_get(bool inc_iter = true) const;
};

struct ColorSetNode
{
    RGBTriple c;
    struct ColorSetNode* next;
};

/**
 * @brief Allocates memory on the heap and must be freed.
 * 
 * @return ColorSetNode* -- a linked list of colors representing the rainbow
 */
ColorSetNode* rainbowColors();

class ColorSet {
    /**
     * @brief 
     * 
     */

    private:
        RGBTriple* colors;
        uint16_t size;
        uint16_t max_size;
        uint16_t iter_idx;

    public:
        ColorSet();
        ColorSet(RGBTriple* _c);
        ColorSet(ColorSetNode* _c);
        ~ColorSet();
        void iter_next() { iter_idx = (iter_idx + 1) % size; }
        RGBTriple iter_get(bool inc_iter = true) const { return colors[iter_idx]; }
        void addColor(const RGBTriple& _c);
        RGBTriple* getColors() const;
        RGBTriple getRandom() const;
};


RGBTriple randomRGB();
RGBTriple hsv2rgb(uint16_t h, uint8_t s, uint8_t v);
RGBTriple scale(RGBTriple c, float ratio);


#endif