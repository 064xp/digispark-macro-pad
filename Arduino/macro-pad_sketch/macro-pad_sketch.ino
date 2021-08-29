#include "Button.h"
#include "handlerFunctions.h"
#include "TrinketHidCombo.h"

#define BTN1 A0
#define BTN2 1

#define ENC_DT 0
#define ENC_CLK 2

// Time in between button presses to consider it a double press
#define PRESS_TIMER 230

int lastStateClk;
Button btn1(true, BTN1, PRESS_TIMER);
Button btn2(false, BTN2, PRESS_TIMER);


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

void loop() {
  btn1.update();
  btn2.update();
  handleButtonGestures();
  encodeVolume();
  pollWait(70);
}

void handleButtonGestures(){
  // === Call gesture handlers === 
  if(btn1.btnState == pressed && btn2.btnState == pressed){
    onBothPress();
  } else if(btn1.btnState == doublePressed){
    onBtn1DoublePress();
  } else if(btn2.btnState == doublePressed) {
    onBtn2DoublePress();
  } else if(btn1.btnState == pressed){
    onBtn1Press();
  } else if(btn2.btnState == pressed){
    onBtn2Press();
  }
}

void encodeVolume(){
  int currentStateClk = digitalRead(ENC_CLK);

  if(currentStateClk != lastStateClk && currentStateClk == 1){
    if(digitalRead(ENC_DT) != currentStateClk){
      // Rotating Clock wise
      onKnobCW();
    } else {
      // Rotating Counter clock wise
      onKnobCCW();
    }
  }

  lastStateClk = currentStateClk;
}

/*
  Sleep for a certain amount of milliseconds
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