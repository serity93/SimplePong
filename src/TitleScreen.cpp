/*
 * TitleScreen.cpp
 *
 *  Created on: 2013-04-08
 *      Author: Sean
 */

#include "TitleScreen.h"
#include "ScreenManager.h"
#include "ScreenElement.h"
#include "QuitButton.h"
#include "NewGameButton.h"

TitleScreen::TitleScreen() {

}

TitleScreen::TitleScreen(ScreenManager* screenManager, SDL_Surface* window,
		SDL_Surface* bitmap, int x, int y, int width, int height) :
		Screen(screenManager, window, bitmap, x, y, width, height) {

	ScreenElement* temp;

	temp = new QuitButton(this, window, bitmap, 330, 380, 800, 0,
			140, 40);
	screenElements->push_back(temp);

	temp = new NewGameButton(this, window, bitmap, 330, 330, 800, 80,
				140, 40);
	screenElements->push_back(temp);
}

TitleScreen::~TitleScreen() {
	// TODO Auto-generated destructor stub
}

void TitleScreen::tick() {
	handleInput();
}

void TitleScreen::handleInput() {
	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			while (!screenManager->getScreenStack()->empty()) {
				screenManager->popScreen();
			}

			return;
		}
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				exit();
				return;
			}
		}
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			for (unsigned int i = 0; i < screenElements->size(); i++) {
				if (screenElements->at(i)->isOver(event.motion.x,
						event.motion.y)) {
					screenElements->at(i)->setPressed(true);
				}
			}
		}
		if (event.type == SDL_MOUSEBUTTONUP) {
			for (unsigned int i = 0; i < screenElements->size(); i++) {
				if (screenElements->at(i)->isPressed())
					screenElements->at(i)->setPressed(false);
				if (screenElements->at(i)->isOver(event.motion.x,
						event.motion.y)) {
					screenElements->at(i)->action();
				}
			}
		}
	}
}
