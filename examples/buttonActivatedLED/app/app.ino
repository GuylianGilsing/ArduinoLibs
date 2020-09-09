#include "Arduino.h"

// Include the button code from the library
#include "ArduinoHardware/button.hpp"

// Include the LED code from the library
#include "ArduinoHardware/led.hpp"

// Aliases the "ArduinoHardware" namespace to "ah"
namespace ah = ArduinoHardware;

// Configures an OUTPUT LED on pin 2
ah::LED testLed = ah::LED(2);

// Configures an INPUT button on pin 4
ah::Button btnActivateLed = ah::Button(4, ButtonType::RAW_READING);

void setup()
{
    Serial.begin(9600);
    Serial.println("Serial port is working");
}

void loop()
{
    if(btnActivateLed.IsPressed())
    {
        testLed.SetHigh();
    }
    else
    {
        testLed.SetLow();
    }
}