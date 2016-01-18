package ca.seantyler.gameengine.game;

import java.awt.event.KeyListener;
import java.awt.event.MouseListener;

import javax.swing.JFrame;

public class Game {

	private final JFrame window = new JFrame();
	private final ScreenFactory screenFactory;
	private final GameThread gameThread;
	private final KeyboardListener keyboardListener;
	private final MousepadListener mousepadListener;

	public Game(int width, int height, String title) {
		window.setSize(width, height);
		window.setResizable(false);
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		window.setFocusable(true);
		window.setLocationRelativeTo(null);
		window.setTitle(title);
		window.setVisible(true);

		screenFactory = new ScreenFactory(this);

		gameThread = new GameThread(this);
		window.add(gameThread);

		keyboardListener = new KeyboardListener();
		window.addKeyListener(keyboardListener);

		mousepadListener = new MousepadListener();
		window.addMouseListener(mousepadListener);

		new Thread(gameThread).start();
	}

	public KeyboardListener getKeyboardListener() {
		return keyboardListener;
	}

	public MousepadListener getMouseListener() {
		return mousepadListener;
	}

	public ScreenFactory getScreenFactory() {
		return screenFactory;
	}

	public JFrame getWindow() {
		return window;
	}

}
