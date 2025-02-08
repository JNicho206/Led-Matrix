// Adafruit_NeoMatrix example for single NeoPixel Shield.
// Scrolls 'Howdy' across the matrix in a portrait (vertical) orientation.

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <Matrix.h>
#include <PixelArt.h>
#include <Color.h>

#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define MATRIX_PIN 6

// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_GRBW    Pixels are wired for GRBW bitstream (RGB+W NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

Matrix matrix = Matrix(8, 8, MATRIX_PIN);

void setup() {
    Serial.begin(9600);
    while (!Serial);
}

void loop() {

  Light white = Light(0,0, Color(255,255,255), 0);
  white.setBrightness(0.0);
  while (white.getBrightness() < 1.0)
  {
    white.incBrightness(0.01);
    matrix.drawLight(white);
    matrix.show();
    delay(50);
  }
  
  // delay(1000);

  Light red = Light(0,0, Color(255,0,0), 0);
  red.setBrightness(0.0);
  while (red.getBrightness() < 1.0)
  {
    red.incBrightness(0.01);
    matrix.drawLight(red);
    matrix.show();
    delay(50);
  }

  delay(1000);

  Light green = Light(0,0, Color(0,255,0), 0);
  green.setBrightness(0.0);
  while (green.getBrightness() < 1.0)
  {
    green.incBrightness(0.01);
    matrix.drawLight(green);
    matrix.show();
    delay(50);
  }

  delay(1000);

  Light blue = Light(0,0, Color(0,0,255), 0);
  blue.setBrightness(0.0);
  while (blue.getBrightness() < 1.0)
  {
    blue.incBrightness(0.01);
    matrix.drawLight(blue);
    matrix.show();
    delay(50);
  }

  delay(1000);

  Light yellow = Light(0,0, Color(0,255,255), 0);
  yellow.setBrightness(0.0);
  while (yellow.getBrightness() < 1.0)
  {
    yellow.incBrightness(0.01);
    matrix.drawLight(yellow);
    matrix.show();
    delay(50);
  }

//   Light purple = Light();
//   purple.setRGB(RGBTriple(255,0,255));
//   purple.setBrightness(0);
//   matrix.setPixel(0, purple);
//   while (purple.getBrightness() < 255)
//   {
//     purple.incBrightness(1);
//     matrix.setPixel(0, purple);
//     matrix.show();
//     delay(20);
//   }

//   Light cyan = Light();
//   cyan.setRGB(RGBTriple(0,255,255));
//   cyan.setBrightness(0);
//   matrix.setPixel(0, cyan);
//   while (cyan.getBrightness() < 255)
//   {
//     cyan.incBrightness(1);
//     matrix.setPixel(0, cyan);
//     matrix.show();
//     delay(20);
//   }

//   Light orange = Light();
//   orange.setRGB(RGBTriple(255,165,0));
//   orange.setBrightness(0);
//   matrix.setPixel(0, orange);
//   while (orange.getBrightness() < 255)
//   {
//     orange.incBrightness(1);
//     matrix.setPixel(0, orange);
//     matrix.show();
//     delay(20);
//   }

//   Light pink = Light();
//   pink.setRGB(RGBTriple(255,192,203));
    Light pink = Light(0,0, Color(255,192,203), 0);
    pink.setBrightness(0.0);
    while (pink.getBrightness() < 1.0)
    {
    pink.incBrightness(0.01);
    matrix.drawLight(pink);
    matrix.show();
    delay(50);
    }

//   Colors colors = Colors();
//   colors.addColor(pink.getColor());
//   colors.addColor(orange.getColor());
//   colors.addColor(cyan.getColor());

//   matrix.sparseLights(colors);
}