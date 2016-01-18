/*
 * TitleScreen.h
 *
 *  Created on: 2013-04-08
 *      Author: Sean
 */

#ifndef TITLESCREEN_H_
#define TITLESCREEN_H_

#include "Screen.h"

class ScreenManager;

class TitleScreen: public Screen {
public:
	TitleScreen();
	TitleScreen(ScreenManager* screenManager, SDL_Surface* window,
			SDL_Surface* bitmap, int x, int y, int width, int height);
	virtual ~TitleScreen();

	void tick();
	void handleInput();
};

#endif /* TITLESCREEN_H_ */
