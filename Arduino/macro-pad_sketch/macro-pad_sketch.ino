#include "Button.h"
#include "handlerFunctions.h"
#include "TrinketHidCombo.h"

#define BTN1 A0
#define BTN2 1

#define ENC_DT 0
#define ENC_CLK 2

// Time in between button presses to consider it a double press
#define PRESS_TIMER 230
#define LONG_PRESS_TIMER 650

int lastStateClk;
Button btn1(
  true, 
  BTN1, 
  PRESS_TIMER,
  LONG_PRESS_TIMER,
  onBtn1Press,
  onBtn1DoublePress,
  onBtn1LongPress 
);

Button btn2(
  false, 
  BTN2, 
  PRESS_TIMER,
  LONG_PRESS_TIMER,
  onBtn2Press,
  onBtn2DoublePress,
  onBtn2LongPress 
);

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
  encodeVolume();
  TrinketHidCombo.poll();
}

void encodeVolume(){
  int currentStateClk = digitalRead(ENC_CLK);

  if(currentStateClk != lastStateClk){
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
