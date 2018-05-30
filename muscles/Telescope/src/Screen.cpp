#include "Screen.hpp"


Screen * Screen::singleton = NULL;

Screen * Screen::getInstance () {
	if(singleton == NULL)
		singleton = new Screen;
	return singleton;
}

Screen::Screen() {
	tft = new MCUFRIEND_kbv();
	ts  = new TouchScreen(XP, YP, XM, YM, 300);


	tft->reset();
	tft->begin(tft->readID());
	fillScreen(COLOR_BLACK);

	nextTimeGetPoint = 0;
};

/**
 * Drawing
 */

void Screen::drawPixel(int x, int y, int color) {
	tft->drawPixel(x, y, color);
}

void Screen::drawLine(int x0, int y0, int x1, int y1, int color) {
	tft->drawLine(x0, y0, x1, y1, color);
}

void Screen::drawRect(int x, int y, int w, int h, int color) {
	tft->drawRect(x, y, w, h, color);
}

void Screen::drawCircle(int x0, int y0, int r, int color) {
	tft->drawCircle(x0, y0, r, color);
}

void Screen::fillCircle(int x0, int y0, int r, int color) {
	tft->fillCircle(x0, y0, r, color);
}

void Screen::drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, int color) {
	tft->drawTriangle(x0, y0, x1, y1, x2, y2, color);
}

void Screen::fillTriangle(int x0, int y0, int x1, int y1, int x2, int y2, int color) {
	tft->fillTriangle(x0, y0, x1, y1, x2, y2, color);
}

void Screen::drawRoundRect(int x0, int y0, int w, int h, int radius, int color) {
	tft->drawRoundRect(x0, y0, w, h, radius, color);
}

void Screen::fillRoundRect(int x0, int y0, int w, int h, int radius, int color) {
	tft->fillRoundRect(x0, y0, w, h, radius, color);
}

void Screen::fillRect(int x, int y, int width, int height, int color) {
	tft->fillRect(x, y, width, height, color);
}

void Screen::fillScreen(int color) {
	tft->fillScreen(color);
}


/**
 * Touch
 */

TSPoint Screen::getPoint() {
	if(nextTimeGetPoint < millis()) {
		lastTouchPoint = ts->getPoint();
		pinMode(XM, OUTPUT);
		pinMode(YP, OUTPUT);
		nextTimeGetPoint = millis() + DELAY_GET_TOUCH;
	}
	return lastTouchPoint;
	//return ts->getPoint();
}

/**
 * Sizes
 */

void Screen::setRotation(int rotation) {
	tft->setRotation(rotation);
}

int Screen::getRotation() {
	return tft->getRotation();
}

int Screen::height() {
	return tft->height();
}

int Screen::width() {
	return tft->width();
}

int Screen::getCursorX() {
	return tft->getCursorX();
}

int Screen::getCursorY() {
	return tft->getCursorY();
}


/**
 * Text
 */
void Screen::setCursor(int x, int y) {
	tft->setCursor(x, y);
}

void Screen::setTextColor(int foregroundColor) {
	tft->setTextColor(foregroundColor);
}

void Screen::setTextColor(int foregroundColor, int backgroundColor) {
	tft->setTextColor(foregroundColor, backgroundColor);
}

void Screen::setTextSize(int size) {
	tft->setTextSize(size);
}

void Screen::setTextWrap(boolean wrap) {
	tft->setTextWrap(wrap);
}

void Screen::print(const char * str, ...) {
	va_list list;
	va_start(list, str);

	size_t needed = vsnprintf(NULL, 0, str, list) + 1;
	char * buffer = (char *) malloc(needed);
	vsnprintf(buffer, needed, str, list);

	tft->print(buffer);
	free(buffer);
}

/**
 * Miscellaneous
 */

Adafruit_GFX * Screen::getAdafruitGFX() {
	return tft;
}
