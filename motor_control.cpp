#include "motor_control.h"

// Motor Control Definitions
void move_forward(void)
{
    digitalWrite(motor_IN1, HIGH);
    analogWrite(motor_IN2, 90);
    digitalWrite(motor_IN3, LOW);
    analogWrite(motor_IN4, 90);
}

void move_backward(void)
{
    digitalWrite(motor_IN1, LOW);
    analogWrite(motor_IN2, 90);
    digitalWrite(motor_IN3, HIGH);
    analogWrite(motor_IN4, 90);
}

void brake(void)
{
    digitalWrite(motor_IN1, LOW);
    digitalWrite(motor_IN2, LOW);
    digitalWrite(motor_IN3, LOW);
    digitalWrite(motor_IN4, LOW);
}

void turn_right(void)
{
    digitalWrite(motor_IN2, LOW);
    digitalWrite(motor_IN3, LOW);
    analogWrite(motor_IN4, 90);
}

void turn_left(void)
{
    digitalWrite(motor_IN1, HIGH);
    analogWrite(motor_IN2, 90);
    digitalWrite(motor_IN4, LOW);
}

int degree(int degree)
{
    obstacle.write(degree);
    delay(500);
    int distance = getDistance(EchoPin1, TrigPin1);
    delay(200);
    return distance;
}

int getDistance(int EchoPin, int TrigPin)
{
    long pulseDuration;
    digitalWrite(TrigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin, LOW);

    pulseDuration = pulseIn(EchoPin, HIGH);
    return pulseDuration / 58;  // Convert to cm
}
