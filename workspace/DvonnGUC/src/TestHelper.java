import eg.edu.guc.dvonn.engine.Board;

public class TestHelper {
	public static Board setupGame() {
		Board b = new Board(5, 11);
		b.put(1, 2); // RED
		b.put(2, 7); // RED
		b.put(4, 4); // RED
		b.put(0, 1); // BLACK
		b.put(0, 0); // WHITE
		b.put(0, 3); // BLACK
		b.put(0, 2); // WHITE
		b.put(0, 5); // BLACK
		b.put(0, 4); // WHITE
		b.put(0, 7); // BLACK
		b.put(0, 6); // WHITE
		b.put(0, 8); // BLACK
		b.put(0, 10); // WHITE
		b.put(0, 9); // BLACK
		b.put(1, 0); // WHITE
		b.put(1, 1); // BLACK
		b.put(1, 3); // WHITE
		b.put(1, 5); // BLACK
		b.put(1, 4); // WHITE
		b.put(1, 7); // BLACK
		b.put(1, 6); // WHITE
		b.put(1, 10); // BLACK
		b.put(1, 8); // WHITE
		b.put(2, 0); // BLACK
		b.put(2, 1); // WHITE
		b.put(2, 3); // BLACK
		b.put(2, 2); // WHITE
		b.put(2, 4); // BLACK
		b.put(2, 6); // WHITE
		b.put(2, 5); // BLACK
		b.put(2, 8); // WHITE
		b.put(2, 9); // BLACK
		b.put(2, 10); // WHITE
		b.put(3, 1); // BLACK
		b.put(3, 0); // WHITE
		b.put(3, 2); // BLACK
		b.put(3, 3); // WHITE
		b.put(3, 4); // BLACK
		b.put(3, 5); // WHITE
		b.put(3, 6); // BLACK
		b.put(3, 7); // WHITE
		b.put(3, 8); // BLACK
		b.put(3, 9); // WHITE
		b.put(4, 0); // BLACK
		b.put(3, 10); // WHITE
		b.put(4, 1); // BLACK
		b.put(4, 2); // WHITE
		b.put(4, 5); // BLACK
		b.put(4, 3); // WHITE
		b.put(4, 7); // BLACK
		b.put(4, 6); // WHITE
		b.put(4, 9); // BLACK
		b.put(4, 8); // WHITE
		b.put(4, 10); // BLACK
		b.put(1, 9); // WHITE
		return b;
	}

	public static  void playSetupBoard(Board board) {
		board.move(0, 1, 0, 0); // Black's turn
		board.move(0, 2, 0, 3); // White's turn
		board.move(1, 1, 0, 0); // Black's turn
		board.move(2, 1, 1, 0); // White's turn
		board.move(2, 0, 1, 0); // Black's turn
		board.move(2, 2, 1, 2); // White's turn
		board.move(2, 3, 1, 2); // Black's turn
		board.move(1, 3, 1, 2); // White's turn
		board.move(3, 2, 4, 2); // Black's turn
		board.move(3, 3, 4, 4); // White's turn
		board.move(4, 2, 4, 4); // Black's turn
		board.move(0, 3, 0, 5); // White's turn
		board.move(4, 4, 4, 8); // Black's turn
		board.move(0, 6, 1, 7); // White's turn
		board.move(4, 9, 4, 10); // Black's turn
		board.move(3, 10, 2, 10); // White's turn
        board.move(4, 10, 4, 8); // Black's turn
		board.move(1, 7, 1, 5); // White's turn
		board.move(3, 8, 4, 8); // Black's turn
		board.move(2, 8, 3, 9); // White's turn
		board.move(0, 8, 0, 7); // Black's turn
		board.move(3, 7, 2, 6); // White's turn
		board.move(2, 4, 2, 5); // Black's turn
		board.move(2, 6, 4, 8); // White's turn
		board.move(4, 7, 4, 8); // Black's turn
		board.move(1, 9, 1, 8); // White's turn
		board.move(0, 7, 0, 9); // Black's turn
		board.move(1, 6, 0, 5); // White's turn
		board.move(3, 6, 4, 6); // Black's turn
        board.move(1, 8, 1, 10); // White's turn
        board.move(0, 9, 3, 9); // Black's turn
		board.move(2, 10, 4, 8); // White's turn
		board.move(2, 9, 3, 9); // Black's turn
	}

}
