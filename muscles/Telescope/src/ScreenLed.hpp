#ifndef SCREEN_LED_H
#define SCREEN_LED_H

#include "ScreenComponent.hpp"

class ScreenLed : public ScreenComponent {

public:
	ScreenLed(Screen * screen, int x, int y, int radius, int color, bool state = false);
	void show();
	void refresh();

	void setActive();
	void setUnactive();
	void setBlinking(int delay);
	void setState(bool state);
	bool getState();

private:
	bool state;
	bool lastState;
	bool blinking;
	int delayBlink;
	int radius;
	int color;
	unsigned long nextBlink;

	void updateBlinkingState();
};

#endif
