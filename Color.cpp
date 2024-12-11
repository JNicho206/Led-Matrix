#include "Color.h"

uint8_t RGBTriple::getR() const {return r;}
uint8_t RGBTriple::getG() const {return g;}
uint8_t RGBTriple::getB() const {return b;}

// COLORSET CLASS METHODS

ColorSet::ColorSet() : colors(nullptr), size(0), max_size(5), iter_idx(0){};

ColorSet::ColorSet(RGBTriple* _c) : colors(_c), size(0) {};

ColorSet::ColorSet(ColorSetNode* _c) : colors(nullptr), size(0)
{
    // ColorSetNode* iter = _c;
    // while (iter != nullptr)
    // {
    //     size++;
    //     iter = iter->next;
    // }

    // c = new RGBTriple[size];
    // iter = _c;
    // for (uint16_t i = 0; i < size; i++)
    // {
    //     c[i] = iter->c;
    //     iter = iter->next;
    // }
}

ColorSet::~ColorSet()
{
    delete[] colors;
}

void ColorSet::addColor(const RGBTriple& _c)
{
    if (size == max_size) {
        max_size *= 2;
        RGBTriple* new_colors = new RGBTriple[max_size];
        for (uint16_t i = 0; i < size; i++)
        {
            new_colors[i] = colors[i];
        }
        delete[] colors;
        colors = new_colors;
    }
    if (colors == nullptr)
    {
        colors = new RGBTriple[max_size];
    }
    colors[size] = _c;
    size++;
}

RGBTriple ColorSet::getRandom() const
{
    return colors[random(0, size - 1)];
}

ColorSetNode* rainbowColors()
{
    ColorSetNode* head = new ColorSetNode;
    ColorSetNode* iter = head;
    iter->c = RGBTriple(255,0,0);
    iter->next = nullptr;

    uint8_t nvals = 11;
    uint8_t cvals[11] = {
        0, 25, 50, 75, 100, 125, 150,
        175, 200, 225, 255
    };

    //Red to yellow
    for (uint8_t i = 0; i < nvals; i++) 
    {
        iter->c = RGBTriple(255, cvals[i], 0);

        ColorSetNode* n = new ColorSetNode;
        iter->next = n;
        iter = n;
        iter->next = nullptr;
    }

    //Yellow to green
    for (uint8_t i = 0; i < nvals; i++) 
    {
        iter->c = RGBTriple(cvals[nvals - i - 1], 255, 0);

        ColorSetNode* n = new ColorSetNode;
        iter->next = n;
        iter = n;
        iter->next = nullptr;
    }

    //Green to cyan 
    for (uint8_t i = 0; i < nvals; i++) 
    {
        iter->c = RGBTriple(0, 255, cvals[i]);

        ColorSetNode* n = new ColorSetNode;
        iter->next = n;
        iter = n;
        iter->next = nullptr;
    }

    //Cyan to blue
    for (uint8_t i = 0; i < nvals; i++) 
    {
        iter->c = RGBTriple(0, cvals[nvals - i - 1], 255);

        ColorSetNode* n = new ColorSetNode;
        iter->next = n;
        iter = n;
        iter->next = nullptr;
    }

    //Blue to violet
    for (uint8_t i = 0; i < nvals; i++) 
    {
        iter->c = RGBTriple(cvals[i], 0, 255);

        ColorSetNode* n = new ColorSetNode;
        iter->next = n;
        iter = n;
        iter->next = nullptr;
    }

    //Violet to right before red
    for (uint8_t i = 0; i < nvals - 1; i++) 
    {
        iter->c = RGBTriple(255, 0, cvals[nvals - i - 1]);

        ColorSetNode* n = new ColorSetNode;
        iter->next = n;
        iter = n;
        iter->next = nullptr;
    }
    return head;
}

// COLOR CLASS METHODS

Color::Color() : base(RGBTriple(0,0,0)), brightness(1.0) {};

Color::Color(cval _r, cval _g, cval _b) : brightness(1.0)
{
    if (_r == 255 || _g == 255 || _b == 255)
    {
        base = RGBTriple(_r,_g,_b);
        Serial.print("Initializing Color with: ");
        Serial.print(_r); Serial.print(", ");
        Serial.print(_g); Serial.print(", ");
        Serial.println(_b);

        // Your existing code...
        Serial.print("Base color set to: ");
        Serial.print(base.getR()); Serial.print(", ");
        Serial.print(base.getG()); Serial.print(", ");
        Serial.println(base.getB());
        return;
    }

    uint8_t r,g,b;

    // If r is dominant
    if (_r > _g && _r > _b)
    {
        double rg = double(_r) / double(_g);
        double rb = double(_r) / double(_b);
        r = 255;
        b = 255.0 / rb;
        g = 255.0 / rg;
    }

    // If g is dominant
    else if (_g > _r && _g > _b)
    {
        double gr = double(_g) / double(r);
        double gb = double(_g) / double(_b);
        g = 255;
        r = 255.0 / gr;
        b = 255.0 / gb;
    }

    // If b is dominant
    else
    {
        double br = double(_b) / double(_r);
        double bg = double(_b) / double(_g);
        b = 255;
        r = 255.0 / br;
        g = 255.0 / bg;
    }
    base = RGBTriple(r,g,b);
}

RGBTriple Color::getRGB() const
{
    cval r = base.getR();
    cval g = base.getG();
    cval b = base.getB();
    return RGBTriple(uint8_t(r * getBrightness()), uint8_t(g * getBrightness()), uint8_t(b * getBrightness()));
}

double Color::getBrightness() const
{
    return brightness;
}

void Color::setBrightness(double _brightness)
{
    if (_brightness < 0)
    {
        brightness = 0.0;
        return;
    }
    if (_brightness > 1)
    { 
        brightness = 1.0;
        return;
    }
    brightness = _brightness;
}

void Color::increaseBrightness(double amount)
{
    if (brightness + amount > 1.0)
    {
        brightness = 1.0;
        return;
    }
    brightness += amount;
}

void Color::decreaseBrightness(double amount)
{
    if (brightness == 0.0) return;
    if (brightness - amount < 0.0)
    {
        brightness = 0.0;
        return;
    }
    brightness -= amount;
}

// COLORS CLASS METHODS

Colors::Colors() : colors(nullptr), size(0), max_size(5), iter_idx(0){};

void Colors::addColor(const Color& _c)
{
    if (colors == nullptr)
    {
        colors = new Color[max_size];
    }
    if (size == max_size) {
        max_size *= 2;
        Color* new_colors = new Color[max_size];
        for (uint16_t i = 0; i < size; i++)
        {
            new_colors[i] = colors[i];
        }
        delete[] colors;
        colors = new_colors;
    }
    colors[size] = _c;
    size++;
}

Color Colors::getRandom() const
{
    return colors[random(0, size - 1)];
}

void Colors::iter_next()
{
    iter_idx = (iter_idx + 1) % size;
}

Color Colors::iter_get(bool inc_iter = true) const
{
    if (inc_iter) iter_next();
    return colors[iter_idx];
}


// RGBTRIPLE CLASS METHODS

RGBTriple randomRGB()
{
    return RGBTriple(random(0, 255), random(0, 255), random(0, 255));
}


RGBTriple hsv2rgb(uint16_t h, uint8_t s, uint8_t v)
{
    uint8_t region, remainder, p, q, t;

    cval r, g, b;
    if (s == 0) {
        // If the saturation is 0, the color is a shade of gray (no hue)
        r = v;
        g = v;
        b = v;
        return;
    }

    region = h / 43;  // Divide hue by 43 to get the region (6 regions)
    remainder = (h - (region * 43)) * 6;  // Modulo operation within the region

    p = (v * (255 - s)) >> 8;
    q = (v * (255 - ((s * remainder) >> 8))) >> 8;
    t = (v * (255 - ((s * (255 - remainder)) >> 8))) >> 8;

    // Assign RGB based on the region
    switch (region) {
        case 0:
            r = v; g = t; b = p;
            break;
        case 1:
            r = q; g = v; b = p;
            break;
        case 2:
            r = p; g = v; b = t;
            break;
        case 3:
            r = p; g = q; b = v;
            break;
        case 4:
            r = t; g = p; b = v;
            break;
        default:
            r = v; g = p; b = q;
            break;
    }
    return RGBTriple(r, g, b);
}

void RGBTriple::dim(uint8_t amount) 
{
    if (amount == 0) return;
    if (r == g && r == b) // Color is white
    {
        if (amount > r)
        {
            r = 0; b = 0; g = 0;
            return;
        }
        r -= amount;
        g -= amount;
        b -= amount;
        return;
    }
    // If r is dominant
    if (r > g && r > b)
    {
        double rg = double(r) / double(g);
        double rb = double(r) / double(b);
        r -= amount;
        b -= double(amount) * rb;
        g -= double(amount) * rg;
    }
    // If g is dominant
    else if (g > r && g > b)
    {
        double gr = double(g) / double(r);
        double gb = double(g) / double(b);
        g -= amount;
        r -= double(amount) * gr;
        b -= double(amount) * gb;
    }
    // If b is dominant
    else
    {
        double br = double(b) / double(r);
        double bg = double(b) / double(g);
        b -= amount;
        r -= double(amount) * br;
        g -= double(amount) * bg;
    }

}

void RGBTriple::brighten(uint8_t amt)
{
    if (r == g && r == b) // Color is black
    {
        if (r + 1 > 255)
        {
            r = 255; b = 255; g = 255;
            return;
        }
        r += 1;
        g += 1;
        b += 1;
        return;
    }
    // If r is dominant
    if (r > g && r > b)
    {
        double rg = double(r) / double(g);
        double rb = double(r) / double(b);
        r += 1;
        b += rb;
        g += rg;
    }
    // If g is dominant
    else if (g > r && g > b)
    {
        double gr = double(g) / double(r);
        double gb = double(g) / double(b);
        g += 1;
        r += gr;
        b += gb;
    }
    // If b is dominant
    else
    {
        double br = double(b) / double(r);
        double bg = double(b) / double(g);
        b += 1;
        r += br;
        g += bg;
    }
}

// If r is max
//

RGBTriple scale(const RGBTriple& c, float ratio)
{
    uint8_t r = c.getR();
    uint8_t g = c.getG();
    uint8_t b = c.getB();

    uint8_t new_r, new_g, new_b;

    uint8_t dif;
    if (r > g && r > b)
    {
        dif = 255 - r;
        new_r; 
    }
    else if (g > r && g > b)
    {
        dif = 255 - g;
    }
    else
    {
        dif = 255 - b;
    }



    return RGBTriple(c.getR() * ratio, c.getG() * ratio, c.getB() * ratio);
}