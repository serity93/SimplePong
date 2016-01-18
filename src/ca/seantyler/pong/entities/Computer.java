package ca.seantyler.pong.entities;

public class Computer extends Paddle {

	public Computer(int x, int y) {
		super(x, y);
	}

	public void update(Ball ball) {
		if (ball.getX() < getX()) {
			setX(getX() - SPEED);
		}
		if (ball.getX() > getX() + WIDTH) {
			setX(getX() + SPEED);
		}
		checkCollision(ball);
	}

	@Override
	public void update() {
	}

}
