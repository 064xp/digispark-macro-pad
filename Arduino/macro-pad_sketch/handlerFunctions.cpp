#include "handlerFunctions.h"
#include "Arduino.h"

/*
======================================================
    Modify this file for editing handler functions
======================================================
*/

// ===== Button 1 on press =====
void onBtn1Press(){
  TrinketHidCombo.println("Button 1 Pressed");
}

// ===== Button 1 on long press =====
void onBtn1LongPress(){
  TrinketHidCombo.println("Button 1 long press");
}

// ===== Button 2 on press =====
void onBtn2Press(){
  TrinketHidCombo.println("Button 2 Pressed");
}

// ===== Button 2 on long press =====
void onBtn2LongPress(){
  TrinketHidCombo.println("Button 2 long press");
}

// ===== Button 1 double press =====
void onBtn1DoublePress(){
  TrinketHidCombo.println("Button 1 double pressed");
}

// ===== Button 2 double press =====
void onBtn2DoublePress(){
  TrinketHidCombo.println("Button 2 double pressed");
}

// ===== Knob turn clock wise =====
void onKnobCW(){
    // Increase volume
    TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_UP);
}

// ===== Knob turn counter clock wise =====
void onKnobCCW(){
    TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN);
}


// ==== Helper functions ====

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
