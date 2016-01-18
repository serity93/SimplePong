/*
 * Game.cpp
 *
 *  Created on: 2013-04-08
 *      Author: Sean
 */

#include "Game.h"
#include "ScreenManager.h"

Game::Game() {
	init();

	while (screenManager->isRunning()) {
		if((SDL_GetTicks()-timer) >= FRAMERATE){
			screenManager->run();
			timer = SDL_GetTicks();
		}
	}

	shutdown();

	return;
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::init() {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	window = SDL_SetVideoMode(WIDTH, HEIGHT, 0, SDL_ANYFORMAT);
	SDL_WM_SetCaption("GameEngine", 0);
	timer = SDL_GetTicks();

	screenManager = new ScreenManager(this);
}

void Game::shutdown() {
	free(screenManager);

	SDL_FreeSurface(window);
	SDL_Quit();
}

int main(int argc, char **argv) {
	new Game();

	return 0;
}
