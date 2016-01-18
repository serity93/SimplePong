/*
 * Game.h
 *
 *  Created on: 2013-04-08
 *      Author: Sean
 */

#ifndef GAME_H_
#define GAME_H_

#include "SDL/SDL.h"

using namespace std;

class ScreenManager;

class Game {
private:
	const static int WIDTH = 800, HEIGHT = 600;
	const static int FPS = 60;
	const static int FRAMERATE = 1000/FPS;
	int timer;

	void init();
	void shutdown();

	SDL_Surface* window;

	ScreenManager* screenManager;

public:
	Game();
	virtual ~Game();

	int getWidth(){ return WIDTH; };
	int getHeight(){ return HEIGHT; };
	int getFPS(){ return FPS; };
	int getFramerate(){ return FRAMERATE; };

	SDL_Surface* getWindow(){ return  window; };

	ScreenManager* getScreenManager(){ return screenManager; };
};

#endif /* GAME_H_ */
