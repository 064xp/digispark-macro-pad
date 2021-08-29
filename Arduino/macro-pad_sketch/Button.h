#ifndef BUTTON_H
#define BUTTON_H
#include "Arduino.h"

enum btnStates {idle, pressPending, pressed, doublePressed};

class Button{
    private:
        unsigned long lastKeyUp;
        unsigned long lastKeyDown;
        unsigned long doublePressDuration;
        unsigned long longPressDuration;
        bool isAnalog;
        bool isPressed;
        char pin;
        bool prevState;
        void (*onPress) (void);
        void (*onDoublePress) (void);
        void (*onLongPress) (void);

        void onKeyDown();
        void onKeyUp();
        bool checkButtonPressed();
    public:
        Button(
            bool analog, 
            int btnPin, 
            unsigned long doublePressTime,
            unsigned long longPressTime,
            void (*onPress) (void),
            void (*onDoublePress) (void),
            void (*onLongPress) (void)
            );
        void update();
        btnStates btnState;
};

#endif