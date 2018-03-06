#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            D4   // Pin on the ESP8266 NodeMCU 1.0

#define NUMPIXELS      53   // Number of WS2812B in my Triangle light

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100; // delay for half a second

void setup() {
pixels.begin(); // This initializes the NeoPixel library.
pixels.show();
}

void loop() {

  Startup(50);
  Glow(5);
  circle(250);
  TopToBottom(50);
  SetTotalColor(pixels.Color(255,255,255), 10000);
  
  //flashing(50);
  //singlecircle(pixels.Color(255,255,255), 40);
  //singlecircle(pixels.Color(0,255,255), 40);
  //singlecircle(pixels.Color(255,255,0), 40);
  //singlecircle(pixels.Color(255,0,255), 40);
  //singlecircle(pixels.Color(255,0,0), 40);
  //singlecircle(pixels.Color(0,0,255), 40);
  //singlecircle(pixels.Color(0,0,255), 40);

  Manual(10000);

  SetTotalColor(pixels.Color(255,127,0), 5000);

  SetTotalColor(pixels.Color(127,255,0), 5000);

  SetTotalColor(pixels.Color(0,127,255), 5000);

  SetTotalColor(pixels.Color(0,255,127), 5000);

  SetTotalColor(pixels.Color(255,0,127), 5000);

  SetTotalColor(pixels.Color(127,0,255), 5000);

  SetTotalColor(pixels.Color(0,255,0), 5000);

  SetTotalColor(pixels.Color(255,0,0), 5000);

  SetTotalColor(pixels.Color(0,0,255), 5000);

}

void SetTotalColor(uint32_t c, uint16_t wait) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, c);
    }
    pixels.show();
    delay(wait);
}

void Startup(uint8_t wait) {
  for(uint16_t i=0; i<200; i = i + 5) {
    Plate1_Bottom(pixels.Color(i, 0, 0));
    Plate1_Top(pixels.Color(i, 0, 0));
    pixels.show();
    delay(wait);
  }
  for(uint16_t i=200; i>0; i = i - 5) {
    Plate1_Bottom(pixels.Color(i, 0, 0));
    Plate1_Top(pixels.Color(i, 0, 0));
    Plate2_Bottom(pixels.Color(0, 200 - i, 0));
    Plate2_Top(pixels.Color(0, 200 - i, 0));
    pixels.show();
    delay(wait);
  }
  for(uint16_t i=200; i>0;  i = i - 5) {
    Plate2_Bottom(pixels.Color(0, i, 0));
    Plate2_Top(pixels.Color(0, i, 0));
    Plate3_Bottom(pixels.Color(0, 0, 200 - i));
    Plate3_Top(pixels.Color(0, 0, 200 - i));
    pixels.show();
    delay(wait);
  }
  for(uint16_t i=200; i>0;  i = i - 5) {
    Plate3_Bottom(pixels.Color(0, 0, i));
    Plate3_Top(pixels.Color(0, 0, i));
    pixels.show();
    delay(wait);
  }
}

void TopToBottom(uint8_t wait) {
  for(uint16_t i=0; i<249; i = i + 5) {
    Plate1_Bottom(pixels.Color(i, 0, 0)); 
    Plate2_Bottom(pixels.Color(i, 0, 0));
    Plate3_Bottom(pixels.Color(i, 0, 0));
    pixels.show();
    delay(wait);
  }
  for(uint16_t loops=0; loops<2; loops++) {
    
    for(uint16_t i=0; i<249; i = i + 5) {
      Plate1_Top(pixels.Color(0, 0, i)); 
      Plate2_Top(pixels.Color(0, 0, i));
      Plate3_Top(pixels.Color(0, 0, i));
      Plate1_Bottom(pixels.Color(249 - i, 0, 0)); 
      Plate2_Bottom(pixels.Color(249 - i, 0, 0));
      Plate3_Bottom(pixels.Color(249 - i, 0, 0));
      pixels.show();
      delay(wait);
    }
    
    for(uint16_t i=0; i<249; i = i + 5) {
      Plate1_Top(pixels.Color(0, 0, 249 - i)); 
      Plate2_Top(pixels.Color(0, 0, 249 - i));
      Plate3_Top(pixels.Color(0, 0, 249 - i));
      Plate1_Bottom(pixels.Color(i, 0, 0)); 
      Plate2_Bottom(pixels.Color(i, 0, 0));
      Plate3_Bottom(pixels.Color(i, 0, 0));
      pixels.show();
      delay(wait);
    }
    
    for(uint16_t i=0; i<249; i = i + 5) {
      Plate1_Top(pixels.Color(0, i, 0)); 
      Plate2_Top(pixels.Color(0, i, 0));
      Plate3_Top(pixels.Color(0, i, 0));
      Plate1_Bottom(pixels.Color(249 - i, 0, 0)); 
      Plate2_Bottom(pixels.Color(249 - i, 0, 0));
      Plate3_Bottom(pixels.Color(249 - i, 0, 0));
      pixels.show();
      delay(wait);
    }
    
    for(uint16_t i=0; i<249; i = i + 5) {
      Plate1_Top(pixels.Color(0, 249 - i, 0)); 
      Plate2_Top(pixels.Color(0, 249 - i, 0));
      Plate3_Top(pixels.Color(0, 249 - i, 0));
      Plate1_Bottom(pixels.Color(i, 0, i)); 
      Plate2_Bottom(pixels.Color(i, 0, i));
      Plate3_Bottom(pixels.Color(i, 0, i));
      pixels.show();
      delay(wait);
    }

    for(uint16_t i=0; i<249; i = i + 5) {
      Plate1_Top(pixels.Color(0, i, i)); 
      Plate2_Top(pixels.Color(0, i, i));
      Plate3_Top(pixels.Color(0, i, i));
      Plate1_Bottom(pixels.Color(249 - i, 0, 249 - i)); 
      Plate2_Bottom(pixels.Color(249 - i, 0, 249 - i));
      Plate3_Bottom(pixels.Color(249 - i, 0, 249 - i));
      pixels.show();
      delay(wait);
    }
    
    for(uint16_t i=0; i<249; i = i + 5) {
      Plate1_Top(pixels.Color(0, 249 - i, 249 - i)); 
      Plate2_Top(pixels.Color(0, 249 - i, 249 - i));
      Plate3_Top(pixels.Color(0, 249 - i, 249 - i));
      Plate1_Bottom(pixels.Color(i, i, 0)); 
      Plate2_Bottom(pixels.Color(i, i, 0));
      Plate3_Bottom(pixels.Color(i, i, 0));
      pixels.show();
      delay(wait);
    }

    for(uint16_t i=0; i<249; i = i + 5) {
      Plate1_Top(pixels.Color(0, i, 0)); 
      Plate2_Top(pixels.Color(0, i, 0));
      Plate3_Top(pixels.Color(0, i, 0));
      Plate1_Bottom(pixels.Color(249 - i, 0, 249 - i)); 
      Plate2_Bottom(pixels.Color(249 - i, 0, 249 - i));
      Plate3_Bottom(pixels.Color(249 - i, 0, 249 - i));
      pixels.show();
      delay(wait);
    }
    
    for(uint16_t i=0; i<249; i = i + 5) {
      Plate1_Top(pixels.Color(0, 249 - i, 0)); 
      Plate2_Top(pixels.Color(0, 249 - i, 0));
      Plate3_Top(pixels.Color(0, 249 - i, 0));
      Plate1_Bottom(pixels.Color(i, 0, 0)); 
      Plate2_Bottom(pixels.Color(i, 0, 0));
      Plate3_Bottom(pixels.Color(i, 0, 0));
      pixels.show();
      delay(wait);
    }
  }
}

void flashing(uint8_t wait) {
  Plate1_Top(pixels.Color(0, 0, 0)); 
  Plate2_Top(pixels.Color(0, 0, 0));
  Plate3_Top(pixels.Color(0, 0, 0));
  Plate1_Bottom(pixels.Color(0, 0, 0)); 
  Plate2_Bottom(pixels.Color(0, 0, 0));
  Plate3_Bottom(pixels.Color(0, 0, 0));
  pixels.show();
  delay(1000);
  for(uint16_t i=0; i<249; i = i + 5) {
    if ( (i % 2) == 0) {
      Plate1_Top(pixels.Color(0, 0, 0)); 
      Plate2_Top(pixels.Color(0, 0, 0));
      Plate3_Top(pixels.Color(0, 0, 0));
      Plate1_Bottom(pixels.Color(0, 0, 0)); 
      Plate2_Bottom(pixels.Color(0, 0, 0));
      Plate3_Bottom(pixels.Color(0, 0, 0));
      pixels.show();
      delay(wait);
    }
    else
    {
      Plate1_Top(pixels.Color(0, 0, i)); 
      Plate2_Top(pixels.Color(0, 0, i));
      Plate3_Top(pixels.Color(0, 0, i));
      Plate1_Bottom(pixels.Color(0, 0, i)); 
      Plate2_Bottom(pixels.Color(0, 0, i));
      Plate3_Bottom(pixels.Color(0, 0, i));
      pixels.show();
      delay(wait);
    }
  }
  
  for(uint16_t i=250; i>0; i = i - 5) {
    if ( (i % 2) == 0) {
      Plate1_Top(pixels.Color(0, 0, 0)); 
      Plate2_Top(pixels.Color(0, 0, 0));
      Plate3_Top(pixels.Color(0, 0, 0));
      Plate1_Bottom(pixels.Color(0, 0, 0)); 
      Plate2_Bottom(pixels.Color(0, 0, 0));
      Plate3_Bottom(pixels.Color(0, 0, 0));
      pixels.show();
      delay(wait);
    }
    else
    {
      Plate1_Top(pixels.Color(0, 0, i)); 
      Plate2_Top(pixels.Color(0, 0, i));
      Plate3_Top(pixels.Color(0, 0, i));
      Plate1_Bottom(pixels.Color(0, 0, i)); 
      Plate2_Bottom(pixels.Color(0, 0, i));
      Plate3_Bottom(pixels.Color(0, 0, i));
      pixels.show();
      delay(wait);
    }
  }
  
  for(uint16_t i=0; i<249; i = i + 5) {
    if ( (i % 2) == 0) {
      Plate1_Top(pixels.Color(0, 0, 0)); 
      Plate2_Top(pixels.Color(0, 0, 0));
      Plate3_Top(pixels.Color(0, 0, 0));
      Plate1_Bottom(pixels.Color(0, 0, 0)); 
      Plate2_Bottom(pixels.Color(0, 0, 0));
      Plate3_Bottom(pixels.Color(0, 0, 0));
      pixels.show();
      delay(wait);
    }
    else
    {
      Plate1_Top(pixels.Color(0, i, 0)); 
      Plate2_Top(pixels.Color(0, i, 0));
      Plate3_Top(pixels.Color(0, i, 0));
      Plate1_Bottom(pixels.Color(0, i, 0)); 
      Plate2_Bottom(pixels.Color(0, i, 0));
      Plate3_Bottom(pixels.Color(0, i, 0));
      pixels.show();
      delay(wait);
    }
  }
  
  for(uint16_t i=250; i>0; i = i - 5) {
    if ( (i % 2) == 0) {
      Plate1_Top(pixels.Color(0, 0, 0)); 
      Plate2_Top(pixels.Color(0, 0, 0));
      Plate3_Top(pixels.Color(0, 0, 0));
      Plate1_Bottom(pixels.Color(0, 0, 0)); 
      Plate2_Bottom(pixels.Color(0, 0, 0));
      Plate3_Bottom(pixels.Color(0, 0, 0));
      pixels.show();
      delay(wait);
    }
    else
    {
      Plate1_Top(pixels.Color(0, i, 0)); 
      Plate2_Top(pixels.Color(0, i, 0));
      Plate3_Top(pixels.Color(0, i, 0));
      Plate1_Bottom(pixels.Color(0, i, 0)); 
      Plate2_Bottom(pixels.Color(0, i, 0));
      Plate3_Bottom(pixels.Color(0, i, 0));
      pixels.show();
      delay(wait);
    }
  }

  for(uint16_t i=0; i<249; i = i + 5) {
    if ( (i % 2) == 0) {
      Plate1_Top(pixels.Color(0, 0, 0)); 
      Plate2_Top(pixels.Color(0, 0, 0));
      Plate3_Top(pixels.Color(0, 0, 0));
      Plate1_Bottom(pixels.Color(0, 0, 0)); 
      Plate2_Bottom(pixels.Color(0, 0, 0));
      Plate3_Bottom(pixels.Color(0, 0, 0));
      pixels.show();
      delay(wait);
    }
    else
    {
      Plate1_Top(pixels.Color(i, 0, 0)); 
      Plate2_Top(pixels.Color(i, 0, 0));
      Plate3_Top(pixels.Color(i, 0, 0));
      Plate1_Bottom(pixels.Color(i, 0, 0)); 
      Plate2_Bottom(pixels.Color(i, 0, 0));
      Plate3_Bottom(pixels.Color(i, 0, 0));
      pixels.show();
      delay(wait);
    }
  }
  
  for(uint16_t i=250; i>0; i = i - 5) {
    if ( (i % 2) == 0) {
      Plate1_Top(pixels.Color(0, 0, 0)); 
      Plate2_Top(pixels.Color(0, 0, 0));
      Plate3_Top(pixels.Color(0, 0, 0));
      Plate1_Bottom(pixels.Color(0, 0, 0)); 
      Plate2_Bottom(pixels.Color(0, 0, 0));
      Plate3_Bottom(pixels.Color(0, 0, 0));
      pixels.show();
      delay(wait);
    }
    else
    {
      Plate1_Top(pixels.Color(i, 0, 0)); 
      Plate2_Top(pixels.Color(i, 0, 0));
      Plate3_Top(pixels.Color(i, 0, 0));
      Plate1_Bottom(pixels.Color(i, 0, 0)); 
      Plate2_Bottom(pixels.Color(i, 0, 0));
      Plate3_Bottom(pixels.Color(i, 0, 0));
      pixels.show();
      delay(wait);
    }
  }
}

void circle(uint8_t wait) {
  for(uint16_t i=0; i<2; i++) {
    Plate1_Top(pixels.Color(255, 0, 0));
    Plate1_Bottom(pixels.Color(255, 0, 0)); 
    pixels.show();
    delay(wait); 
    Plate1_Top(pixels.Color(0, 0, 0));
    Plate1_Bottom(pixels.Color(0, 0, 0)); 
    Plate2_Top(pixels.Color(255, 0, 0));
    Plate2_Bottom(pixels.Color(255, 0, 0)); 
    pixels.show();
    delay(wait); 
    Plate2_Top(pixels.Color(0, 0, 0));
    Plate2_Bottom(pixels.Color(0, 0, 0)); 
    Plate3_Top(pixels.Color(255, 0, 0));
    Plate3_Bottom(pixels.Color(255, 0, 0)); 
    pixels.show();
    delay(wait); 
    Plate3_Top(pixels.Color(0, 0, 0));
    Plate3_Bottom(pixels.Color(0, 0, 0)); 
    Plate1_Top(pixels.Color(0, 255, 0));
    Plate1_Bottom(pixels.Color(0, 255, 0)); 
    pixels.show();
    delay(wait); 
    Plate1_Top(pixels.Color(0, 0, 0));
    Plate1_Bottom(pixels.Color(0, 0, 0)); 
    Plate2_Top(pixels.Color(0, 255, 0));
    Plate2_Bottom(pixels.Color(0, 255, 0)); 
    pixels.show();
    delay(wait); 
    Plate2_Top(pixels.Color(0, 0, 0));
    Plate2_Bottom(pixels.Color(0, 0, 0)); 
    Plate3_Top(pixels.Color(0, 255, 0));
    Plate3_Bottom(pixels.Color(0, 255, 0)); 
    pixels.show();
    delay(wait); 
    Plate3_Top(pixels.Color(0, 0, 0));
    Plate3_Bottom(pixels.Color(0, 0, 0)); 
    Plate1_Top(pixels.Color(0, 0, 255));
    Plate1_Bottom(pixels.Color(0, 0, 255)); 
    pixels.show();
    delay(wait); 
    Plate1_Top(pixels.Color(0, 0, 0));
    Plate1_Bottom(pixels.Color(0, 0, 0)); 
    Plate2_Top(pixels.Color(0, 0, 255));
    Plate2_Bottom(pixels.Color(0, 0, 255)); 
    pixels.show();
    delay(wait); 
    Plate2_Top(pixels.Color(0, 0, 0));
    Plate2_Bottom(pixels.Color(0, 0, 0)); 
    Plate3_Top(pixels.Color(0, 0, 255));
    Plate3_Bottom(pixels.Color(0, 0, 255)); 
    pixels.show();
    delay(wait); 
    Plate3_Top(pixels.Color(0, 0, 0));
    Plate3_Bottom(pixels.Color(0, 0, 0)); 
    Plate1_Top(pixels.Color(0, 255, 255));
    Plate1_Bottom(pixels.Color(0, 255, 255)); 
    pixels.show();
    delay(wait); 
    Plate1_Top(pixels.Color(0, 0, 0));
    Plate1_Bottom(pixels.Color(0, 0, 0)); 
    Plate2_Top(pixels.Color(0, 255, 255));
    Plate2_Bottom(pixels.Color(0, 255, 255)); 
    pixels.show();
    delay(wait); 
    Plate2_Top(pixels.Color(0, 0, 0));
    Plate2_Bottom(pixels.Color(0, 0, 0)); 
    Plate3_Top(pixels.Color(0, 255, 255));
    Plate3_Bottom(pixels.Color(0, 255, 255)); 
    pixels.show();
    delay(wait); 
    Plate3_Top(pixels.Color(0, 0, 0));
    Plate3_Bottom(pixels.Color(0, 0, 0)); 
    Plate1_Top(pixels.Color(255, 255, 0));
    Plate1_Bottom(pixels.Color(255, 255, 0)); 
    pixels.show();
    delay(wait); 
    Plate1_Top(pixels.Color(0, 0, 0));
    Plate1_Bottom(pixels.Color(0, 0, 0)); 
    Plate2_Top(pixels.Color(255, 255, 0));
    Plate2_Bottom(pixels.Color(255, 255, 0)); 
    pixels.show();
    delay(wait); 
    Plate2_Top(pixels.Color(0, 0, 0));
    Plate2_Bottom(pixels.Color(0, 0, 0)); 
    Plate3_Top(pixels.Color(255, 255, 0));
    Plate3_Bottom(pixels.Color(255, 255, 0)); 
    pixels.show();
    delay(wait); 
    Plate3_Top(pixels.Color(0, 0, 0));
    Plate3_Bottom(pixels.Color(0, 0, 0)); 
    Plate1_Top(pixels.Color(255, 0, 255));
    Plate1_Bottom(pixels.Color(255, 0, 255)); 
    pixels.show();
    delay(wait); 
    Plate1_Top(pixels.Color(0, 0, 0));
    Plate1_Bottom(pixels.Color(0, 0, 0)); 
    Plate2_Top(pixels.Color(255, 0, 255));
    Plate2_Bottom(pixels.Color(255, 0, 255)); 
    pixels.show();
    delay(wait); 
    Plate2_Top(pixels.Color(0, 0, 0));
    Plate2_Bottom(pixels.Color(0, 0, 0)); 
    Plate3_Top(pixels.Color(255, 0, 255));
    Plate3_Bottom(pixels.Color(255, 0, 255)); 
    pixels.show();
    delay(wait); 
    Plate3_Top(pixels.Color(0, 0, 0));
    Plate3_Bottom(pixels.Color(055, 0, 0)); 
    pixels.show();
    delay(wait); 
  }
}

void singlecircle(uint32_t c, uint8_t wait) {
  pixels.show();
  for(uint16_t i=0; i<NUMPIXELS; i++) {
    if ( i==0 ) {
      pixels.setPixelColor(i, c);
      pixels.show();
      delay(wait); 
    }
    else
    {
      pixels.setPixelColor(i, c);
      pixels.setPixelColor(i-1, pixels.Color(0,0,0));
      pixels.show();
      delay(wait); 
    }
  }
}

void Glow(uint8_t wait) {
  pixels.show();
  for(uint16_t j=0; j<255; j++) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(j,0,0));
    }
    pixels.show();
    delay(wait);
  }
  for(uint16_t j=255; j>50; j--) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(j,0,0));
    }
    pixels.show();
    delay(wait);
  }
  for(uint16_t j=50; j<255; j++) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(j,0,0));
    }
    pixels.show();
    delay(wait);
  }
  for(uint16_t j=255; j>0; j--) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(j,0,0));
    }
    pixels.show();
  }
  for(uint16_t j=0; j<255; j++) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(j,j,0));
    }
    pixels.show();
    delay(wait);
  }
  for(uint16_t j=255; j>50; j--) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(j,j,0));
    }
    pixels.show();
    delay(wait);
  }
  for(uint16_t j=50; j<255; j++) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(j,j,0));
    }
    pixels.show();
    delay(wait);
  }
  for(uint16_t j=255; j>50; j--) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(j,j,0));
    }
    pixels.show();
    delay(wait);
  }
  for(uint16_t j=50; j<255; j++) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(j,j,0));
    }
    pixels.show();
    delay(wait);
  }

 
  for(uint16_t j=255; j>0; j--) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(j,j,0));
    }
    pixels.show();
  }
  for(uint16_t j=0; j<255; j++) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(j,0,j));
    }
    pixels.show();
    delay(wait);
  }
  for(uint16_t j=255; j>50; j--) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(j,0,j));
    }
    pixels.show();
    delay(wait);
  }
  for(uint16_t j=50; j<255; j++) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(j,0,j));
    }
    pixels.show();
    delay(wait);
  }

  for(uint16_t j=255; j>0; j--) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(j,0,j));
    }
    pixels.show();
  }
  for(uint16_t j=0; j<255; j++) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0,j,j));
    }
    pixels.show();
    delay(wait);
  }
  for(uint16_t j=255; j>50; j--) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0,j,j));
    }
    pixels.show();
    delay(wait);
  }
  for(uint16_t j=50; j<255; j++) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0,j,j));
    }
    pixels.show();
    delay(wait);
  }
  for(uint16_t j=255; j>0; j--) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0,j,j));
    }
    pixels.show();
  }
  for(uint16_t j=0; j<255; j++) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0,0,j));
    }
    pixels.show();
    delay(wait);
  }
  for(uint16_t j=255; j>50; j--) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0,0,j));
    }
    pixels.show();
    delay(wait);
  }
  for(uint16_t j=50; j<255; j++) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0,0,j));
    }
    pixels.show();
    delay(wait);
  }

  for(uint16_t j=255; j>0; j--) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0,0,j));
    }
    pixels.show();
  }
  for(uint16_t j=0; j<255; j++) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0,j,0));
    }
    pixels.show();
    delay(wait);
  }
  for(uint16_t j=255; j>50; j--) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0,j,0));
    }
    pixels.show();
    delay(wait);
  }
  for(uint16_t j=50; j<255; j++) {
    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0,j,0));
    }
    pixels.show();
    delay(wait);
  }
}
void Manual(uint16_t wait) {
  Plate1_Top(pixels.Color(0, 0, 0)); 
  Plate2_Top(pixels.Color(0, 0, 0));
  Plate3_Top(pixels.Color(0, 0, 0));
  Plate1_Bottom(pixels.Color(0, 0, 0)); 
  Plate2_Bottom(pixels.Color(0, 0, 0));
  Plate3_Bottom(pixels.Color(0, 0, 0));
  pixels.show();
  pixels.setPixelColor(0, pixels.Color(255,0,0));
  pixels.setPixelColor(34, pixels.Color(255,0,0));
  pixels.setPixelColor(7, pixels.Color(0,0,255));
  pixels.setPixelColor(26, pixels.Color(0,0,255));
  pixels.setPixelColor(8, pixels.Color(0,0,255));
  pixels.setPixelColor(52, pixels.Color(0,0,255));
  pixels.setPixelColor(16, pixels.Color(0,255,0));
  pixels.setPixelColor(44, pixels.Color(0,255,0));
  pixels.setPixelColor(17, pixels.Color(0,255,0));
  pixels.setPixelColor(43, pixels.Color(0,255,0));
  pixels.setPixelColor(25, pixels.Color(255,0,0));
  pixels.setPixelColor(35, pixels.Color(255,0,0));
  pixels.show();
  delay(wait);
}
//Plate1 = Right
void Plate1_Bottom(uint32_t c) {
  for(uint16_t i=0; i<8; i++) {
    pixels.setPixelColor(i, c);
  }
}
void Plate1_Top(uint32_t c) {
  for(uint16_t i=26; i<35; i++) {
    pixels.setPixelColor(i, c);
  }
}
//Plate2 = Center Front
void Plate2_Bottom(uint32_t c) {
  for(uint16_t i=8; i<17; i++) {
    pixels.setPixelColor(i, c);
  }
}
void Plate2_Top(uint32_t c) {
  for(uint16_t i=44; i<53; i++) {
    pixels.setPixelColor(i, c);
  }
}
//Plate3 = Left
void Plate3_Bottom(uint32_t c) {
  for(uint16_t i=17; i<26; i++) {
    pixels.setPixelColor(i, c);
  }
}
void Plate3_Top(uint32_t c) {
  for(uint16_t i=35; i<44; i++) {
    pixels.setPixelColor(i, c);
  }
}

