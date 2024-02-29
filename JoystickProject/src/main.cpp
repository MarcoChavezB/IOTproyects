#include <Arduino.h>
#include <Servo.h>

// Joystick
const int xPin = A2;
const int yPin = A1;
const int switchPin = 2;

// motores
int leftMotorPin = 11;
int rightMotorPin = 12;
Servo leftMotor;
Servo rightMotor;

int ledPin = 3;

void setup() {
  pinMode(leftMotorPin, OUTPUT);
  pinMode(rightMotorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); 
  leftMotor.attach(leftMotorPin);
  rightMotor.attach(rightMotorPin);
}


void leftMotorControl(int value) {
  leftMotor.write(map(value, -100, 100, 1000, 2000));
}

void rightMotorControl(int value) {
  rightMotor.write(map(value, -100, 100, 1000, 2000));
}

void adelante() {
  Serial.print("Adelante");
  leftMotorControl(100);
  rightMotorControl(-100);
}

void atras() {
  Serial.println("Atras");
  leftMotorControl(-100);
  rightMotorControl(100);
}

void izquierda() {
  Serial.println("Izquierda");
  leftMotorControl(-100);
  rightMotorControl(100);
}

void derecha() {
  Serial.println("Derecha");
  leftMotorControl(100);
  rightMotorControl(-100);
}

void detener() {
  leftMotorControl(0);
  rightMotorControl(0);
}
void readJoystick() {
  int xValue = analogRead(xPin);
  int yValue = analogRead(yPin);
  int switchValue = digitalRead(switchPin);

  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" Y: ");
  Serial.print(yValue);
  Serial.print(" Switch: ");
  Serial.println(switchValue);
// mayor a 500 es adelante
  if (xValue > 500) {
    adelante();
  } else if (xValue < 400) {
    atras();
  } else if (yValue > 500) {
    derecha();
  } else if (yValue < 400) {
    izquierda();
  } else if(xValue > 400 && xValue < 500 && yValue > 400 && yValue < 500) {
    detener();
  }else if(switchValue == 0){
    digitalWrite(ledPin, HIGH);
}

void loop() {
  readJoystick();
  delay(100);
}
