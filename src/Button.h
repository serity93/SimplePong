/*
 * Button.h
 *
 *  Created on: 2013-04-08
 *      Author: Sean
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "ScreenElement.h"

class Button: public ScreenElement {
protected:
	int initBmpY;

public:
	Button();
	Button(Screen* screen, SDL_Surface* window,
			SDL_Surface* bitmap, int x, int y, int bmpX, int bmpY, int width,
			int height);
	virtual ~Button();

	void setPressed(bool pressed);

};

#endif /* BUTTON_H_ */
