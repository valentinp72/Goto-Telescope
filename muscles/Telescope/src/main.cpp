#include <Arduino.h>

#include "Motor.cpp"
#include "Screen.hpp"
#include "ScreenLed.hpp"

Screen * s;

ScreenLed * ledEmergency;
ScreenLed * ledRunning;
ScreenLed * ledArmed;

void setup() {
    s = Screen::getInstance();
	s->setRotation(3);
	s->fillRoundRect(0, 0, s->width(), s->height(), 20, COLOR_WHITE);

	s->setTextColor(COLOR_BLACK);
	s->setTextSize(2);
	s->setCursor(10, 2);

	const char * somebody = "Valentin";
	s->print("Hello %s!", somebody);

	ledEmergency = new ScreenLed(s, 100, 50, 10, COLOR_RED);
	ledEmergency->setUnactive();

	ledRunning   = new ScreenLed(s, 150, 50, 10, COLOR_GREEN);
	ledRunning->setActive();

	ledArmed     = new ScreenLed(s, 200, 50, 10, COLOR_BLUE);
	ledArmed->setBlinking(250);
}

void loop() {
	ledEmergency->refresh();
	ledRunning->refresh();
	ledArmed->refresh();
}
