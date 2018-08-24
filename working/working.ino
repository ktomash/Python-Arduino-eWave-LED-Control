#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define DEBUG 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

int l_CS = 7;
int oR = 0;
int oG = 0;
int oB = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("TEST");
  strip.begin();
  strip.show();

}

void loop() {


  if (Serial.available() > 0) {
    int CS = Serial.read();

    for (int j = 0; j < strip.numPixels(); j++) {
      strip.setPixelColor(j, strip.Color((200-2*CS*CS), (200-2*(CS-10)*(CS-10)), (255-(CS-30)*(CS-30))));
      strip.show(); 
    }


    l_CS = CS;
  }      
}


    
    

