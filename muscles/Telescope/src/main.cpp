#include <Arduino.h>

#include "Motor.cpp"
#include "Screen.hpp"
#include "ScreenLed.hpp"
#include "ScreenButton.hpp"

Screen * s;

ScreenLed * ledEmergency;
ScreenLed * ledRunning;
ScreenLed * ledArmed;

#define LED_BLUE  47
#define LED_GREEN 46
#define LED_RED   45

ScreenButton * btnStart;
ScreenButton * btnStop;

unsigned long begin;
int i = 0;

void startOn() {
	ledRunning->setActive();
}
void startOff() {
	//ledRunning->setUnactive();
}

void stopOn() {
	ledRunning->setUnactive();
	ledEmergency->setActive();
	ledArmed->setUnactive();
}

void stopOff() {
	ledEmergency->setUnactive();
	ledArmed->setActive();
	ledArmed->setBlinking(500);
}

void setup() {
    s = Screen::getInstance();

	ledEmergency = new ScreenLed(s, 100, 50, 10, COLOR_RED);
	ledEmergency->attachDigitalPin(LED_RED);
	ledEmergency->setActive();

	ledRunning   = new ScreenLed(s, 150, 50, 10, COLOR_GREEN);
	ledRunning->attachDigitalPin(LED_GREEN);
	ledRunning->setUnactive();

	ledArmed     = new ScreenLed(s, 200, 50, 10, COLOR_BLUE);
	ledArmed->attachDigitalPin(LED_BLUE);
	ledArmed->setBlinking(500);
	//ledArmed->setUnactive();

	btnStart     = new ScreenButton(s, 150, 150, COLOR_GREEN, "Start");
	btnStart->setActions(startOn, NULL);

	btnStop     = new ScreenButton(s, 150, 300, COLOR_RED, "STOP");
	btnStop->setActions(stopOn, stopOff);

	s->addComponent(ledEmergency);
	s->addComponent(ledRunning);
	s->addComponent(ledArmed);
	s->addComponent(btnStart);
	s->addComponent(btnStop);


	begin = millis();
}

void loop() {
	s->refresh();

	s->setTextColor(COLOR_BLACK, COLOR_LIGHTGREY);
	s->setTextSize(2);
	s->setCursor(0, 0);
	s->print("Count: %i (%is since start)", i, (millis() - begin) / 1000);
	i++;
}
