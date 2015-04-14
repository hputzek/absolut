#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 15
#define DATA_PIN 3
#define BRIGHTNESS 25

byte activeProgram = 1;
byte activeStep = 1;
byte programs[4][16][16] = {
	{
		{255,0,0,0,0,0,0,0,0,0,0,0,0,0,05,255},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255},
		{0,0,28,0,0,0,0,0,33,0,0,0,0,0,0,255},
		{0,0,0,0,20,0,0,0,0,0,0,0,0,0,255,0},
		{255,0,0,0,0,0,0,0,0,0,0,0,0,0,05,255},
		{0,0,0,0,0,0,200,0,0,55,0,28,0,0,255,255},
		{0,0,0,26,0,0,0,0,0,0,0,0,0,0,0,255},
		{0,0,0,0,0,0,0,45,0,0,0,0,0,0,255,0},
		{255,0,0,50,0,0,0,55,0,0,50,0,0,0,05,255},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255},
		{0,0,0,0,0,0,0,0,69,0,0,0,28,0,0,255},
		{0,0,0,80,0,0,0,0,0,0,0,0,0,0,255,0},
		{255,0,0,0,80,0,0,0,0,0,160,0,0,0,05,255},
		{0,0,0,0,0,28,0,0,0,0,0,0,0,0,255,255},
		{0,0,0,33,0,0,0,0,44,0,0,0,0,0,0,255},
		{0,0,47,0,0,0,0,0,0,0,0,0,0,0,255,0}
	},
	{
        {255,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255}
    },
	{
		{255,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255}
	},
	{
		{255,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255}
	}
};

// Define the array of leds
CRGB leds[NUM_LEDS];



void setup() {
	FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
	LEDS.setBrightness(BRIGHTNESS);
}

void loop() {
	stepLooper();
	FastLED.show();
	delay(100);
}

void stepLooper() {
	setStep(activeProgram,activeStep);
	if(activeStep>16){
		activeStep = 1;
	}
	else {
		activeStep++;
	}
}

void setStep(byte programNumber,byte stepNumber) {
	int i = 0;
	for (i = 0; i < NUM_LEDS; i = i + 1) {
     setLed(i+1,programs[programNumber-1][stepNumber-1][i]);
    }
}

void setLed(byte realLedNum, byte brightness){
	byte ledNum = 0;
	byte colorNum = 0;
	float tool =  (realLedNum-1) /3;
    ledNum = byte(tool+.5);
    colorNum = (realLedNum-1) % 3;
    leds[ledNum][colorNum] = brightness;
}
