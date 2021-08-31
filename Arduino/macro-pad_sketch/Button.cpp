#include "Button.h"
#include "TrinketHidCombo.h"

Button::Button(
    bool analog,
    char btnPin, 
    void (*onPress) (void),
    void (*onDoublePress) (void),
    void (*onLongPress) (void)
){
    this->isAnalog = analog;
    this->pin = btnPin;
    this->btnState = idle;
    this->lastKeyUp = 0;

    this->onPress = onPress;
    this->onDoublePress = onDoublePress;
    this->onLongPress = onLongPress;
}

void Button::update(){
    // If double press timeout has expired, and the button was pressed
    // Check if it was a long or short press
    if(btnState == pressPending && millis() - lastKeyUp > DOUBLE_PRESS_TIME){
        if(lastKeyUp - lastKeyDown < LONG_PRESS_TIME)
            onPress();
        else 
            onLongPress();
        btnState = idle;
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
    lastKeyDown = millis();
}

void Button::onKeyUp(){
    btnState = pressPending;
    // Double press
    if(millis() - lastKeyUp < DOUBLE_PRESS_TIME){
        btnState = idle;
        onDoublePress();
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
