// 03_pot_to_servo_direct.ino
// A 10K potentiometer's wiper feeds Mega A0, ADC reads 0-1023, map() scales to 0-180°,
// servo is commanded to that angle.
// Observation: servo follows pot rotation in real time. Wire on A0 slipping out caused
//              random servo motion due to electrical noise being mapped to angles
// Date: 11th May 2026

#include <Servo.h>

Servo myServo;
int potPin = A0;       // potentiometer wiper input

void setup() {
  myServo.attach(9);
  Serial.begin(9600);  // for monitoring the angle on Serial Monitor
}

void loop() {
  int potValue = analogRead(potPin);              // 10-bit ADC: 0-1023
  int angle = map(potValue, 0, 1023, 0, 180);     // scale linearly to 0-180°
  myServo.write(angle);                            // command servo
  Serial.println(angle);                           // print for debugging
  delay(15);
}
