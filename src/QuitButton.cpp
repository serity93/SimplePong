/*
 * QuitButton.cpp
 *
 *  Created on: 2013-04-08
 *      Author: Sean
 */

#include "QuitButton.h"
#include "Screen.h"

QuitButton::QuitButton() {

}

QuitButton::QuitButton(Screen* screen, SDL_Surface* window, SDL_Surface* bitmap,
		int x, int y, int bmpX, int bmpY, int width, int height) :
		Button(screen, window, bitmap, x, y, bmpX, bmpY, width, height) {

}

QuitButton::~QuitButton() {
	// TODO Auto-generated destructor stub
}

void QuitButton::action() {
	screen->exit();
}
