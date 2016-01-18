package ca.seantyler.pong.game;

import java.awt.Color;
import java.awt.Graphics2D;

import ca.seantyler.gameengine.game.Screen;
import ca.seantyler.gameengine.game.ScreenFactory;
import ca.seantyler.pong.entities.Ball;
import ca.seantyler.pong.entities.Computer;
import ca.seantyler.pong.entities.Player;

public class GameScreen extends Screen {

	private Ball ball;
	private Player player;
	private Computer computer;

	public GameScreen(ScreenFactory screenFactory) {
		super(screenFactory);
		ball = new Ball(400 - 16, 300 - 16);
		player = new Player(400 - 32, 550);
		computer = new Computer(400 - 32, 25);
	}

	@Override
	public void onCreate() {

	}

	@Override
	public void onDraw(Graphics2D g2d) {
		g2d.setColor(Color.BLACK);
		g2d.fillRect(0, 0, 800, 600);
		ball.draw(g2d);
		player.draw(g2d);
		computer.draw(g2d);
	}

	@Override
	public void onUpdate() {
		ball.update();
		player.update(ball, this);
		computer.update(ball);
	}

}
