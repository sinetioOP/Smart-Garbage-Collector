#include "sensor_management.h"

// Sensor Management Definitions
int garbage_detector(void)
{
    int sensor_value = digitalRead(garbage_sensorPin);

    if (sensor_value == LOW) { // LOW MEANS Object Detected
        digitalWrite(garbage_outputPin, HIGH);
    }
    else
    {
        digitalWrite(garbage_outputPin, LOW);
    }
    return sensor_value;
}

int IR_sensor(void)
{
    int sensor_value = digitalRead(back_IR_sensor);

    if (sensor_value == LOW) { // LOW MEANS Object Detected
        digitalWrite(back_IR_output, HIGH);
    }
    else
    {
        digitalWrite(back_IR_output, LOW);
    }
    return sensor_value;
}
