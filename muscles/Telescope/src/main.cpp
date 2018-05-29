#include <Arduino.h>

#include "Motor.cpp"
#include "Screen.hpp"

Screen * s;

void setup() {
    s = Screen::getInstance();
}

void loop() {
    s->fillRect(0, 0, 240, 8, COLOR_MAROON);
	s->drawLine(0, 0, s->width(), 100, COLOR_PINK);
}
