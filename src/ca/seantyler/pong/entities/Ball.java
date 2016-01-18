package ca.seantyler.pong.entities;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.util.Random;

import ca.seantyler.gameengine.entities.AbstractEntity;
import ca.seantyler.gameengine.game.ScreenFactory;
import ca.seantyler.gameengine.game.GameOverScreen;

public class Ball extends AbstractEntity {

	private static final int SIZE = 32;
	private static Random random = new Random();
	private int dx, dy;

	public Ball(int x, int y) {
		super(x, y);
		dx = random.nextInt(8) - 4;
		dy = random.nextInt(8) - 4;
		
		if(dx == 0) dx = 4;
		if(dy == 0) dy = 4;
	}

	@Override
	public void draw(Graphics2D g2d) {
		g2d.setColor(Color.WHITE);
		g2d.fillOval(getX() + (SIZE / 2), getY() + (SIZE / 2), SIZE, SIZE);
	}
	
	@Override
	public void update() {
		setX(getX() + dx);
		setY(getY() + dy);
	}

	public Rectangle getBounds() {
		return new Rectangle(getX() + (SIZE / 2), getY() + (SIZE / 2), SIZE, SIZE);
	}

	public void checkWallCollisions(ScreenFactory screenFactory) {
		if (getX() <= 0) {
			dx = -dx;
		}

		if (getX() >= 800 - SIZE) {
			dx = -dx;
		}

		if (getY() <= 0) {
			// Player scores
			dy = -dy;
		}

		if (getY() >= 600 - SIZE) {
			// Computer scores
			screenFactory.showScreen(new GameOverScreen(screenFactory, "Computer scores!"));
		}
	}

	public void negateDY() {
		dy = -dy;
	}

}
