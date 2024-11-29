# Smart Garbage Collection Robot
<img src="https://github.com/user-attachments/assets/e3e5884f-0481-4a27-a731-b56475fc3ef3" alt="Garbage Collect2" width="300" height="300">
<br>

### Overview
As part of the Introduction to Engineering Design module in Year 1 of Singapore Polytechnic's Computer Engineering program, the Smart Garbage Collection Robot is an autonomous robotic system designed to optimize waste management and recycling in urban environments. This project integrates advanced technologies such as ultrasonic sensors, infrared sensors, and servo-driven mechanics to detect, collect, and categorize recyclable and non-recyclable waste. By automating waste collection, this robot contributes to sustainability efforts and improves waste management efficiency, particularly in campuses or urban settings.
<br>
<br>
<br>

### Project Features
- Autonomous Garbage Collection: The robot can navigate and detect waste using an ultrasonic sensor for obstacle avoidance and an infrared sensor for garbage detection.
- Recyclable vs Non-Recyclable Sorting: Using a combination of mechanical claws and an arm extension, the robot collects waste and sorts it into recyclable and non-recyclable categories.
- User-Friendly Display: A real-time LCD display shows the number of recyclable and non-recyclable items collected, offering insights into the robot's progress.
- Efficient Navigation: The robot can move forward, backward, and turn based on real-time sensor data to avoid obstacles and navigate toward waste items.
<br>

### Technology Stack
- Arduino IDE: The robot is built using an Arduino platform, leveraging the powerful libraries for servo control, ultrasonic sensors, and LCD integration.
- Sensors: Ultrasonic sensor (HC-SR04) for distance measurement and infrared sensor (IR) for waste detection.
- Actuators: Servo motors for the arm and claw mechanisms that collect and release waste.
- LCD Display: A 16x2 LCD with I2C interface to display collected waste information.
- C++ Programming: The code is written in C++ using Arduino libraries for hardware control and sensor data processing.
<br>

### Key Components
- Arduino Uno: The main microcontroller that processes sensor data and controls actuators.
- Servo Motors: For controlling the robotic arm and claw for garbage collection and release.
- Ultrasonic Sensor (HC-SR04): Used for detecting obstacles and measuring the distance to waste objects.
- Infrared Sensor (IR): Detects the presence of garbage in the environment.
- LCD Screen: Displays real-time data about the collection process.
- Motor Drivers: Control the movement of the robot based on sensor inputs.
<br>

### How It Works
- Navigation: The robot moves autonomously using distance data from the ultrasonic sensor. If obstacles are detected, it will attempt to avoid them by turning or reversing.
- Waste Detection: The infrared sensor identifies waste objects. Once detected, the robot moves toward the waste.
- Sorting and Collection: The robot uses a servo-controlled claw and arm extension to pick up the waste. It categorizes the waste into recyclable or non-recyclable based on predefined criteria, storing each in a separate compartment.
- Real-Time Feedback: The LCD displays the number of recyclable and non-recyclable items collected, providing real-time feedback to the user.

<br>

### Contact
- Name: Khant Min San
- Email: khantkhant.23@ichat.sp.edu.sg

