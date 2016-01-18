/*
 * ScreenManager.h
 *
 *  Created on: 2013-04-08
 *      Author: Sean
 */

#ifndef SCREENMANAGER_H_
#define SCREENMANAGER_H_

#include <string>
#include <stack>

#include "SDL/SDL.h"

#include "Enums.h"

using namespace std;

class Game;
class Screen;

class ScreenManager {
private:
	Game* game;
	bool running;
	stack<Screen*>* screenStack;
	int totalWidth, totalHeight;

	SDL_Surface* window;

public:
	ScreenManager();
	ScreenManager(Game* game);
	virtual ~ScreenManager();

	void init();
	void run();
	void shutdown();
	void popScreen();
	void pushScreen(ScreenType screenType);
	Screen* getCurrentScreen();

	Game* getGame(){ return game; };
	bool isRunning(){ return running; };
	stack<Screen*>* getScreenStack(){ return screenStack; };
	int getWidth(){ return totalWidth; };
	int getHeight(){ return totalHeight; };

	SDL_Surface* getWindow(){ return window; };
};

#endif /* SCREENMANAGER_H_ */
