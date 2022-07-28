#include <FastLED.h>

#define LED_PIN  3

#define COLOR_ORDER GRB
#define CHIPSET     WS2812B

#define BRIGHTNESS 32

// Helper functions for an two-dimensional XY matrix of pixels.
// Simple 2-D demo code is included as well.
//
//     XY(x,y) takes x and y coordinates and returns an LED index number,
//             for use like this:  leds[ XY(x,y) ] == CRGB::Red;
//             No error checking is performed on the ranges of x and y.
//
//     XYsafe(x,y) takes x and y coordinates and returns an LED index number,
//             for use like this:  leds[ XYsafe(x,y) ] == CRGB::Red;
//             Error checking IS performed on the ranges of x and y, and an
//             index of "-1" is returned.  Special instructions below
//             explain how to use this without having to do your own error
//             checking every time you use this function.  
//             This is a slightly more advanced technique, and 
//             it REQUIRES SPECIAL ADDITIONAL setup, described below.


// Params for width and height
const uint8_t kMatrixWidth = 60;
const uint8_t kMatrixHeight = 5;

// Param for different pixel layouts
const bool    kMatrixSerpentineLayout = true;
const bool    kMatrixVertical = false;

// Set 'kMatrixSerpentineLayout' to false if your pixels are 
// laid out all running the same way, like this:
//
//     0 >  1 >  2 >  3 >  4
//                         |
//     .----<----<----<----'
//     |
//     5 >  6 >  7 >  8 >  9
//                         |
//     .----<----<----<----'
//     |
//    10 > 11 > 12 > 13 > 14
//                         |
//     .----<----<----<----'
//     |
//    15 > 16 > 17 > 18 > 19
//
// Set 'kMatrixSerpentineLayout' to true if your pixels are 
// laid out back-and-forth, like this:
//
//     0 >  1 >  2 >  3 >  4
//                         |
//                         |
//     9 <  8 <  7 <  6 <  5
//     |
//     |
//    10 > 11 > 12 > 13 > 14
//                        |
//                        |
//    19 < 18 < 17 < 16 < 15
//
// Bonus vocabulary word: anything that goes one way 
// in one row, and then backwards in the next row, and so on
// is call "boustrophedon", meaning "as the ox plows."


// This function will return the right 'led index number' for 
// a given set of X and Y coordinates on your matrix.  
// IT DOES NOT CHECK THE COORDINATE BOUNDARIES.  
// That's up to you.  Don't pass it bogus values.
//
// Use the "XY" function like this:
//
//    for( uint8_t x = 0; x < kMatrixWidth; x++) {
//      for( uint8_t y = 0; y < kMatrixHeight; y++) {
//      
//        // Here's the x, y to 'led index' in action: 
//        leds[ XY( x, y) ] = CHSV( random8(), 255, 255);
//      
//      }
//    }
//
//
// Demo that USES "XY" follows code below
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


void loop()
{
    uint32_t ms = millis();
    int32_t yHueDelta32 = ((int32_t)cos16( ms * (27/1) ) * (350 / kMatrixWidth));
    int32_t xHueDelta32 = ((int32_t)cos16( ms * (39/1) ) * (310 / kMatrixHeight));
    leds[XY(13,1)] = CRGB(255,255,255);
    leds[XY(12,0)] = CRGB(255,255,255);
    leds[XY(11,0)] = CRGB(255,255,255);
    leds[XY(10,1)] = CRGB(255,255,255);
    leds[XY(10,2)] = CRGB(255,255,255);
    leds[XY(10,3)] = CRGB(255,255,255);
    leds[XY(11,4)] = CRGB(255,255,255);
    leds[XY(12,4)] = CRGB(255,255,255);
    leds[XY(13,3)] = CRGB(255,255,255);
    
    leds[XY(15,1)] = CRGB(255,255,255);
    leds[XY(15,2)] = CRGB(255,255,255);
    leds[XY(15,3)] = CRGB(255,255,255);
    leds[XY(16,0)] = CRGB(255,255,255);
    leds[XY(16,4)] = CRGB(255,255,255);
    leds[XY(17,0)] = CRGB(255,255,255);
    leds[XY(17,4)] = CRGB(255,255,255);
    leds[XY(18,1)] = CRGB(255,255,255);
    leds[XY(18,2)] = CRGB(255,255,255);
    leds[XY(18,3)] = CRGB(255,255,255);

    leds[XY(20,0)] = CRGB(255,255,255);
    leds[XY(20,1)] = CRGB(255,255,255);
    leds[XY(20,2)] = CRGB(255,255,255);
    leds[XY(20,3)] = CRGB(255,255,255);
    leds[XY(20,4)] = CRGB(255,255,255);
    leds[XY(21,0)] = CRGB(255,255,255);
    leds[XY(21,2)] = CRGB(255,255,255);
    leds[XY(21,4)] = CRGB(255,255,255);
    leds[XY(22,0)] = CRGB(255,255,255);
    leds[XY(22,2)] = CRGB(255,255,255);
    leds[XY(22,4)] = CRGB(255,255,255);
    leds[XY(23,1)] = CRGB(255,255,255);
    leds[XY(23,3)] = CRGB(255,255,255);

    leds[XY(25,0)] = CRGB(255,255,255);
    leds[XY(25,1)] = CRGB(255,255,255);
    leds[XY(26,2)] = CRGB(255,255,255);
    leds[XY(26,3)] = CRGB(255,255,255);
    leds[XY(26,4)] = CRGB(255,255,255);
    leds[XY(27,1)] = CRGB(255,255,255);
    leds[XY(27,0)] = CRGB(255,255,255);
    
    
    FastLED.setBrightness(BRIGHTNESS);
    FastLED.show();
}

void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalSMD5050);
  FastLED.setBrightness( BRIGHTNESS );
}
