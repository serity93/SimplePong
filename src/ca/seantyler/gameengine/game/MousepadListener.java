package ca.seantyler.gameengine.game;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class MousepadListener implements MouseListener {

	private int x, y;
	private boolean clicked;

	@Override
	public void mouseClicked(MouseEvent event) {
		x = event.getX();
		y = event.getY();
		clicked = true;
	}

	@Override
	public void mouseEntered(MouseEvent event) {

	}

	@Override
	public void mouseExited(MouseEvent event) {

	}

	@Override
	public void mousePressed(MouseEvent event) {
		mouseClicked(event);
	}

	@Override
	public void mouseReleased(MouseEvent event) {
		clicked = false;
	}

	public boolean isMousePressed() {
		return clicked;
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

}
