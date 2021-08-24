// #include "DigiKeyboard.h"
#include "TrinketHidCombo.h"


#define BTN1 1
#define BTN2 5

#define ENC_DT 0
#define ENC_CLK 2

int lastStateClk;

void setup() {                

  // Buttons
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);

  // Rotary Encoder
  // pinMode(ENC_SW, INPUT);
  pinMode(ENC_DT, INPUT);
  pinMode(ENC_CLK, INPUT);

  lastStateClk = digitalRead(ENC_CLK);

  // Trinket 
  TrinketHidCombo.begin();
}
// the loop routine runs over and over again forever:
void loop() {
  int btn1State = digitalRead(BTN1);
  int btn2State = analogRead(BTN2);

  if(btn1State == HIGH){
    // DigiKeyboard.println("Button 1 Pressed");
    TrinketHidCombo.println("Button 1 Pressed");
  }


  // Pin 5 (A0) is reset pin, to use it as GPIO
  // Place a resistor between push button and GND so that voltage never goes to 5v
  // Then analog read if the value is under a certain threshold to see if its pressed
  // https://forum.arduino.cc/t/useless-pin-5-in-all-digispark-attiny85-boards-solved/655868/10
  if(analogRead(A0) < 800){
    // DigiKeyboard.println("Button 3 Pressed");
    TrinketHidCombo.println("Button 2 Pressed");
  }

  encodeVolume();
  TrinketHidCombo.poll(); 
}

void encodeVolume(){
  int currentStateClk = digitalRead(ENC_CLK);
  // int btnState = digitalRead(ENC_SW);

  if(currentStateClk != lastStateClk && currentStateClk == 1){
    if(digitalRead(ENC_DT) != currentStateClk){
      // Rotating Counter clock wise
      // Decrease volume
      TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_UP);
      // DigiKeyboard.println("Decrease Volume");
    } else {
      // Rotating Clock wise
      // Increase volume
      TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN);
      // DigiKeyboard.println("Increase Volume");
    }
  }

  lastStateClk = currentStateClk;
}