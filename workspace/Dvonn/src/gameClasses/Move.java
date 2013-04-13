package gameClasses;

import java.awt.Point;
import java.util.Stack;

public class Move {
	protected final Point from,to;
	protected int steps;
	protected Game game;
	
	
	public Move(Point f, Point t,Game g){
		from = f;
		to = t;
		game = g;
		calcSteps();
	}
	
	public void calcSteps(){
		steps = game.board.cells[from.x][from.y].cell.size();
	}
	public void setSteps(int s){
		steps=s;
	}
	
	
	
	public boolean doMove(){
		if(isValid()){
			Stack<Ring> temp = new Stack<Ring>();
			while(!game.board.cells[from.x][from.y].cell.isEmpty())
				temp.push(game.board.cells[from.x][from.y].cell.pop());
			while(!temp.isEmpty()){
				Ring r = temp.pop();
				r.setPos(new Point(to.x,to.y));
				game.board.cells[to.x][to.y].cell.push(r);
			}
			return true;
		}
		return false;
	}
	
	public boolean isValid(){
		if(game.board.cells[to.x][to.y].blanked)return false;
		Point[] p = validMoves();
		for(int i=0; i<p.length;i++){
			if(to.equals(p[i])) return true;
		}
		return false;
	}
	
	
	
	public Point[] validMoves(){
		if(steps==0) return new Point[0];
		int x,y;
		Stack<Point> s = new Stack<Point>();
		
		x = from.x+steps;
		y = from.y;
		Point p = new Point(x,y);
		if(isMoveValid(p))s.push(p);
		
		x = from.x-steps;
		y = from.y;
		p = new Point(x,y);
		if(isMoveValid(p))s.push(p);
		
		x = from.x;
		y = from.y+steps;
		p = new Point(x,y);
		if(isMoveValid(p))s.push(p);
		
		x = from.x;
		y = from.y-steps;
		p = new Point(x,y);
		if(isMoveValid(p))s.push(p);
		
		x = from.x+steps;
		y = from.y+steps;
		p = new Point(x,y);
		if(isMoveValid(p))s.push(p);
		
		x = from.x-steps;
		y = from.y-steps;
		p = new Point(x,y);
		if(isMoveValid(p))s.push(p);
		
		Point[] moves = new Point[s.size()];
		for(int i=0;i<moves.length;i++) moves[i]=s.pop(); 
		return moves;
	}
	public Point[] validMovesNoBlanked(){
		Point[] m = validMoves();
		Stack<Point> s = new Stack<Point>();
		
		for(int i=0;i<m.length;i++)if(!game.board.cells[m[i].x][m[i].y].blanked) s.push(m[i]);
		
		Point[] moves = new Point[s.size()];
		for(int i=0;i<moves.length;i++) moves[i]=s.pop(); 
		return moves;
	}
	public boolean isMoveValid(Point p){
		int x=p.x, y=p.y;
		if(x>10||y>4||x<0||y<0)return false;
		return game.board.cells[x][y].valid;
	}
}
