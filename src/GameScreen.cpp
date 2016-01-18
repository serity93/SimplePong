/*
 * GameScreen.cpp
 *
 *  Created on: 2013-04-09
 *      Author: Sean
 */

#include "GameScreen.h"
#include "ScreenManager.h"
#include "ScreenElement.h"
#include "QuitButton.h"
#include "Sprite.h"
#include "Ball.h"

GameScreen::GameScreen() {
	player1 = NULL;
	ball = NULL;
}

GameScreen::GameScreen(ScreenManager* screenManager, SDL_Surface* window,
		SDL_Surface* bitmap, int x, int y, int width, int height) :
		Screen(screenManager, window, bitmap, x, y, width, height) {

	srand(time(0));

	ScreenElement* tempScreenElem = new QuitButton(this, window, bitmap, 650, 5,
			800, 0, 140, 40);
	screenElements->push_back(tempScreenElem);

	int xSpeed;
	if(rand() % 2 == 2) xSpeed = 10;
	else				xSpeed = -10;
	int ySpeed = rand() % 20 - 10;

	ball = new Ball(window, bitmap, 390, 310, xSpeed, ySpeed, 20, 20, 20, 600);
	sprites->push_back(ball);

	player1 = new Sprite(window, bitmap, 60, 270, 0, 10, 20, 100, 0, 600);
	sprites->push_back(player1);
}

GameScreen::~GameScreen() {
	for (unsigned int i = 0; i < screenElements->size(); i++) {
		delete (screenElements->at(i));
	}
	delete (screenElements);

	for (unsigned int i = 0; i < sprites->size(); i++) {
		delete (sprites->at(i));
	}
	delete (sprites);
}

void GameScreen::tick() {
	handleInput();
}

void GameScreen::handleInput() {
	static bool upIsPressed = false;
	static bool downIsPressed = false;

	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			while (!screenManager->getScreenStack()->empty()) {
				screenManager->popScreen();
			}

			return;
		} else if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				exit();
				return;
			}
			if (event.key.keysym.sym == SDLK_w) {
				upIsPressed = true;
			}
			if (event.key.keysym.sym == SDLK_s) {
				downIsPressed = true;
			}
		} else if (event.type == SDL_KEYUP) {
			if (event.key.keysym.sym == SDLK_w) {
				upIsPressed = false;
			}
			if (event.key.keysym.sym == SDLK_s) {
				downIsPressed = false;
			}
		} else if (event.type == SDL_MOUSEBUTTONDOWN) {
			for (unsigned int i = 0; i < screenElements->size(); i++) {
				if (screenElements->at(i)->isOver(event.motion.x,
						event.motion.y)) {
					screenElements->at(i)->setPressed(true);
				}
			}
		} else if (event.type == SDL_MOUSEBUTTONUP) {
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

	if (upIsPressed) {
		if (!checkWallCollisions(player1, UP)) {
			player1->setY(player1->getY() - player1->getDy());
		}
	}
	if (downIsPressed) {
		if (!checkWallCollisions(player1, DOWN)) {
			player1->setY(player1->getY() + player1->getDy());
		}
	}
}

bool GameScreen::checkWallCollisions(Sprite* sprite, Direction dir) {
	int temp_y;

	switch (dir) {
	case UP: {
		temp_y = sprite->getY() - sprite->getDy();
	}
		break;
	case DOWN: {
		temp_y = (sprite->getY() + sprite->getHeight()) + sprite->getDy();
	}
		break;
	}

	if (temp_y < stageY) {
		sprite->setY(stageY);
		return true;
	} else if (temp_y > stageY + stageHeight) {
		sprite->setY(stageY + stageHeight - sprite->getHeight());
		return true;
	}

	return false;
}
