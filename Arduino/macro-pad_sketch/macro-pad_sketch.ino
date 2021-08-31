#include "Button.h"
#include "handlerFunctions.h"
#include "TrinketHidCombo.h"

#define BTN1 A0
#define BTN2 1

#define ENC_DT 0
#define ENC_CLK 2

char lastStateClk;
Button btn1(
  true, 
  BTN1,
  onBtn1Press,
  onBtn1DoublePress,
  onBtn1LongPress 
);

Button btn2(
  false, 
  BTN2,
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
  char currentStateClk = digitalRead(ENC_CLK);
  char currentDT = digitalRead(ENC_DT);

  if(currentStateClk != lastStateClk){
    if(currentDT != currentStateClk){
      // Rotating Clock wise
      onKnobCW();
    } else {
      // Rotating Counter clock wise
      onKnobCCW();
    }
  }

  lastStateClk = currentStateClk;
}
