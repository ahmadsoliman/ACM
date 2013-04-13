package eg.edu.guc.dvonn.engine;

public interface BoardInterface {
	void fillRandom();
	int getCurrentPhase();
	boolean put(int row, int col);
	boolean move(int rowStart, int colStart, int rowEnd, int colEnd);
	boolean isEmpty(int row, int col);
	boolean isGameOver();
	int getWinner();
	int getColor(int row, int col);
	int getHeight(int row, int col);
	boolean hasRed(int row, int col);
}
