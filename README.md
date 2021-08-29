# Digispark Attiny85 Macro Pad

Small macro pad based on the Digispark Attiny85 dev board with 2 programmable buttons and a rotary encoder volume knob.

## Schematic 
<img src="schematic/schematic.png" width="500">

## Set up

1. Follow [this tutorial](http://digistump.com/wiki/digispark/tutorials/connecting) to install the Arduino IDE and digispark libraries/drivers.
2. Install the **Pro Trinket USB Keyboard Library** from the Library manager in the Arduino IDE.

    2.1. Tools > Manage Libraries > Search for **Pro Trinket USB Keyboard Library**
3. Clone this repository
4. Open *digispark-macro-pad/Arduino/macro-pad_sketch/macro-pad_sketch.ino* in the Arduino IDE.
5. Hit the upload button, wait for the 
`Plug in device now... (will timeout in 60 seconds)`
message in the console, then plug in your Digispark into a usb port.
    
    5.1 It's important that you don't plug it in before this message appears, otherwise, it will fail to upload.

## Code
This project uses the [TrinketHidCombo](https://github.com/adafruit/Adafruit-Trinket-USB/tree/master/TrinketHidCombo) library for emulating a HID device.

See [TrinketHidCombo.h](https://github.com/adafruit/Adafruit-Trinket-USB/blob/master/TrinketHidCombo/TrinketHidCombo.h) for the list of available methods and key names.

### Gestures
The available gestures are:
- Button 1 short press
- Button 1 long press
- Button 1 double press
- Button 2 short press
- Button 2 long press
- Button 2 double press
- Rotary encoder clockwise
- Rotary encoder counter clockwise

To edit the behaviour of these, edit the [hanlderFunctions.cpp](https://github.com/064xp/digispark-macro-pad/blob/main/Arduino/macro-pad_sketch/handlerFunctions.cpp) file.
