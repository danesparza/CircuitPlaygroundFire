# CircuitPlaygroundFire
Spooky fire effect for Adafruit Circuit Playground

I have tested this with an [Adafruit Circuit Playground Express](https://www.adafruit.com/product/3333)

I recommending powering this with a USB [battery charger](http://www.amazon.com/Anker-Generation-Astro-mini-Lipstick-Sized/dp/B005X1Y7I2) or just plugging it into a USB wall socket adapter.

## Flame colors
You can also adjust some parameters of the sketch to easily tweak the fire effect.  Here, we are using an orange flame effect by default:
```cpp
RGB flameColors[] = {
  { 226, 121, 35},  // Orange flame
  { 158, 8, 148},   // Purple flame 
  { 74, 150, 12},   // Green flame
  { 226, 15, 30},   // Red flame
  { 0, 128, 255}    // Blue flame
  };
```

## Changing the flame color after it's powered on
![Circuit playground buttons](https://cdn-learn.adafruit.com/assets/assets/000/047/172/medium640/circuit_playground_pushbutton.jpg)

You can adjust what color is used by using the two main buttons on the circut playground to cycle through the color array when it's plugged in and has power.  It will always reset to the first item in the array when it's powered on (so if you want a different default color, just update the array to have your favorite color first).
