// Adafruit_NeoMatrix example for single NeoPixel Shield.
// Scrolls 'Howdy' across the matrix in a portrait (vertical) orientation.

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <Matrix.h>
#include <PixelArt.h>
#include <Color.h>
#include <IRRemote.h>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define MATRIX_PIN 6
#define IR_PIN 8

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
IRrecv irrecv(IR_PIN);
decode_results results;


void setup() {
  irrecv.enableIRIn();
  attachInterrupt(digitalPinToInterrupt(RECV_PIN), handleIRInterrupt, CHANGE);
}

int x = matrix.width();
void loop() {
  
  // Light up each led with delay in between
  for(int i=0; i<(matrix.width*matrix.height); i++) {
    matrix.setPixel(i, RGBTriple(50,50,50));
    matrix.show();
    delay(100);
  }

  matrix.clear();
  
  matrix.fireworks();
}


void handleTurnOn()
{

}


void handleTurnOff()
{


}

void handleIRInterrupt()
{
   // This function will be called when an IR signal is received
  if (irrecv.decode(&results)) {

    irrecv.resume();  // Prepare to receive the next signal
  }
}
