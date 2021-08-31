#ifndef BUTTON_H
#define BUTTON_H
#include "Arduino.h"

#define DOUBLE_PRESS_TIME 230
#define LONG_PRESS_TIME 650

enum btnStates {idle, pressPending};

class Button{
    private:
        unsigned long lastKeyUp;
        unsigned long lastKeyDown;
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
            char btnPin,
            void (*onPress) (void),
            void (*onDoublePress) (void),
            void (*onLongPress) (void)
            );
        void update();
        btnStates btnState;
};

#endif
