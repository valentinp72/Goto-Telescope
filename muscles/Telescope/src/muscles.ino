/*#include "Motor.cpp"


#define PIN_EMERGENCY 2
#define PIN_START 3

#define LED_STOPPED A8
#define LED_STARTED A9

Motor motor1(7, 8, 11);

bool started = false;
bool emergen = false;

void emergencyChange() {
	emergen = !digitalRead(PIN_EMERGENCY);
	motor1.emergencyStop(emergen);
  started = false;
}

void startChange() {
  //started = false;
  /*while(true) {
     digitalWrite(LED_STARTED, HIGH);
     delay(1000);
    digitalWrite(LED_STARTED, LOW);
    delay(1000);
}*//*
  if(!started) {
    started = true;
    motor1.setTarget(0);
    motor1.runToPosition();
    motor1.setTarget(900);
  }
}

void setup() {
	pinMode(PIN_EMERGENCY, INPUT_PULLUP);
  pinMode(PIN_START,     INPUT_PULLUP);

  pinMode(LED_STOPPED, OUTPUT);
  pinMode(LED_STARTED, OUTPUT);

	attachInterrupt(digitalPinToInterrupt(PIN_EMERGENCY), emergencyChange, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_START),     startChange, FALLING);

  motor1.configurationTest();
}

void loop() {
  digitalWrite(LED_STARTED, started);
  digitalWrite(LED_STOPPED, emergen);
  if(started) {
    motor1.run();
  }
}*/
