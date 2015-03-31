#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 3

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 3

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
  // Turn the LED on, then pause
    leds[0].r = random8(40,255);
    leds[0].g = random8(40,255);
    leds[0].b = random8(40,255);
    leds[1].r = random8(40,255);
    leds[1].g = random8(40,255);
    leds[1].b = random8(40,255);
    leds[2].r = random8(40,255);
    leds[2].g = random8(40,255);
    leds[2].b = random8(40,255);
    LEDS.setBrightness(random8(5,20));
  FastLED.show();
  delay(100);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  FastLED.show();
    delay(10);
}
