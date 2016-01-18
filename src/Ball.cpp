/*
 * Ball.cpp
 *
 *  Created on: 2013-05-01
 *      Author: Sean
 */

#include "Ball.h"

Ball::Ball() {
	// TODO Auto-generated constructor stub

}

Ball::Ball(SDL_Surface* window, SDL_Surface* bitmap, int x, int y, int dx,
		int dy, int width, int height, int bitmapX, int bitmapY) :
		Sprite(window, bitmap, x, y, dx, dy, width, height, bitmapX, bitmapY) {

}

Ball::~Ball() {
	// TODO Auto-generated destructor stub
}

