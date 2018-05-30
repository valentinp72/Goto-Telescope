#ifndef SCREEN_BUTTON_H
#define SCREEN_BUTTON_H

#include "ScreenComponent.hpp"

#define MINPRESSURE 10
#define MAXPRESSURE 1000

#define TS_MINX 130
#define TS_MAXX 905

#define TS_MINY 75
#define TS_MAXY 930

#define CHAR_SIZE    2

#define CHAR_WIDTH    6
#define MARGIN_WIDTH  1

#define CHAR_HEIGHT   8
#define MARGIN_HEIGHT 1

class ScreenButton : public ScreenComponent {

public:
	ScreenButton(Screen * screen, int x, int y, int color, const char * text, bool state = false);
	void show();
	void refresh();

	void setState(bool state);
	bool getState();

private:
	Adafruit_GFX_Button * realButton;
};

#endif
