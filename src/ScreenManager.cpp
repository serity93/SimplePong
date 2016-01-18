/*
 * ScreenManager.cpp
 *
 *  Created on: 2013-04-08
 *      Author: Sean
 */

#include "ScreenManager.h"
#include "Game.h"
#include "Screen.h"
#include "TitleScreen.h"
#include "GameScreen.h"

using namespace std;

ScreenManager::ScreenManager() {
	this->game = NULL;
	window = NULL;
	screenStack = NULL;
	totalWidth = 0;
	totalHeight = 0;
	running = false;
}

ScreenManager::ScreenManager(Game* game) {
	this->game = game;
	window = game->getWindow();
	screenStack = new stack<Screen*>;
	totalWidth = game->getWidth();
	totalHeight = game->getHeight();
	running = true;
	init();
}

ScreenManager::~ScreenManager() {
	delete(screenStack);
}

void ScreenManager::init() {

	pushScreen(TITLE_SCREEN);
}

void ScreenManager::run() {
	if (screenStack->empty()) {
		shutdown();
	}

	screenStack->top()->tick();
	screenStack->top()->render();

}

void ScreenManager::shutdown() {
	while (!screenStack->empty()) {
		free(screenStack->top());
		screenStack->pop();
	}
	delete(screenStack);
	running = false;
}

void ScreenManager::popScreen() {
	delete(screenStack->top());
	screenStack->pop();
}

void ScreenManager::pushScreen(ScreenType screenType) {
	Screen* screen;
	SDL_Surface* screenBitmap;

	switch (screenType) {
	case TITLE_SCREEN:
		screenBitmap = SDL_LoadBMP("titleScreen.bmp");
		screen = new TitleScreen(this, window, screenBitmap, 0, 0, 800,
				600);
		break;

	case GAME_SCREEN:
		screenBitmap = SDL_LoadBMP("gameScreen.bmp");
		screen = new GameScreen(this, window, screenBitmap, 0, 0, 800,
						600);
		break;
	}

	SDL_SetColorKey(screenBitmap, SDL_SRCCOLORKEY,
				SDL_MapRGB(screenBitmap->format, 255, 0, 255));

	screenStack->push(screen);
}

Screen* ScreenManager::getCurrentScreen() {
	return screenStack->top();
}
