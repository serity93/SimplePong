/*
 * Screen.h
 *
 *  Created on: 2013-04-08
 *      Author: Sean
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <vector>

#include "SDL/SDL.h"

#include "Enums.h"

using namespace std;

class ScreenManager;
class ScreenElement;
class Sprite;

class Screen {
protected:
	ScreenManager* screenManager;
	vector<ScreenElement*>* screenElements;
	vector<Sprite*>* sprites;

	SDL_Rect screenLocation;
	SDL_Rect bitmapLocation;
	int width, height;

	SDL_Surface* window;
	SDL_Surface* bitmap;
	SDL_Event event;

public:
	Screen();
	Screen(ScreenManager* screenManager, SDL_Surface* window,
			SDL_Surface* bitmap, int x, int y, int width, int height);
	virtual ~Screen();

	virtual void tick() = 0;
	void render();
	void clearScreen();
	virtual void handleInput() = 0;
	void exit();
	void switchScreen(ScreenType screen);

	ScreenManager* getScreenManager(){ return screenManager; };
	vector<ScreenElement*>* getScreenElements(){ return screenElements; };
	int getX(){ return screenLocation.x; };
	int getY(){ return screenLocation.y; };
	int getWidth(){ return width; };
	int getHeight(){ return height; };
	SDL_Surface* getWindow(){ return window; };
	SDL_Surface* getBitmap(){ return bitmap; };
};

#endif /* SCREEN_H_ */
