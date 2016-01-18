package ca.seantyler.pong.entities;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.Rectangle;

import ca.seantyler.gameengine.entities.AbstractEntity;

public abstract class Paddle extends AbstractEntity {

	protected static final int WIDTH = 100, HEIGHT = 25;
	protected static final int SPEED = 2;

	public Paddle(int x, int y) {
		super(x, y);
	}

	public Rectangle getBounds() {
		return new Rectangle(getX(), getY(), WIDTH, HEIGHT);
	}
	
	public void checkWallCollision(){
		if(getX() < 0){
			setX(0);
		}
		if(getX() > 800 - WIDTH){
			setX(800 - WIDTH);
		}
	}

	public void checkCollision(Ball ball) {
		if (ball.getBounds().intersects(getBounds())) {
			ball.negateDY();
		}
	}

	@Override
	public void draw(Graphics2D g2d) {
		g2d.setColor(Color.WHITE);
		g2d.fillRect(getX(), getY(), WIDTH, HEIGHT);
	}

}
