// Adafruit_NeoMatrix example for single NeoPixel Shield.
// Scrolls 'Howdy' across the matrix in a portrait (vertical) orientation.

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <Matrix.h>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define PIN 6

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


// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.
Matrix matrix = Matrix(8, 8, PIN);

const RGBTriple christmas_tree_colors[][8] = {
    { // R1
      RGBTriple(), RGBTriple(), RGBTriple(), RGBTriple(30,255,0),
      RGBTriple(30,255,0), RGBTriple(), RGBTriple(), RGBTriple()
    },
    { // R2
      RGBTriple(), RGBTriple(), RGBTriple(), RGBTriple(30,255,0),
      RGBTriple(255, 0, 100), RGBTriple(), RGBTriple(), RGBTriple()
    },
    { // R3
      RGBTriple(), RGBTriple(), RGBTriple(130,40,255), RGBTriple(30,255,0),
      RGBTriple(30,255,0), RGBTriple(30,255,0), RGBTriple(), RGBTriple()
    },
    { // R4
      RGBTriple(), RGBTriple(), RGBTriple(30,255,0), RGBTriple(30,255,0),
      RGBTriple(30,255,0), RGBTriple(255,0,0), RGBTriple(), RGBTriple()
    },
    { // R5
      RGBTriple(), RGBTriple(100, 0, 200), RGBTriple(30,255,0), RGBTriple(80,0,200),
      RGBTriple(30,255,0), RGBTriple(30,255,0), RGBTriple(30,255,0), RGBTriple()
    },
    { // R6
      RGBTriple(30,255,0), RGBTriple(30,255,0), RGBTriple(100, 100, 50), RGBTriple(30,255,0),
      RGBTriple(30,255,0), RGBTriple(30,255,0), RGBTriple(0,0,255), RGBTriple(30,255,0)
    },
    { // R7
      RGBTriple(30,255,0), RGBTriple(255,30,40), RGBTriple(30,255,0), RGBTriple(30,255,0),
      RGBTriple(30,255,0), RGBTriple(50,0,255), RGBTriple(30,255,0), RGBTriple(255,0,0)
    },
    { // R8
      RGBTriple(), RGBTriple(), RGBTriple(), RGBTriple(200,50, 0),
      RGBTriple(200,50,0), RGBTriple(), RGBTriple(), RGBTriple()
    }
};
Art8x8 christmas_tree = Art8x8(christmas_tree_colors);

void setup() {
  //matrix.setTextColor(colors[0]);
  // matrix.setTextWrap(false);
  // matrix.setBrightness(40);
  // matrix.setTextColor(colors[0]);
}

int x = matrix.width();
void loop() {
  matrix.setBrightness(15);
  matrix.rainbowGrad(3);
}

// void christmas_progression()
// {
//   matrix.drawTree();
//   //Say merry christmas
  
// }
