#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 3

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 3

const int ledNumber = 3;
const int channel = 3;
int ledStates[ledNumber][channel];
int brightnessArray[ledNumber][channel];
int loopIterator = 255;
int loopDuration = 2;

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
   // LEDS.setBrightness(254);
   setRandomBrightness();
}

void loop() {
    for (int i = 0; i < ledNumber; i++) {
      for (int j = 0; j < channel; j++) {
            if(brightnessArray[i][j] - loopIterator > 0){
                leds[i][j] = cubicwave8(brightnessArray[i][j] - loopIterator);
            }
            else {
                leds[i][j] = 0;
            }

      }
    }
    FastLED.show();
    if(loopIterator > 0) {
        loopIterator--;
    }
    else {
        setRandomBrightness();
        loopIterator = 255;
    }

    delay(4 * loopDuration);
}

void setRandomBrightness(){
    for (int i = 0; i < ledNumber; i++) {
      for (int j = 0; j < channel; j++) {
         brightnessArray[i][j] = random8(0,255);
      }
    }
}
