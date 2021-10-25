#include <Adafruit_CircuitPlayground.h>

//  The Circuit playground has 10 integrated LEDs
#define NUM_LEDS 10

//  Base Red / Blue / Green (color) struct
struct RGB {
  byte r;
  byte g;
  byte b;
};

//  The flame color array (the first is the default):
RGB flameColors[] = {
  { 226, 121, 35},  // Orange flame
  { 158, 8, 148},   // Purple flame 
  { 74, 150, 12},   // Green flame
  { 226, 15, 30},   // Red flame
  { 0, 128, 255}    // Blue flame
  };

//  Number of flame colors
int NUMBER_OF_COLORS = sizeof(flameColors) / sizeof(RGB);

//  Tracks the current color
int currentColorIndex = 0;

//  Tracking if it's ok to shift colors or not
bool okToChangeColors = true;

void setup() {
  CircuitPlayground.begin();
}

void loop() {
  //  Get the current colors based on the color index:
  RGB currentColor = flameColors[currentColorIndex];

  // If the left button is pressed....
  if (CircuitPlayground.leftButton()) {
      if(okToChangeColors){
        okToChangeColors = false;
        
        //  Shift to another color flame:
        if(currentColorIndex < (NUMBER_OF_COLORS - 1)){ 
          currentColorIndex++;  
        } else {
          //  Roll around to zero
          currentColorIndex = 0;
        }
      }
  }
  if (CircuitPlayground.rightButton()) {
      if(okToChangeColors){
        okToChangeColors = false;
        
        //  Shift to another color flame:
        if(currentColorIndex > 0){ 
          currentColorIndex--;  
        } else {
          //  Roll around to the top
          currentColorIndex = (NUMBER_OF_COLORS -1);
        }
      }
  } else {
      okToChangeColors = true;
  }
  
  CircuitPlayground.clearPixels();

  //  Flicker, based on our initial RGB values
  for(int i=0; i < NUM_LEDS; i++) {
    int flicker = random(0,100);
    int r1 = currentColor.r-flicker;
    int g1 = currentColor.g-flicker;
    int b1 = currentColor.b-flicker;
    if(g1<0) g1=0;
    if(r1<0) r1=0;
    if(b1<0) b1=0;
    CircuitPlayground.setPixelColor(i,r1,g1,b1);
  }

  //  Adjust the delay here, if you'd like.  Right now, it randomizes the 
  //  color switch delay to give a sense of realism
  delay(random(50,200));
}
