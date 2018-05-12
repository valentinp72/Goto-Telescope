#include "Motor.cpp"


#define PIN_EMERGENCY 2


Motor motor1(7, 8, 11);

void emergencyChange() {
	bool value = !digitalRead(PIN_EMERGENCY);
	pinMode(13, OUTPUT);
	digitalWrite(13, value);
	motor1.emergencyStop(value);
}

void setup() {
	pinMode(PIN_EMERGENCY, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(PIN_EMERGENCY), emergencyChange, CHANGE);
}

void loop() {
	motor1.configurationTest();
}
