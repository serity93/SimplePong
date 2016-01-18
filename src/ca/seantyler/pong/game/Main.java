package ca.seantyler.pong.game;

import ca.seantyler.gameengine.game.Game;

public class Main {
	
	private final Game game;

	public Main(){
		game = new Game(800, 600, "Pong");
		game.getScreenFactory().showScreen(new MainScreen(game.getScreenFactory()));
	}
	
	public static void main(String[] args) {
		new Main();
	}

}
