package gameClasses;

import java.awt.Point;
import java.util.Stack;

public class Cell {
	public final boolean valid;
	public boolean blanked=false;
	public final Point pos;
	public Stack<Ring> cell;
	public Cell(boolean v,Point p){
		valid = v;
		pos = p;
		cell = new Stack<Ring>();
	}
}
