package eg.edu.guc.dvonn.engine;

import java.awt.Point;
import java.util.Stack;

public class Cell {
	private Point pos;
	public Stack<Ring> cell;

	public Cell(Point p) {
		pos = p;
		cell = new Stack<Ring>();
	}

	public Point getPos() {
		return pos;
	}
}
