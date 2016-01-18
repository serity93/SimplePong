/*
 * ScreenElement.h
 *
 *  Created on: 2013-04-08
 *      Author: Sean
 */

#ifndef SCREENELEMENT_H_
#define SCREENELEMENT_H_

#include "SDL/SDL.h"

#include "Enums.h"

class Screen;

class ScreenElement {
protected:
	Screen* screen;

	SDL_Rect screenLocation;
	SDL_Rect bitmapLocation;
	int width, height;

	SDL_Surface* window;
	SDL_Surface* bitmap;

	bool pressed;

public:
	ScreenElement();
	ScreenElement(Screen* screen, SDL_Surface* window,
			SDL_Surface* bitmap, int x, int y, int bmpX, int bmpY, int width, int height);
	virtual ~ScreenElement();

	void render();
	virtual void action() = 0;
	bool isOver(int x, int y);
	virtual void setPressed(bool pressed) = 0;

	Screen* getScreen(){ return screen; };
	int getX(){ return screenLocation.x; };
	int getY(){ return screenLocation.y; };
	int getWidth(){ return width; };
	int getHeight(){ return height; };
	SDL_Rect getScreenLocation(){ return screenLocation; };
	SDL_Rect getBitmapLocation(){ return bitmapLocation; };
	bool isPressed(){ return pressed; };
};

#endif /* SCREENELEMENT_H_ */
