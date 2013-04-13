package eg.edu.guc.dvonn.gui;

public class Player {

	private String name;
	private int playerNum;

	public Player(String n, int num) {
		name = n;
		playerNum = num;
	}

	public void setName(String n) {
		name = n;
	}

	public String getName() {
		return name;
	}

	public int getPlayerNum() {
		return playerNum;
	}

}
