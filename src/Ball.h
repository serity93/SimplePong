/*
 * Ball.h
 *
 *  Created on: 2013-05-01
 *      Author: Sean
 */

#ifndef BALL_H_
#define BALL_H_

#include "Sprite.h"

class Ball: public Sprite {
public:
	Ball();
	Ball(SDL_Surface* window, SDL_Surface* bitmap, int x, int y, int dx,
			int dy, int width, int height, int bitmapX, int bitmapY);
	virtual ~Ball();
};

#endif /* BALL_H_ */
