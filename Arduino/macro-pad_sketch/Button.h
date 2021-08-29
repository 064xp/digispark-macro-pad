#ifndef BUTTON_H
#define BUTTON_H
#include "Arduino.h"

enum btnStates {idle, pressPending, pressed, doublePressed};

class Button{
    private:
        unsigned long lastKeyUp;
        unsigned long doublePressDuration;
        bool isAnalog;
        bool isPressed;
        char pin;
        bool prevState;

        void onKeyDown();
        void onKeyUp();
        bool checkButtonPressed();
    public:
        Button(bool analog, int btnPin, unsigned long doublePressTime);
        void update();
        btnStates btnState;
};

#endif