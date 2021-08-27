#include "TrinketHidCombo.h"
// TrinketHIDCombo functions and Key names
// https://github.com/adafruit/Adafruit-Trinket-USB/blob/master/TrinketHidCombo/TrinketHidCombo.h


#define BTN2 1
#define BTN1 5

#define ENC_DT 0
#define ENC_CLK 2

int lastStateClk;

void setup() {                

  // Buttons
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);

  // Rotary Encoder
  pinMode(ENC_DT, INPUT);
  pinMode(ENC_CLK, INPUT);

  lastStateClk = digitalRead(ENC_CLK);

  // Trinket HID Init
  TrinketHidCombo.begin();
}
// the loop routine runs over and over again forever:
void loop() {
  int btn1State = analogRead(BTN1);
  int btn2State = digitalRead(BTN2);

  if(btn2State == HIGH){
    TrinketHidCombo.println("Button 2 Pressed");
  }


  // Pin 5 (A0) is reset pin, to use it as GPIO
  // Place a resistor between push button and GND so that voltage never goes to 5v
  // Then analog read if the value is under a certain threshold to see if its pressed
  // https://forum.arduino.cc/t/useless-pin-5-in-all-digispark-attiny85-boards-solved/655868/10
  if(analogRead(A0) < 800){
    TrinketHidCombo.println("Button 1 Pressed");
  }

  encodeVolume();
  TrinketHidCombo.poll(); 
}

void encodeVolume(){
  int currentStateClk = digitalRead(ENC_CLK);

  if(currentStateClk != lastStateClk && currentStateClk == 1){
    if(digitalRead(ENC_DT) != currentStateClk){
      // Rotating Clock wise
      // Increase volume
      TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_UP);
    } else {
      // Rotating Counter clock wise
      // Decrease volume
      TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN);
    }
  }

  lastStateClk = currentStateClk;
}