// Library by Guylian Gilsing
// Github: https://github.com/GuylianGilsing/ArduinoLibs

#ifndef ARDUINO_HARDWARE_FILE_BUTTON
#define ARDUINO_HARDWARE_FILE_BUTTON

namespace ArduinoHardware
{
    class Button
    {
    private:
        int pin = 0;

    public:
        // Normal constructor
        Button(int a_pin)
        {
            this->pin = a_pin;
            pinMode(this->pin, INPUT);   
        }

        bool IsPressed()
        {
            bool pressed = false;

            if(digitalRead(this->pin) == HIGH)
                pressed = true;

            return pressed;
        }
    };
}

#endif