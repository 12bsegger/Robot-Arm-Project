// 01_blink.ino
// Blinks the Mega's onboard LED (pin 13) at 1Hz.
// Date: 11th May 2026

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);   // LED_BUILTIN is pin 13 on the Mega
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // turn LED on
  delay(1000);                     // wait 1 second
  digitalWrite(LED_BUILTIN, LOW);  // turn LED off
  delay(1000);                     // wait 1 second
}
