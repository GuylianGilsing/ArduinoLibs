// Library by Guylian Gilsing
// Github: https://github.com/GuylianGilsing/ArduinoLibs

#ifndef ARDUINO_HARDWARE_FILE_BUTTON
#define ARDUINO_HARDWARE_FILE_BUTTON

enum ButtonType
{
    PULL_UP = 0,
    PULL_DOWN = 1,
    RAW_READING = 2
};

namespace ArduinoHardware
{
    class Button
    {
    private:
        int pin = 0;
        ButtonType buttonState = ButtonType::RAW_READING;

        bool pullUpButtonClickRegistered = false;
        bool pullDownButtonClickRegistered = false;

    public:
        // Normal constructor
        Button(int a_pin, ButtonType a_buttonType = ButtonType::RAW_READING)
        {
            this->pin = a_pin;
            this->buttonState = a_buttonType;

            pinMode(this->pin, INPUT);   
        }

        bool IsPressed()
        {
            bool pressed = false;

            int buttonReading = digitalRead(this->pin);

            switch(this->buttonState)
            {
                case ButtonType::PULL_UP:
                    pressed = this->isPressedPullUp(buttonReading);
                break;

                case ButtonType::PULL_DOWN:
                    pressed = this->isPressedPullDown(buttonReading);
                break;

                // Default is ButtonType::RAW_READING
                default:
                    pressed = this->isPressedRaw(buttonReading);
                break;
            }

            return pressed;
        }

    private:
        bool isPressedPullUp(int a_buttonReading)
        {
            bool isPressed = false;

            if(a_buttonReading == HIGH && this->pullUpButtonClickRegistered == false)
            {
                isPressed = true;
                this->pullUpButtonClickRegistered = true;
            }

            if(this->pullUpButtonClickRegistered && a_buttonReading == LOW)
                this->pullUpButtonClickRegistered = false;

            return isPressed;
        }

        bool isPressedPullDown(int a_buttonReading)
        {
            bool isPressed = false;

            if(a_buttonReading == HIGH && this->pullDownButtonClickRegistered == false)
                this->pullDownButtonClickRegistered = true;

            if(a_buttonReading == LOW && this->pullDownButtonClickRegistered == true)
            {
                this->pullDownButtonClickRegistered = false;
                isPressed = true;
            }

            return isPressed;
        }

        bool isPressedRaw(int a_buttonReading)
        {
            bool isPressed = false;

            if(a_buttonReading == HIGH)
                isPressed = true;

            return isPressed;
        }
    };
}

#endif