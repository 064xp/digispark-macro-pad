#ifndef HANDLER_FUNCS_H
#define HANDLER_FUNCS_H

#include "TrinketHidCombo.h"
// TrinketHIDCombo functions and Key names
// https://github.com/adafruit/Adafruit-Trinket-USB/blob/master/TrinketHidCombo/TrinketHidCombo.h

void onBtn1Press();
void onBtn1LongPress();
void onBtn2Press();
void onBtn2LongPress();
void onBtn1DoublePress();
void onBtn2DoublePress();
void onKnobCW();
void onKnobCCW();
void pollWait(int time);

#endif