#include "handlerFunctions.h"
/*
======================================================
    Modify this file for editing handler functions
======================================================
*/

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