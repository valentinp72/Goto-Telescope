#include "ScreenLed.hpp"

ScreenLed::ScreenLed(
	Screen * screen,
	int x,
	int y,
	int radius,
	int color,
	bool state
) : ScreenComponent(screen, x, y, radius, radius) {
	this->radius     = radius;
	this->color      = color;
	this->state      = state;
	this->lastState  = state;
	this->blinking   = false;
	this->delayBlink = 0;
	this->nextBlink  = millis();

	this->show();
}

void ScreenLed::setActive() {
	setState(true);
}

void ScreenLed::setUnactive() {
	setState(false);
}

void ScreenLed::setBlinking(int delay) {
	this->blinking   = true;
	this->delayBlink = delay;
	this->nextBlink  = millis() + delay;
}

void ScreenLed::setState(bool state) {
	this->state = state;
	this->blinking = false;
}

bool ScreenLed::getState() {
	return state;
}

void ScreenLed::show() {
	int currentColor = COLOR_LIGHTGREY;
	if(state == true)
		currentColor = color;

	this->getScreen()->fillCircle(this->getX(), this->getY(), radius, currentColor);
	this->getScreen()->drawCircle(this->getX(), this->getY(), radius, COLOR_DARKGREY);


}

void ScreenLed::refresh() {
	updateBlinkingState();
	if(state != lastState) {
		show();
		lastState = state;
	}
}

void ScreenLed::updateBlinkingState() {
	if(blinking) {
		if(millis() >= this->nextBlink) {
			this->state = !this->state;
			this->nextBlink = millis() + this->delayBlink;
		}
	}
}
