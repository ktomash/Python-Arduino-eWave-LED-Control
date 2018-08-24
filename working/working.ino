#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define DEBUG 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

int l_CS = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("TEST");
  strip.begin();
  strip.show();
}

void loop() {

  if (Serial.available() > 0) {
    int CS = Serial.read();

    if (CS < 6) {
      for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));
        strip.show(); 
      }
    } else {
      if (CS < 21) {
        for (int i = 0; i < strip.numPixels(); i++) {
          strip.setPixelColor(i, strip.Color(0, 0, 255));
          strip.show(); 
        }
      } else {
        for (int i = 0; i < strip.numPixels(); i++) {
          strip.setPixelColor(i, strip.Color(0, 255, 0));
          strip.show(); 
        }
      }
    }
    l_CS = CS;
  }      
}
    
    

