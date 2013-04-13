package gameClasses;

public class Player {
	
	private String name;
	private int playerNum;
	private int score;
	private static boolean playerExist=false;
	
	public Player(){
		name="Player"+(!playerExist?"1":"2");
		if(!playerExist) playerNum=Game.PLAYER1;
		else playerNum = Game.PLAYER2;
		playerExist=true;
	}
	public Player(String n,int num){
		name = n;
		playerNum = num;
		playerExist=true;
	}
	
	public void setName(String n) {name=n;}
	public String getName(){ return name;}
	public int getPlayerNum(){return playerNum;}
	public void setScore(int s){score = s;}
	public int getScore(){return score;}
	
}
