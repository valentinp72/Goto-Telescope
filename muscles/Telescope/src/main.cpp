#include <Arduino.h>

#include "Motor.cpp"
#include "Screen.hpp"

Screen * s;

void setup() {
    s = Screen::getInstance();
	s->setRotation(3);
	s->fillRect(0, 0, 240, 8, COLOR_MAROON);
	s->drawLine(0, 0, s->width(), 100, COLOR_PINK);
	s->setTextSize(2);

	const char * somebody = "world";
	s->print("Hello %s!", somebody);
}

void loop() {

}
