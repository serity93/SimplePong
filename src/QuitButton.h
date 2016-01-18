/*
 * QuitButton.h
 *
 *  Created on: 2013-04-08
 *      Author: Sean
 */

#ifndef QUITBUTTON_H_
#define QUITBUTTON_H_

#include "Button.h"

class QuitButton: public Button {
public:
	QuitButton();
	QuitButton(Screen* screen, SDL_Surface* window, SDL_Surface* bitmap, int x,
			int y, int bmpX, int bmpY, int width, int height);
	virtual ~QuitButton();

	void action();
};

#endif /* QUITBUTTON_H_ */
