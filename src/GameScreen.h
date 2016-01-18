/*
 * GameScreen.h
 *
 *  Created on: 2013-04-09
 *      Author: Sean
 */

#ifndef GAMESCREEN_H_
#define GAMESCREEN_H_

#include "math.h"
#include "time.h"

#include "Screen.h"

class ScreenManager;

class GameScreen: public Screen {
private:
	Sprite* player1;
	Sprite* ball;

	const static int stageX = 20;
	const static int stageY = 60;
	const static int stageWidth = 760;
	const static int stageHeight = 520;

public:
	GameScreen();
	GameScreen(ScreenManager* screenManager, SDL_Surface* window,
			SDL_Surface* bitmap, int x, int y, int width, int height);
	virtual ~GameScreen();

	void tick();
	void handleInput();

	vector<Sprite*>* getSprites(){ return sprites; };

	bool checkWallCollisions(Sprite* sprite, Direction dir);
};

#endif /* GAMESCREEN_H_ */
