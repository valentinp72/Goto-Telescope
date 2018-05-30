#include "ScreenButton.hpp"

ScreenButton::ScreenButton(
	Screen * screen,
	int x,
	int y,
	int color,
	const char * text,
	bool state
) : ScreenComponent(screen, x, y, 0, 0) {
	this->realButton = new Adafruit_GFX_Button();
	this->realButton->initButton(
		screen->getAdafruitGFX(),
		x, y,
		CHAR_SIZE * CHAR_WIDTH  * (MARGIN_WIDTH + strlen(text)),
		CHAR_SIZE * CHAR_HEIGHT * (MARGIN_HEIGHT + 1),
		COLOR_LIGHTGREY, COLOR_WHITE, color,
		text, CHAR_SIZE);
	this->setState(state);
	this->show();
}


void ScreenButton::setState(bool state) {
	realButton->press(state);
}

bool ScreenButton::getState() {
	return realButton->isPressed();
}

void ScreenButton::show() {
	this->realButton->drawButton(getState());
}

void ScreenButton::refresh() {
	TSPoint p = ScreenComponent::getScreen()->getPoint();

	if(p.z > MINPRESSURE && p.z < MAXPRESSURE) {
		p.x = p.x + p.y;
		p.y = p.x - p.y;
		p.x = p.x - p.y;
		p.x = map(p.x, TS_MINX, TS_MAXX, ScreenComponent::getScreen()->width(), 0);
		p.y = ScreenComponent::getScreen()->height() - (map(
			p.y,
			TS_MINY, TS_MAXY,
			ScreenComponent::getScreen()->height(), 0));
	}

	/*
	ScreenComponent::getScreen()->setTextColor(COLOR_BLACK, COLOR_LIGHTGREY);
	ScreenComponent::getScreen()->setTextSize(2);
	ScreenComponent::getScreen()->setCursor(100, 100);*/

	if(this->realButton->contains(p.x, p.y)) {
		setState(true);
		//ScreenComponent::getScreen()->print("O (%i %i)",  p.x, p.y);
	}
	else {
		setState(false);
		//ScreenComponent::getScreen()->print("F (%i %i)", p.x, p.y);
	}

	if(this->realButton->justPressed() || this->realButton->justReleased()) {
		show();
	}
}
