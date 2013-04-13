package eg.edu.guc.chessboard;

public class ChessBoard {
	private boolean belongsToPlayer(final char piece, final int player) {
		if (player == 0 && Character.isUpperCase(piece)) {
			return true;
		}
		if (player == 1 && Character.isLowerCase(piece)) {
			return true;
		}
		return false;
	}

	public final int getCount(final String[] board, final int player) {
		int count = 0;

		int size = board.length;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < board[i].length(); j++) {
				if (belongsToPlayer(board[i].charAt(j), player)) {
					count++;
				}
			}
		}
		return count;
	}
}
