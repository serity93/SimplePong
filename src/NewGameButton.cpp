/*
 * NewGameButton.cpp
 *
 *  Created on: 2013-04-09
 *      Author: Sean
 */

#include "NewGameButton.h"
#include "Screen.h"

NewGameButton::NewGameButton() {

}

NewGameButton::NewGameButton(Screen* screen, SDL_Surface* window, SDL_Surface* bitmap,
		int x, int y, int bmpX, int bmpY, int width, int height) :
		Button(screen, window, bitmap, x, y, bmpX, bmpY, width, height) {

}

NewGameButton::~NewGameButton() {
	// TODO Auto-generated destructor stub
}

void NewGameButton::action() {
	screen->switchScreen(GAME_SCREEN);
}
