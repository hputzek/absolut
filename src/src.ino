#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 15

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 3

int ledArray[NUM_LEDS];
int activeLed = 1;

// Define the array of leds
CRGB leds[NUM_LEDS];



void setup() {
	FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
	LEDS.setBrightness(255);
}

void loop() {
 animate(activeLed);
 setLed(activeLed,random8(1,30));
 if(activeLed == NUM_LEDS){
    activeLed = 1;
 }
 else {
    activeLed ++;
 }
}

void animate(int ledNumber){
int x = 1;
  for (int i = 254; i > -1; i = i + x){
	   if (i == 254){
			x = -1;
		  }
         setLed(ledNumber,i);
         FastLED.show();
        // delay(.001);
   }
}

void setLed(int realLedNum, int brightness){
	int ledNum = 0;
	int colorNum = 0;
	float tool =  (realLedNum-1) /3;
    ledNum = int(tool+.5);
    colorNum = (realLedNum-1) % 3;
    leds[ledNum][colorNum] = cubicwave8(brightness)-1;
}
