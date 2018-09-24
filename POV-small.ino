#include "data.h"
#include <avr/pgmspace.h>
#include <Adafruit_NeoPixel.h>

#define PIN            6
unsigned long current_time;
unsigned long prev_time = 0;
int time_dif;
unsigned long prev_time2;
int cnt;
int HigherPointer;
int Pointer;
#define NUMPIXELS      20
#define Sensor 4
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  HigherPointer = radialPixels/4;
  Pointer = (3*radialPixels)/4;
 pinMode(Sensor, INPUT_PULLUP);
pixels.begin();
}

void loop() {
  //Read Sensor
  if(digitalRead(Sensor)==0&& (millis()-prev_time)>(50)){
    current_time = millis();
    time_dif = current_time-prev_time;
    prev_time = current_time;
  HigherPointer = radialPixels/4;
  Pointer = (3*radialPixels)/4;
    }
    

//SetPixel:
//Check for time
if(millis()-prev_time2 > time_dif/radialPixels ){
  prev_time2 = millis();
// update pixels
cnt = 0;
for(int i=(NUMPIXELS/2)-1;i>=0;i--){
//  uint8_t r = pgm_read_byte(&Pixels[Pointer][i][0]);
// uint8_t g = pgm_read_byte(&Pixels[Pointer][i][1]);
//  uint8_t b = pgm_read_byte(&Pixels[Pointer][i][2]);
    pixels.setPixelColor(i, pixels.Color(Pixels[Pointer][i][0],Pixels[Pointer][i][1],Pixels[Pointer][i][2]));
      cnt++;

    }

for(int i = 0;i<=NUMPIXELS/2;i++){
//  uint8_t r = pgm_read_byte(&Pixels[HigherPointer][i][0]);
//uint8_t g = pgm_read_byte(&Pixels[HigherPointer][i][1]);
//  uint8_t b = pgm_read_byte(&Pixels[HigherPointer][i][2]);
    pixels.setPixelColor(i+(NUMPIXELS/2), pixels.Color(Pixels[HigherPointer][i][0],Pixels[HigherPointer][i][1],Pixels[HigherPointer][i][2]));

  }    pixels.show();

  //initialise Pointer
  if(HigherPointer >= (radialPixels)-1){
      HigherPointer = 0;
      
    } 
    else{
      HigherPointer++;
    }
  if(Pointer>=(radialPixels)-1){
   Pointer = 0;
  }
  else{
  Pointer++;
  }
}



 
  
 
}


  
