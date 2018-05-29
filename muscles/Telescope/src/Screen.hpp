#ifndef SCREEN_H
#define SCREEN_H

#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h>
#include <TouchScreen.h>
#include <stdarg.h>

// The control pins for the LCD can be assigned to any digital or
// analog pins...but we'll use the analog pins as this allows us to
// double up the pins with the touch screen (see the TFT paint example).
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0

#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

#define YP A2  // must be an analog pin, use "An" notation!
#define XM A3  // must be an analog pin, use "An" notation!
#define YM 8   // can be a digital pin
#define XP 9   // can be a digital pin

// When using the BREAKOUT BOARD only, use these 8 data lines to the LCD:
// For the Arduino Uno, Duemilanove, Diecimila, etc.:
//   D0 connects to digital pin 8  (Notice these are
//   D1 connects to digital pin 9   NOT in order!)
//   D2 connects to digital pin 2
//   D3 connects to digital pin 3
//   D4 connects to digital pin 4
//   D5 connects to digital pin 5
//   D6 connects to digital pin 6
//   D7 connects to digital pin 7
// For the Arduino Mega, use digital pins 22 through 29
// (on the 2-row header at the end of the board).

// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

// Color definitions
#define COLOR_BLACK       0x0000      /*   0,   0,   0 */
#define COLOR_NAVY        0x000F      /*   0,   0, 128 */
#define COLOR_DARKGREEN   0x03E0      /*   0, 128,   0 */
#define COLOR_DARKCYAN    0x03EF      /*   0, 128, 128 */
#define COLOR_MAROON      0x7800      /* 128,   0,   0 */
#define COLOR_PURPLE      0x780F      /* 128,   0, 128 */
#define COLOR_OLIVE       0x7BE0      /* 128, 128,   0 */
#define COLOR_LIGHTGREY   0xC618      /* 192, 192, 192 */
#define COLOR_DARKGREY    0x7BEF      /* 128, 128, 128 */
#define COLOR_BLUE        0x001F      /*   0,   0, 255 */
#define COLOR_GREEN       0x07E0      /*   0, 255,   0 */
#define COLOR_CYAN        0x07FF      /*   0, 255, 255 */
#define COLOR_RED         0xF800      /* 255,   0,   0 */
#define COLOR_MAGENTA     0xF81F      /* 255,   0, 255 */
#define COLOR_YELLOW      0xFFE0      /* 255, 255,   0 */
#define COLOR_WHITE       0xFFFF      /* 255, 255, 255 */
#define COLOR_ORANGE      0xFD20      /* 255, 165,   0 */
#define COLOR_GREENYELLOW 0xAFE5      /* 173, 255,  47 */
#define COLOR_PINK        0xF81F


#include <MCUFRIEND_kbv.h>


class Screen {

public:
	static Screen *getInstance ();

	/* Drawing */
	void drawPixel(int x, int y, int color);
	void drawLine(int x0, int y0, int x1, int y1, int color);
	void drawRect(int x, int y, int w, int h, int color);
	void fillRect(int x, int y, int width, int height, int color);
	void drawCircle(int x0, int y0, int r, int color);
	void fillCircle(int x0, int y0, int r, int color);
	void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, int color);
	void fillTriangle(int x0, int y0, int x1, int y1, int x2, int y2, int color);
	void drawRoundRect(int x0, int y0, int w, int h, int radius, int color);
	void fillRoundRect(int x0, int y0, int w, int h, int radius, int color);
	void fillScreen(int color);

	/* Sizes */
	void setRotation(int rotation);
	int getRotation();
	int height();
	int width();
	int getCursorX();
	int getCursorY();

	/* Text */
	void drawChar(int x, int y, unsigned char c, int color, int backgroundColor, int size);
	void setCursor(int x, int y);
	void setTextColor(int foregroundColor);
	void setTextColor(int foregroundColor, int backgroundColor);
	void setTextSize(int size);
	void setTextWrap(boolean wrap);
	void print(const char * str, ...);

private:
	Screen();
	TouchScreen   * ts;
	MCUFRIEND_kbv * tft;
	static Screen * singleton;
};

#endif
