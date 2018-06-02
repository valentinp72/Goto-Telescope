#ifndef SCREEN_COMPONENT_H
#define SCREEN_COMPONENT_H

class ScreenComponent;
#include "Screen.hpp"

class ScreenComponent {
private:
	int x;
	int y;
	int width;
	int height;
	char * title;
	Screen * screen;

public:
	ScreenComponent(Screen * screen, int x, int y, int width, int height);

	void setTitle(const char * title);
	char * getTitle();

	Screen * getScreen();
	int getX();
	int getY();

	virtual void show()    = 0;
	virtual void refresh() = 0;
};

#endif
