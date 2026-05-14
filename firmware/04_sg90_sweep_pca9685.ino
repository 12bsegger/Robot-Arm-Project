// 04_sg90_sweep_pca9685.ino
// Same SG90 sweep as 02, but routed through the PCA9685 16-channel PWM driver via I²C
// instead of using a Mega PWM pin directly.
// Calibration: SERVOMIN=100, SERVOMAX=650 yields ~170° mechanical range 
// Defaults of 150/600 produced a narrower sweep.
// Note: for this test, servo power is taken from the PCA9685's V+ header pin
// (jumpered to the breadboard +5V rail). Workaround until screwdriver is acquired
// to use the screw terminal. Only acceptable for low-current SG90 testing.
// Date: 14th May 2026

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();  // default I²C address 0x40

#define SERVOMIN 100         // pulse length (12-bit ticks) for ~0° position
#define SERVOMAX 650         // pulse length for ~170° position
#define SERVO_CHANNEL 0      // channel on the PCA9685 (0-15)

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);        // 50Hz refresh rate, standard for analog servos
  delay(10);
}

void loop() {
  // Sweep from SERVOMIN to SERVOMAX
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    pwm.setPWM(SERVO_CHANNEL, 0, pulselen);  // (channel, pulse_on_tick, pulse_off_tick)
  }
  delay(500);
  // Sweep back
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(SERVO_CHANNEL, 0, pulselen);
  }
  delay(500);
}
