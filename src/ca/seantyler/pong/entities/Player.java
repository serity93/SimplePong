package ca.seantyler.pong.entities;

import java.awt.event.KeyEvent;

import ca.seantyler.gameengine.game.Screen;

public class Player extends Paddle {

	public Player(int x, int y) {
		super(x, y);
	}

	public void update(Ball ball, Screen screen) {
		if (screen.getScreenFactory().getGame().getKeyboardListener()
				.isKeyPressed(KeyEvent.VK_A)) {
			setX(getX() - SPEED);
		}

		if (screen.getScreenFactory().getGame().getKeyboardListener()
				.isKeyPressed(KeyEvent.VK_D)) {
			setX(getX() + SPEED);
		}
		
		checkWallCollision();
		checkCollision(ball);
	}

	@Override
	public void update() {

	}

}
