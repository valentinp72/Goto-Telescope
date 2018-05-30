#include <Arduino.h>

#include "Motor.cpp"
#include "Screen.hpp"
#include "ScreenLed.hpp"
#include "ScreenButton.hpp"

Screen * s;

ScreenLed * ledEmergency;
ScreenLed * ledRunning;
ScreenLed * ledArmed;

ScreenButton * btnStart;

unsigned long begin;
int i = 0;

void setup() {
    s = Screen::getInstance();
	//s->setRotation(3);
	s->fillRoundRect(0, 0, s->width(), s->height(), 20, COLOR_WHITE);

	ledEmergency = new ScreenLed(s, 100, 50, 10, COLOR_RED);
	ledEmergency->setUnactive();

	ledRunning   = new ScreenLed(s, 150, 50, 10, COLOR_GREEN);
	ledRunning->setActive();

	ledArmed     = new ScreenLed(s, 200, 50, 10, COLOR_BLUE);
	ledArmed->setBlinking(250);

	btnStart     = new ScreenButton(s, 150, 150, COLOR_GREEN, "Start");
	begin = millis();
}

void loop() {
	ledEmergency->refresh();
	ledRunning->refresh();
	ledArmed->refresh();
	btnStart->refresh();

	s->setTextColor(COLOR_BLACK, COLOR_LIGHTGREY);
	s->setTextSize(2);
	s->setCursor(0, 0);
	s->print("Count: %i (%is since start)", i, (millis() - begin) / 1000);
	i++;
}
