/*
 * Sprite.cpp
 *
 *  Created on: 2013-04-28
 *      Author: Sean
 */

#include "Sprite.h"

Sprite::Sprite() {
	window = NULL;
	bitmap = NULL;

	screenLocation.x = 0;
	screenLocation.y = 0;

	bitmapLocation.x = 0;
	bitmapLocation.y = 0;

	dx = 0;
	dy = 0;

	width = 0;
	screenLocation.w = 0;
	bitmapLocation.w = 0;
	height = 0;
	screenLocation.h = 0;
	bitmapLocation.h = 0;
}

Sprite::Sprite(SDL_Surface* window, SDL_Surface* bitmap, int x, int y, int dx,
		int dy, int width, int height, int bitmapX, int bitmapY) {
	this->window = window;
	this->bitmap = bitmap;

	screenLocation.x = x;
	screenLocation.y = y;

	bitmapLocation.x = bitmapX;
	bitmapLocation.y = bitmapY;

	this->dx = dx;
	this->dy = dy;

	this->width = width;
	screenLocation.w = width;
	bitmapLocation.w = width;
	this->height = height;
	screenLocation.h = height;
	bitmapLocation.h = height;
}

Sprite::~Sprite() {
	// TODO Auto-generated destructor stub
}

void Sprite::render() {
	SDL_BlitSurface(bitmap, &bitmapLocation, window, &screenLocation);
}
