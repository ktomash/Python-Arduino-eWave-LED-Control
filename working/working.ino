#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define DEBUG 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(115200);
  Serial.println("TEST");
  strip.begin();
  strip.show();

}

void loop() {


  if (Serial.available() > 0) {
    int CS = Serial.read();

  /*  for (int j = 0; j < strip.numPixels(); j++) {
      strip.setPixelColor(j, strip.Color((200-2*CS*CS), (200-2*(CS-10)*(CS-10)), (255-(CS-30)*(CS-30))));
      strip.show(); 
    } */
    if (CS < 6) {
      for (int j = 0; j < strip.numPixels(); j++) {
        strip.setPixelColor(j, strip.Color(255, 0, 0));
        strip.show();
        delay(5); 
      }
    }

    if (CS < 13 && CS >=6) {
      for (int j = 0; j < strip.numPixels(); j++) {
        strip.setPixelColor(j, strip.Color(255-(CS-6)*35, 0, (CS-6)*35));
        strip.show(); 
        delay(5); 
      }
    }
    if (CS >= 13 && CS < 25) {
      for (int j = 0; j < strip.numPixels(); j++) {
        strip.setPixelColor(j, strip.Color(0, 20*(CS-13), 255-(20*(CS-13))));
        strip.show(); 
        delay(5); 
      }
    }
    if (CS >= 25) {
      for (int j = 0; j < strip.numPixels(); j++) {
        strip.setPixelColor(j, strip.Color(0, 255, 0));
        strip.show(); 
        delay(5); 
      }
    }

  }      
}


    
    

