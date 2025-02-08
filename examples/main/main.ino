// Adafruit_NeoMatrix example for single NeoPixel Shield.
// Scrolls 'Howdy' across the matrix in a portrait (vertical) orientation.

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <Matrix.h>
#include <PixelArt.h>
#include <Color.h>


#include <IRremote.h>

#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define MATRIX_PIN 6
#define IR_PIN 2

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
uint16_t functionIdx = 100;
IRrecv ir = IRrecv(IR_PIN);
decode_results results;

void setup() {
  ir.enableIRIn();
  Serial.begin(9600);
  while(!Serial);
}



Color c = Color(0,255,255);
void loop() {

    for (int i =0; i < 10; i++)
    {
      matrix.fireworks();
    }
    matrix.plasma(1000);
    matrix.sparseLights(3, c);
}
  

uint16_t results2function(uint32_t res)
{
   switch (res) {
        case 0x45: return 1;   // ONE
        case 0x46: return 2;   // TWO
        case 0x47: return 3;   // THREE
        case 0x44: return 4;   // FOUR
        case 0x40: return 5;   // FIVE
        case 0x43: return 6;   // SIX
        case 0x7:  return 7;   // SEVEN
        case 0x15: return 8;   // EIGHT
        case 0x9:  return 9;   // NINE
        case 0x16: return 10;  // STAR
        case 0x19: return 11;  // ZERO
        case 0xD: return 12;  // POUND
        case 0x18: return 13;  // UP
        case 0x8:  return 14;  // LEFT
        case 0x1C: return 15;  // OK
        case 0x5A: return 16;  // RIGHT
        case 0x52: return 17;  // DOWN
        default: return functionIdx;  // Unknown code
  }
}