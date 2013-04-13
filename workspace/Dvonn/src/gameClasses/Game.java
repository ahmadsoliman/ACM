package gameClasses;

import java.io.IOException;

public class Game {
	protected Board board;
	protected Player p1, p2;
	protected final static int DVONN=0,PLAYER1=1,PLAYER2=2;
	protected int playerTurn=1;
	protected boolean ringsPlaced=false;
	
	
	public static void main(String [] args)throws Exception {
		
		new Game();
	}
	
	public Game()throws IOException{
		p1 = new Player();
		p2 = new Player();
			
		new DvonnFrame(this);
		
		
	}
	
//	public void newGame()throws IOException{
//		board = new Board(this);
//		
//	}
//	
	public int whoWon(){
		int w=0,b=0;
		for(int i=0; i<11; i++){
			for(int j=0; j<5; j++){
				if(board.cells[i][j].valid&&!board.cells[i][j].blanked){
					if(board.cells[i][j].cell.peek().getPlayer()==PLAYER1)w+=board.cells[i][j].cell.size();
					else if(board.cells[i][j].cell.peek().getPlayer()==PLAYER2)b+=board.cells[i][j].cell.size();
				}
			}
		}
		p1.setScore(w);
		p2.setScore(b);
		if(w==b) return 0;
		if(w>b) return PLAYER1;
		else return PLAYER2;
	}
	
}
