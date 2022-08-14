// Obstacle avoidance robot with three ultrasonic sensors

//Include the motor driver library
#include <AFMotor.h>
//Define the sensor pins
#define S1Trig A4
#define S2Trig A2
#define S3Trig A0
#define S1Echo A5
#define S2Echo A3
#define S3Echo A1
//Set the speed of the motors
#define Speed 160

//Create objects for the motors
AF_DCMotor motorBackRight(1);
AF_DCMotor motorFrontRight(2);
AF_DCMotor motorFrontLeft(3);
AF_DCMotor motorBackLeft(4);

void setup() {
  Serial.begin(9600);
  //Set the Trig pins as output pins
  pinMode(S1Trig, OUTPUT);
  pinMode(S2Trig, OUTPUT);
  pinMode(S3Trig, OUTPUT);
  //Set the Echo pins as input pins
  pinMode(S1Echo, INPUT);
  pinMode(S2Echo, INPUT);
  pinMode(S3Echo, INPUT);
  //Set the speed of the motors
}

void loop() {
  int centerSensor = sensorTwo();
  int leftSensor = sensorOne();
  int rightSensor = sensorThree();
// Check the distance using the IF condition

  if (8 >= rightSensor) {
    belki();
    delay(50);
    Serial.println("Belok kiri");
    delay(50);
    }
   else if (8 >= leftSensor) {
    belka();
    delay(50);
    Serial.println("Belok Kanan");
    delay(50);
    }
  
  if(25 >= centerSensor) {
    Stop();
    Serial.println("Stop");
    delay(500);
    if (leftSensor > rightSensor) {
      left();
      Serial.println("Left");
      delay(500);
    } else {
      right();
      Serial.println("Right");
      delay(500);
    }
  }
  Serial.println("Forward");
  forward();
}

//Get the sensor values
int sensorOne() {
  //pulse output
  digitalWrite(S1Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(S1Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(S1Trig, LOW);

  long t = pulseIn(S1Echo, HIGH);//Get the pulse
  int cm = t / 29 / 2; //Convert time to the distance
  Serial.println(cm);
  return cm; // Return the values from the sensor
}

//Get the sensor values
int sensorTwo() {
  //pulse output
  digitalWrite(S2Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(S2Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(S2Trig, LOW);

  long t = pulseIn(S2Echo, HIGH);//Get the pulse
  int cm = t / 29 / 2; //Convert time to the distance
  Serial.println(cm);
  return cm; // Return the values from the sensor
}

//Get the sensor values
int sensorThree() {
  //pulse output
  digitalWrite(S3Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(S3Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(S3Trig, LOW);

  long t = pulseIn(S3Echo, HIGH);//Get the pulse
  int cm = t / 29 / 2; //Convert time to the distance
  Serial.println(cm);
  return cm; // Return the values from the sensor
}

/*******************Motor functions**********************/
void belki(){                 
  // Oblique left
  motorBackRight.run(FORWARD);
  motorFrontRight.run(FORWARD);
  motorFrontLeft.run(FORWARD);
  motorBackLeft.run(FORWARD);
  motorBackRight.setSpeed(Speed + 25);
  motorFrontRight.setSpeed(Speed + 25);
  motorFrontLeft.setSpeed(Speed);
  motorBackLeft.setSpeed(Speed);
}
void belka(){
  // Oblique Right
  motorBackRight.run(FORWARD);
  motorFrontRight.run(FORWARD);
  motorFrontLeft.run(FORWARD);
  motorBackLeft.run(FORWARD);
  motorBackRight.setSpeed(Speed);
  motorFrontRight.setSpeed(Speed);
  motorFrontLeft.setSpeed(Speed + 25);
  motorBackLeft.setSpeed(Speed + 25);
}
void forward() {
  motorBackRight.run(FORWARD);
  motorFrontRight.run(FORWARD);
  motorFrontLeft.run(FORWARD);
  motorBackLeft.run(FORWARD);
  motorBackRight.setSpeed(Speed);
  motorFrontRight.setSpeed(Speed);
  motorFrontLeft.setSpeed(Speed);
  motorBackLeft.setSpeed(Speed);
}
void right() {
  // Turn Right
  motorBackRight.run(BACKWARD);
  motorFrontRight.run(BACKWARD);
  motorFrontLeft.run(FORWARD);
  motorBackLeft.run(FORWARD);
  motorBackRight.setSpeed(Speed);
  motorFrontRight.setSpeed(Speed);
  motorFrontLeft.setSpeed(Speed);
  motorBackLeft.setSpeed(Speed);
}
void left() {
  motorBackRight.run(FORWARD);
  motorFrontRight.run(FORWARD);
  motorFrontLeft.run(BACKWARD);
  motorBackLeft.run(BACKWARD);
  motorBackRight.setSpeed(Speed);
  motorFrontRight.setSpeed(Speed);
  motorFrontLeft.setSpeed(Speed);
  motorBackLeft.setSpeed(Speed);
}
void Stop() {
  motorBackRight.run(RELEASE);
  motorFrontRight.run(RELEASE);
  motorFrontLeft.run(RELEASE);
  motorBackLeft.run(RELEASE);
}
