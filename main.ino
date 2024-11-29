#include <Servo.h>
#include <LiquidCrystal_I2C.h>
//
// Motor Control Declarations
void move_forward(void);
void move_backward(void);
void brake(void);
void turn_right(void);
void turn_left(void);
int degree(int degree);
int getDistance(int EchoPin, int TrigPin);

// Garbage Collection Declarations
void collect_garbage();
void release_garbage(void);
void move_extension_down(int position);
void move_extension_up(int garbage_type);
int recyclable_garbage(void);
int non_recyclable_garbage(void);

// Sensor Management Declarations
int garbage_detector(void);
int IR_sensor(void);

// Display Declarations
void display(int a, int b);

// Pin Definitions
#define Hit_aPin 4   //define digital I/O pin D4 for Hit A
#define Hit_bPin 2   //define digital I/O pin D2 for Hit B
#define motor_IN2 6      //Connect to Arduino pin 6
#define motor_IN1 9          //Connect to Arduino pin 9
#define motor_IN4 3      //Connect to Arduino pin 3
#define motor_IN3 5          //Connect to Arduino pin 5
#define TrigPin1 8  // U/S1 Trig connected to pin 11
#define EchoPin1 7
#define garbage_sensorPin A0
#define garbage_outputPin A0
#define back_IR_sensor A1
#define back_IR_output A1

// Global Variables
Servo claw;
Servo obstacle;
Servo extension;

int arm_position = 180;
int garbage;

int counterA = 0;
int counterB = 0;

int hit_a, hit_b;

void setup()
{
    Serial.begin(9600);
    obstacle.attach(10);
    claw.attach(12);
    extension.attach(A2);

    lcd.init();
    lcd.begin(16, 2);
    lcd.backlight();
    lcd.clear();

    move_extension_up(180);
}

void loop()
{
    garbage = garbage_detector();
    while (garbage == 1)
    {
        move_forward();
        garbage = garbage_detector();
        Serial.println(garbage);
    }
    brake();

    int infront_obstacle = getDistance(EchoPin1, TrigPin1);
    if (infront_obstacle <= 20)
    {
        delay(1000);
        handle_obstacle();
    }
    else
    {
        delay(1000);
        obstacle.write(90);
        move_extension_down(arm_position);
        collect_garbage();
    }
}

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

// Garbage Collection Definitions
void collect_garbage()
{
    claw.write(0);
    delay(1000);
    claw.write(100);
    delay(1000);
}

void release_garbage(void)
{
    delay(700);
    claw.write(0);
    delay(2000);
}

void move_extension_down(int position)
{
    for (int i = position; i >= 0; i--)
    {
        extension.write(i);
        delay(20);
    }
    delay(1000);
}

void move_extension_up(int garbage_type)
{
    for (int i = 0; i <= garbage_type; i++)
    {
        extension.write(i);
        delay(20);
    }
    delay(1000);
}

int recyclable_garbage(void)
{
    int recyclable = counterA++;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Recyclable.");
    delay(1000);
    display(recyclable, counterB);
    move_extension_up(180);
    release_garbage();
    return recyclable;
}

int non_recyclable_garbage(void)
{
    int non_recyclable = counterB++;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NON-Recyclable.");
    delay(1000);
    display(counterA, non_recyclable);
    move_extension_up(155);
    release_garbage();
    return non_recyclable;
}

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

// Display Definitions
void display(int a, int b)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Recyclable:");
    lcd.print(a);
    lcd.setCursor(0, 1);
    lcd.print("Non-recyclable:");
    lcd.print(b);
}
