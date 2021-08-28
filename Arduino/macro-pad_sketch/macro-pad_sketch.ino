#include "TrinketHidCombo.h"
// TrinketHIDCombo functions and Key names
// https://github.com/adafruit/Adafruit-Trinket-USB/blob/master/TrinketHidCombo/TrinketHidCombo.h

#define BTN2 1
#define BTN1 5

#define ENC_DT 0
#define ENC_CLK 2

int lastStateClk;

// ===== Button 1 on click =====
void onBtn1Press(){
  TrinketHidCombo.println("Button 1 Pressed");
}

// ===== Button 2 on click =====
void onBtn2Press(){
  TrinketHidCombo.println("Button 2 Pressed");
}

// ===== Both buttons pressed at same time =====
void onBothPress(){
  TrinketHidCombo.println("Both buttons pressed");
}


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
  bool btn1Pressed = false;
  bool btn2Pressed = false;

  // Pin 5 (A0) is reset pin, to use it as GPIO
  // Place a resistor between push button and GND so that voltage never goes to 5v
  // Then analog read if the value is under a certain threshold to see if its pressed
  // https://forum.arduino.cc/t/useless-pin-5-in-all-digispark-attiny85-boards-solved/655868/10
  if(analogRead(A0) < 800){
    btn1Pressed = true;
  }

  if(btn2State == HIGH){
    btn2Pressed = true;
  }

  if(btn1Pressed && btn2Pressed){
    onBothPress();
  } else if(btn1Pressed){
    onBtn1Press();
  } else if(btn2Pressed){
    onBtn2Press();
  }

  encodeVolume();
  pollWait(80);
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

/*
  Sleep for a certain amount of miliseconds
  Poll every ms to sustain USB connection
*/
void pollWait(int time){
  int counter;
  for(counter = 0; counter<time; counter++){
    delay(1);
    counter++;
    TrinketHidCombo.poll();
  }
}