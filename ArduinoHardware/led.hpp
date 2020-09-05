#ifndef ARDUINO_HARDWARE_FILE_LED
#define ARDUINO_HARDWARE_FILE_LED

namespace ArduinoHardware
{
    class LED
    {
    private:
        int pin = 0;
        int voltage = LOW;

    public:
        LED(int a_pin)
        {
            this->pin = a_pin;
        }

        void SetHigh()
        {
            this->voltage = HIGH;
            UpdateVoltage();
        }

        void SetLow()
        {
            this->voltage = LOW;
            UpdateVoltage();
        }

    private:
        void UpdateVoltage()
        {
            digitalWrite(this->pin, this->voltage);
        }
    };
}

#endif