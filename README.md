# ArduinoLibs
A collection of self-written arduino libraries that I use for my school projects

## ArduinoHardware
ArduinoHardware offers a high-level syntax for cleaner code when working with hardware like buttons and LEDs.
### LED
The LED class makes it easy to turn your LED on or off.
```cpp
// Include the LED code from the library
#include "ArduinoHardware/led.hpp"

// Aliases the "ArduinoHardware" namespace to "ah"
namespace ah = ArduinoHardware;

// Register a new LED on pin 4
ah::LED testLED = ah::LED(4);

// Set the LED pin to HIGH
testLed.SetHigh();

// Set the LED pin to LOW
testLed.SetLow();
```

### Button
The button class makes it easier to work with buttons.
```cpp
// Include the button code from the library
#include "ArduinoHardware/button.hpp"

// Aliases the "ArduinoHardware" namespace to "ah"
namespace ah = ArduinoHardware;

// Register a button on pin 4
ah::Button testButton = ah::Button(4, ah::ButtonType::RAW_READING);

// Check if the button is pressed
if(testButton.IsPressed())
{
    // Do stuff...
}
```
The button class has 3 types:

**RAW_READING (default)**<br/>
Makes the `IsPressed()` function return true when the voltage is HIGH.

**PULL_UP**<br/>
Makes the `IsPressed()` function return true once when the button is physically pressed.

**PULL_DOWN**<br/>
Makes the `IsPressed()` function return true once after the button has been physically pressed.