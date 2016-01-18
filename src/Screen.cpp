/*
 * Screen.cpp
 *
 *  Created on: 2013-04-08
 *      Author: Sean
 */

#include "Screen.h"
#include "ScreenManager.h"
#include "ScreenElement.h"
#include "Sprite.h"

Screen::Screen() {
	screenManager = NULL;
	screenElements = NULL;
	sprites = NULL;
	screenLocation.x = 0;
	screenLocation.y = 0;
	screenLocation.w = 0;
	screenLocation.h = 0;
	bitmapLocation.x = 0;
	bitmapLocation.y = 0;
	bitmapLocation.w = 0;
	bitmapLocation.h = 0;
	width = 0;
	height = 0;

	window = NULL;
	bitmap = NULL;
}

Screen::Screen(ScreenManager* screenManager, SDL_Surface* window,
		SDL_Surface* bitmap, int x, int y, int width, int height) {
	this->screenManager = screenManager;
	screenElements = new vector<ScreenElement*>;
	sprites = new vector<Sprite*>;
	this->width = width;
	this->height = height;
	screenLocation.x = x;
	screenLocation.y = y;
	screenLocation.w = width;
	screenLocation.h = height;
	bitmapLocation.x = 0;
	bitmapLocation.y = 0;
	bitmapLocation.w = width;
	bitmapLocation.h = width;

	this->window = window;
	this->bitmap = bitmap;
}

Screen::~Screen() {
	delete (screenElements);
}

void Screen::render() {
	clearScreen();

	SDL_BlitSurface(bitmap, &bitmapLocation, window, &screenLocation);

	for (unsigned int i = 0; i < screenElements->size(); i++) {
		screenElements->at(i)->render();
	}
	for (unsigned int i = 0; i < sprites->size(); i++) {
		sprites->at(i)->render();
	}

	SDL_UpdateRect(window, 0, 0, 0, 0);
}

void Screen::clearScreen() {
	SDL_FillRect(window, 0, 1);
}

void Screen::exit() {
	screenManager->popScreen();
}

void Screen::switchScreen(ScreenType screen) {
	screenManager->pushScreen(screen);
}
