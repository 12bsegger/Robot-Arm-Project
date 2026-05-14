// 02_sg90_sweep_direct.ino
// Basic servo control test.
// Drives an SG90 micro servo directly from the Mega's PWM pin 9 using the Servo.h library.
// Servo sweeps from 0° to 180° and back continuously.
// Observation: SG90 produced ~160° of range
// Date: 11th May 2026

#include <Servo.h>

Servo myServo;       // create servo object

void setup() {
  myServo.attach(9); // attach servo signal wire to digital pin 9
}

void loop() {
  // Sweep from 0° to 180°
  for (int pos = 0; pos <= 180; pos++) {
    myServo.write(pos);    // command servo to position
    delay(15);             // wait 15ms to allow servo to reach position
  }
  // Sweep back from 180° to 0°
  for (int pos = 180; pos >= 0; pos--) {
    myServo.write(pos);
    delay(15);
  }
}
