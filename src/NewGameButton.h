/*
 * NewGameButton.h
 *
 *  Created on: 2013-04-09
 *      Author: Sean
 */

#ifndef NEWGAMEBUTTON_H_
#define NEWGAMEBUTTON_H_

#include "Button.h"

class NewGameButton: public Button {
public:
	NewGameButton();
	NewGameButton(Screen* screen, SDL_Surface* window, SDL_Surface* bitmap, int x,
				int y, int bmpX, int bmpY, int width, int height);
	virtual ~NewGameButton();

	void action();
};

#endif /* NEWGAMEBUTTON_H_ */
