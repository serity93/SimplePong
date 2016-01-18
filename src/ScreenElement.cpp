/*
 * ScreenElements.cpp
 *
 *  Created on: 2013-04-08
 *      Author: Sean
 */

#include "ScreenElement.h"
#include "Screen.h"

ScreenElement::ScreenElement() {
	screen = NULL;
	screenLocation.x = 0;
	screenLocation.y = 0;
	screenLocation.w = 0;
	screenLocation.h = 0;
	bitmapLocation.x = 0;
	bitmapLocation.y = 0;
	bitmapLocation.w = 0;
	bitmapLocation.h = 0;
	width = 0;
	height = 0;

	window = NULL;
	bitmap = NULL;

	pressed = false;
}

ScreenElement::ScreenElement(Screen* screen, SDL_Surface* window,
		SDL_Surface* bitmap, int x, int y, int bmpX, int bmpY, int width,
		int height) {
	this->screen = screen;
	this->width = width;
	this->height = height;
	screenLocation.x = screen->getX() + x;
	screenLocation.y = screen->getY() + y;
	screenLocation.w = width;
	screenLocation.h = height;
	bitmapLocation.x = bmpX;
	bitmapLocation.y = bmpY;
	bitmapLocation.w = width;
	bitmapLocation.h = height;

	this->window = window;
	this->bitmap = bitmap;

	pressed = false;
}

ScreenElement::~ScreenElement() {
	// TODO Auto-generated destructor stub
}

void ScreenElement::render() {
	SDL_BlitSurface(bitmap, &bitmapLocation, window, &screenLocation);
}

bool ScreenElement::isOver(int x, int y) {
	return (x >= screenLocation.x && x <= screenLocation.x + width
			&& y >= screenLocation.y && y <= screenLocation.y + height);
}
