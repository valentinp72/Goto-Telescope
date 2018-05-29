#include <Arduino.h>

#include "Motor.cpp"
#include "Screen.hpp"

Screen * s;

void setup() {
    s = Screen::getInstance();
	s->setRotation(3);
	s->fillRoundRect(0, 0, s->width(), s->height(), 20, COLOR_WHITE);

	s->setTextColor(COLOR_BLACK);
	s->setTextSize(2);
	s->setCursor(10, 2);


	const char * somebody = "Valentin";
	s->print("Hello %s!", somebody);
}

void loop() {

}
