#include "Screen.hpp"


Screen * Screen::singleton = NULL;

Screen * Screen::getInstance () {
	if(singleton == NULL)
		singleton = new Screen;
	return singleton;
}

Screen::Screen() {
	ts  = new TouchScreen(XP, YP, XM, YM, 300);
	tft = new MCUFRIEND_kbv();

	tft->reset();
	tft->begin(tft->readID());
	fillScreen(COLOR_BLACK);
};

void Screen::drawPixel(int x, int y, int color) {
	tft->drawPixel(x, y, color);
}

void Screen::drawLine(int x0, int y0, int x1, int y1, int color) {
	tft->drawLine(x0, y0, x1, y1, color);
}

void Screen::fillRect(int x, int y, int width, int height, int color) {
	tft->fillRect(x, y, width, height, color);
}

void Screen::fillScreen(int color) {
	tft->fillScreen(color);
}

int Screen::height() {
	return tft->height();
}

int Screen::width() {
	return tft->width();
}
