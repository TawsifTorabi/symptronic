#include <ESP8266WiFi.h>

#define LEFT_SENSOR 5
#define RIGHT_SENSOR 4


#define LEFT_MOTOR_FORWARD 0
#define LEFT_MOTOR_BACKWARD 2

#define RIGHT_MOTOR_FORWARD 14
#define RIGHT_MOTOR_BACKWARD 12

void setup() {
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);
  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
  pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  bool left_detected = digitalRead(LEFT_SENSOR) == LOW;
  bool right_detected = digitalRead(RIGHT_SENSOR) == LOW;

  if (left_detected && !right_detected) {
    moveRight();
  } else if (!left_detected && right_detected) {
    moveLeft();
  } else if (!left_detected && !right_detected) {
    moveForward();
  } else {
    stop();
  }

  delay(10);
}

void moveForward() {
  digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
  digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
  digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
}

void moveLeft() {
  digitalWrite(LEFT_MOTOR_FORWARD, LOW);
  digitalWrite(LEFT_MOTOR_BACKWARD, HIGH);
  digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
  digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
}

void moveRight() {
  digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
  digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_MOTOR_BACKWARD, HIGH);
}

void stop() {
  digitalWrite(LEFT_MOTOR_FORWARD, LOW);
  digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
}
