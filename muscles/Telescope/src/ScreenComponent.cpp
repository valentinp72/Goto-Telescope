#include "ScreenComponent.hpp"

ScreenComponent::ScreenComponent(Screen * screen, int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width  = width;
	this->height = height;
	this->screen = screen;
}

Screen * ScreenComponent::getScreen() {
	return screen;
}

int ScreenComponent::getX() {
	return this->x;
}

int ScreenComponent::getY() {
	return this->y;
}
