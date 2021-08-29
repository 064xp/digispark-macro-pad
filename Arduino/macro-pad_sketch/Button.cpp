#include "Button.h"
#include "TrinketHidCombo.h"

Button::Button(bool analog, int btnPin, unsigned long doublePressTime){
    isAnalog = analog;
    pin = btnPin;
    btnState = idle;
    doublePressDuration = doublePressTime;
    lastKeyUp = 0;
}

void Button::update(){
    if(btnState > 1)
        btnState = idle;

    if(btnState == pressPending && millis() - lastKeyUp > doublePressDuration){
        btnState = pressed;
    }
    
    isPressed = checkButtonPressed();

    if(!prevState && isPressed) {
        onKeyDown();
    } else if (prevState && !isPressed){
        onKeyUp();
    }
    prevState = isPressed;
}

void Button::onKeyDown(){
    // Not needed at the moment
}

void Button::onKeyUp(){
    btnState = pressPending;
    if(millis() - lastKeyUp < doublePressDuration){
        btnState = doublePressed;
        lastKeyUp = 0;
        return;
    } 

    lastKeyUp = millis();
}

bool Button::checkButtonPressed(){
    // Pin 5 (A0) is reset pin, to use it as GPIO
    // Place a resistor between push button and GND so that voltage never goes to 5v
    // Then analog read if the value is under a certain threshold to see if its pressed
    // https://forum.arduino.cc/t/useless-pin-5-in-all-digispark-attiny85-boards-solved/655868/10
    if(isAnalog){
        if(analogRead(pin) < 800){
            return true;
        }
    } else {
        if(digitalRead(pin) == HIGH)
            return true;
    }
    return false;
}