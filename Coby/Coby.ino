#include <FastLED.h>

#define LED_PIN  3

#define COLOR_ORDER GRB
#define CHIPSET     WS2812B

#define BRIGHTNESS 16

// Params for width and height
const uint8_t kMatrixWidth = 50;
const uint8_t kMatrixHeight = 6;

// Param for different pixel layouts
const bool    kMatrixSerpentineLayout = true;
const bool    kMatrixVertical = false;

uint16_t XY( uint8_t x, uint8_t y)
{
  uint16_t i;

  if( kMatrixSerpentineLayout == false) {
    if (kMatrixVertical == false) {
      i = (y * kMatrixWidth) + x;
    } else {
      i = kMatrixHeight * (kMatrixWidth - (x+1))+y;
    }
  }

  if( kMatrixSerpentineLayout == true) {
    if (kMatrixVertical == false) {
      if( y & 0x01) {
        // Odd rows run backwards
        uint8_t reverseX = (kMatrixWidth - 1) - x;
        i = (y * kMatrixWidth) + reverseX;
      } else {
        // Even rows run forwards
        i = (y * kMatrixWidth) + x;
      }
    } else { // vertical positioning
      if ( x & 0x01) {
        i = kMatrixHeight * (kMatrixWidth - (x+1))+y;
      } else {
        i = kMatrixHeight * (kMatrixWidth - x) - (y+1);
      }
    }
  }

  return i;
}

#define NUM_LEDS (kMatrixWidth * kMatrixHeight)
CRGB leds_plus_safety_pixel[ NUM_LEDS + 1];
CRGB* const leds( leds_plus_safety_pixel + 1);

void C(int x, int y, CRGB c) {
    leds[XY(x+0,y+1)] = c;
    leds[XY(x+0,y+2)] = c;
    leds[XY(x+0,y+3)] = c;
    leds[XY(x+0,y+4)] = c;
    leds[XY(x+1,y+0)] = c;
    leds[XY(x+1,y+5)] = c;
    leds[XY(x+2,y+0)] = c;
    leds[XY(x+2,y+5)] = c;
    leds[XY(x+3,y+1)] = c;
    leds[XY(x+3,y+4)] = c;
}

void O(int x, int y, CRGB c) {
    leds[XY(x+0,y+1)] = c;
    leds[XY(x+0,y+2)] = c;
    leds[XY(x+0,y+3)] = c;
    leds[XY(x+0,y+4)] = c;
    leds[XY(x+1,y+0)] = c;
    leds[XY(x+1,y+5)] = c;
    leds[XY(x+2,y+0)] = c;
    leds[XY(x+2,y+5)] = c;
    leds[XY(x+3,y+1)] = c;
    leds[XY(x+3,y+2)] = c;
    leds[XY(x+3,y+3)] = c;
    leds[XY(x+3,y+4)] = c;
}

void B(int x, int y, CRGB c) {
    leds[XY(x+0,y+0)] = c;
    leds[XY(x+0,y+1)] = c;
    leds[XY(x+0,y+2)] = c;
    leds[XY(x+0,y+3)] = c;
    leds[XY(x+0,y+4)] = c;
    leds[XY(x+0,y+5)] = c;
    leds[XY(x+1,y+0)] = c;
    leds[XY(x+1,y+2)] = c;
    leds[XY(x+1,y+3)] = c;
    leds[XY(x+1,y+5)] = c;
    leds[XY(x+2,y+0)] = c;
    leds[XY(x+2,y+2)] = c;
    leds[XY(x+2,y+3)] = c;
    leds[XY(x+2,y+5)] = c;
    leds[XY(x+3,y+1)] = c;
    leds[XY(x+3,y+4)] = c;
}

void Y(int x, int y, CRGB c) {
    leds[XY(x+0,y+0)] = c;
    leds[XY(x+0,y+1)] = c;
    leds[XY(x+0,y+2)] = c;
    leds[XY(x+1,y+3)] = c;
    leds[XY(x+1,y+4)] = c;
    leds[XY(x+1,y+5)] = c;
    leds[XY(x+2,y+3)] = c;
    leds[XY(x+2,y+4)] = c;
    leds[XY(x+2,y+5)] = c;
    leds[XY(x+3,y+1)] = c;
    leds[XY(x+3,y+0)] = c;
    leds[XY(x+3,y+2)] = c;
}

void loop()
{
    uint32_t ms = millis();
    int32_t yHueDelta32 = ((int32_t)cos16( ms * (27/1) ) * (350 / kMatrixWidth));
    int32_t xHueDelta32 = ((int32_t)cos16( ms * (39/1) ) * (310 / kMatrixHeight));
	C(10,0, CRGB(255,255,255));
	O(15,0, CRGB(123,233,43));
	B(20,0, CRGB(56,54,255));
	Y(25,0, CRGB(255,11,25));




	//for (int i = 9; i < 300; i += 10)	leds[i] = CRGB(255,0,0);

    
    FastLED.setBrightness(BRIGHTNESS);
    FastLED.show();
}

void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalSMD5050);
  FastLED.setBrightness( BRIGHTNESS );
}
