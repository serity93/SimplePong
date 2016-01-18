package ca.seantyler.pong.game;

import java.awt.Color;
import java.awt.Graphics2D;

import ca.seantyler.gameengine.game.Screen;
import ca.seantyler.gameengine.game.ScreenFactory;

public class GameOverScreen extends Screen {

	private final String message;
	
	public GameOverScreen(ScreenFactory screenFactory, String message) {
		super(screenFactory);
		this.message = message;
	}

	@Override
	public void onCreate() {

	}

	@Override
	public void onDraw(Graphics2D g2d) {
		g2d.setColor(Color.BLACK);
		g2d.fillRect(0, 0, 800, 600);
		g2d.setColor(Color.WHITE);
		g2d.drawString(message, 400, 300);
	}

	@Override
	public void onUpdate() {
		
	}

}
