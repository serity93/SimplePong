/*
 * Sprite.h
 *
 *  Created on: 2013-04-28
 *      Author: Sean
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include "SDL/SDL.h"

using namespace std;

class Sprite {
private:
	SDL_Rect screenLocation;
	SDL_Rect bitmapLocation;

	int width, height;
	int dx, dy;

	SDL_Surface* window;
	SDL_Surface* bitmap;

public:
	Sprite();
	Sprite(SDL_Surface* window, SDL_Surface* bitmap, int x, int y, int dx,
			int dy, int width, int height, int bitmapX, int bitmapY);
	virtual ~Sprite();

	void render();

	// Getter methods
	SDL_Rect* getScreenLocation(){ return &screenLocation; };
	SDL_Rect* getBitmapLocation(){ return &bitmapLocation; };

	int getX(){ return screenLocation.x; };
	int getY(){ return screenLocation.y; };

	int getBitmapX(){ return bitmapLocation.x; };
	int getBitmapY(){ return bitmapLocation.y; };

	int getDx(){ return dx; };
	int getDy(){ return dy; };

	int getWidth(){ return width; };
	int getHeight(){ return height; };

	// Setter methods
	void setBitmap(SDL_Surface* newBitmap){ bitmap = newBitmap; };

	void setScreenLocation(SDL_Rect newScreenLocation){ screenLocation = newScreenLocation; };
	void setBitmapLocation(SDL_Rect newBitmapLocation){ bitmapLocation = newBitmapLocation; };

	void setX(int newX){ screenLocation.x = newX; };
	void setY(int newY){ screenLocation.y = newY; };

	void setBitmapX(int newBitmapX){ bitmapLocation.x = newBitmapX; };
	void setBitmapY(int newBitmapY){ bitmapLocation.y = newBitmapY; };

	void setDx(int newDx){ dx = newDx; };
	void setDy(int newDy){ dy = newDy; };

	void setWidth(int newWidth){ width = newWidth; screenLocation.w = newWidth; bitmapLocation.w = newWidth; };
	void setHeight(int newHeight){ height = newHeight; screenLocation.h = newHeight; bitmapLocation.h = newHeight; };

};

#endif /* SPRITE_H_ */
