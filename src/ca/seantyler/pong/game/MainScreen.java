package ca.seantyler.pong.game;

import java.awt.Color;
import java.awt.Graphics2D;

import ca.seantyler.gameengine.game.Screen;
import ca.seantyler.gameengine.game.ScreenFactory;

public class MainScreen extends Screen {

	private long clicked;
	
	public MainScreen(ScreenFactory screenFactory) {
		super(screenFactory);
	}

	@Override
	public void onCreate() {
		clicked = System.currentTimeMillis();
	}

	@Override
	public void onDraw(Graphics2D g2d) {
		g2d.setColor(Color.BLACK);
		g2d.fillRect(0, 0, 800, 600);
		g2d.setColor(Color.WHITE);
		g2d.drawString("Press the mouse to start!", 350, 250);
	}

	@Override
	public void onUpdate() {
		if (getScreenFactory().getGame().getMouseListener().isMousePressed() && System.currentTimeMillis() - clicked >= 500) {
			// Go to next screen
			getScreenFactory().showScreen(new GameScreen(getScreenFactory()));
		}
	}
}
