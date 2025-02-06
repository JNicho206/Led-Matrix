#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <Matrix.h>
#include <PixelArt.h>
#include <Color.h>
#include <IRRemote.hpp>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define MATRIX_PIN 6
#define IR_PIN 2

#define CMD_UNKNOWN -1
#define CMD_DEFAULT 0
#define CMD_ON 1
#define CMD_OFF 2
#define CMD_FIREWORKS 100
#define CMD_RAINBOW 101
#define CMD_SPARSE_LIGHTS_WHITE 102
#define CMD_SPARSE_LIGHTS_COLOR 103



// After running the code, press the buttons on the remote control and observe the serial monitor.
// Match the button code to the signal and update the values below
#define SIG_ON 0x0
#define SIG_OFF 0x1
#define SIG_FIREWORKS 0x2
#define SIG_RAINBOW 0x3
#define SIG_SPARSE_LIGHTS_WHITE 0x4
#define SIG_SPARSE_LIGHTS_COLOR 0x5
#define SIG_DEFAULT 0x6


uint16_t signalToCommand(unsigned long signal) {
    switch (signal) {
        case SIG_ON:
            return CMD_ON;
        case SIG_OFF:
            return CMD_OFF;
        case SIG_FIREWORKS:
            return CMD_FIREWORKS;
        case SIG_RAINBOW:
            return CMD_RAINBOW;
        case SIG_SPARSE_LIGHTS_WHITE:
            return CMD_SPARSE_LIGHTS_WHITE;
        case SIG_SPARSE_LIGHTS_COLOR:
            return CMD_SPARSE_LIGHTS_COLOR;
        default:
            return CMD_DEFAULT;
    }
}

void handleCommand(uint16_t cmd) 
{
    switch(cmd)
    {
        case CMD_ON:
            handleTurnOn();
            break;
        case CMD_OFF:
            handleTurnOff();
            break;
        case CMD_FIREWORKS:
            matrix.fireworks();
            break;
        case CMD_RAINBOW:
            matrix.rainbowGrad(3);
            break;
        case CMD_SPARSE_LIGHTS_WHITE:
            matrix.sparseLights();
            break;
        case CMD_SPARSE_LIGHTS_COLOR:
            matrix.sparseLights();
            break;
        default:
            // matrix.aurora();
            matrix.fireworks();
            break;
    }
}

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
volatile unsigned long signal = SIG_DEFAULT;
volatile bool wakeFlag = true;

void setup() {
    Serial.begin(9600);
    while (!Serial);
    IrReceiver.begin(IR_PIN);

}
void loop() {
    if (IrReceiver.decode()) {
        signal = IrReceiver.decodedIRData.command;
        IrReceiver.resume();
        Serial.print("Signal Received: ");
        Serial.println(signal);
        uint16_t cmd = signalToCommand(signal);
        handleCommand(cmd);
    }
    else
    {
        // Can try to make a resume instead and store the state
        handleCommand(cmd);
    }
}

void handleTurnOn()
{
  wakeFlag = true;
}

void wakeUp()
{
    wakeFlag = true;
}

void handleTurnOff()
{   

    Serial.println("Entering sleep mode...");

    delay(100);  // Allow Serial messages to complete

    // Set up interrupt on the IR_PIN to wake up the Arduino
    attachInterrupt(digitalPinToInterrupt(IR_PIN), wakeUp, CHANGE);

    wakeFlag = false;
    // Enter power-down mode (sleep until IR receiver wakes it up)
    LowPower.powherDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);

    // Might need to put this in a loop until the correct button is pressed
    // Detach interrupt after waking up
    detachInterrupt(digitalPinToInterrupt(IR_PIN));

    
    handleTurnOn();

    Serial.println("Waking up from sleep");
}
