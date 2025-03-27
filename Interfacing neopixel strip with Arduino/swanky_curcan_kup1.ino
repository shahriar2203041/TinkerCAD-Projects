#include <Adafruit_NeoPixel.h>  // Include the Neopixel library

#define LED_PIN 6      // Data pin connected to pin 6
#define NUM_LEDS 30    // Change this to match the number of LEDs in your strip

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    strip.begin();  // Initialize the strip
    strip.show();   // Turn off all LEDs initially
}

void loop() {
    rainbowCycle(10);  // Run a smooth color-changing effect
}

// Function to create a rainbow cycle effect
void rainbowCycle(int wait) {
    for (int j = 0; j < 256; j++) {
        for (int i = 0; i < strip.numPixels(); i++) {
            int pixelHue = (i * 256 / strip.numPixels() + j) & 255;
            strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
        }
        strip.show();
        delay(wait);
    }
}
