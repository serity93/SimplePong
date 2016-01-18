/*
 * Button.cpp
 *
 *  Created on: 2013-04-08
 *      Author: Sean
 */

#include "Button.h"

Button::Button() {
	initBmpY = 0;
	pressed = false;
}

Button::Button(Screen* screen, SDL_Surface* window, SDL_Surface* bitmap, int x,
		int y, int bmpX, int bmpY, int width, int height) :
		ScreenElement(screen, window, bitmap, x, y, bmpX, bmpY, width, height) {

	initBmpY = bmpY;
}

Button::~Button() {
	// TODO Auto-generated destructor stub
}

void Button::setPressed(bool pressed) {
	this->pressed = pressed;
	if (pressed) {
		bitmapLocation.y = initBmpY + height;
	} else {
		bitmapLocation.y = initBmpY;
	}
}
