package eg.edu.guc.dvonn.engine;

import java.awt.Point;
import java.util.ArrayList;
import java.util.Random;
import java.util.Stack;

public class Board implements BoardInterface {
	public final static int DVONN = 0, PLAYER1 = 1, PLAYER2 = 2;
	public int rows, columns;
	private int turn, placedPieces, boardSize;
	private boolean placingPhase;
	private boolean easyAI;
	private ArrayList<Point> freeCells;

	private Cell[][] board;
	private boolean[][] found;
	private boolean evenBoard;
	private Random rand;

	public Board() {
		this(5, 11);
	}

	public Board(int rows, int columns) {
		rand = new Random();

		this.rows = rows;
		this.columns = columns;
		boardSize = rows * columns;
		board = new Cell[rows][columns];
		if (boardSize % 2 == 0) {
			boardSize--;
			evenBoard = true;
		}
		freeCells = new ArrayList<Point>();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (evenBoard && i == rows - 1 && j == columns - 1) {
					continue;
				}
				freeCells.add(new Point(i, j));
				Point pos = new Point(i,j);
				board[i][j] = new Cell(pos);
			}
		}
		this.turn = PLAYER1;
		placingPhase = true;
		placedPieces = 0;
	}

	public Board(int rows, int columns, int levelAI) {
		this(rows, columns);
		if (levelAI == 0) {
			setEasyAI(true);
		}
	}

	public void fillRandom() {
		if (!placingPhase) {
			return;
		}
		for (int i = 0; i < 3; i++) {
			Point p = freeRandom();
			put(p.x, p.y);
		}
		for (int i = 0; i < ((rows * columns - 3) / 2); i++) {
			Point p = freeRandom();
			put(p.x, p.y);
			p = freeRandom();
			put(p.x, p.y);
		}
		turn = PLAYER2;
		placingPhase = false;
	}

	public Point freeRandom() {
		Point p = new Point();
		int index = rand.nextInt(freeCells.size());
		p = freeCells.get(index);
		freeCells.remove(index);
		return p;
	}

	public boolean put(int row, int col) {
		if (!isEmpty(row, col)) {
			return false;
		}
		if (!placingPhase) {
			return false;
		}
		freeCells.remove(new Point(row, col));
		Ring ring = new Ring();
		if (placedPieces < 3) {
			ring = new Ring('r', DVONN, "red.png", "");
		} else if (turn == PLAYER1) {
			ring = new Ring('w', PLAYER1, "white.png", "whiteSelected.png");
		} else if (turn == PLAYER2) {
			ring = new Ring('b', PLAYER2, "black.png", "blackSelected.png");
		}
		board[row][col].cell.push(ring);
		placedPieces++;
		if (placedPieces == boardSize) {
			placingPhase = false;
		}
		turn = (getTurn() == PLAYER1) ? PLAYER2 : PLAYER1;
		return true;
	}

	public int getCurrentPhase() {
		if (placingPhase) {
			return 0;
		}
		return 1;
	}

	public boolean canMove(int i, int j) {
		Point[] moves = validMoves(i, j, getHeight(i, j));
		return moves.length != 8 && !isEmpty(i, j) && getColor(i, j) == turn;
	}

	public boolean move(int rowStart, int colStart, int rowEnd, int colEnd) {
		if (placingPhase || isGameOver()) {
			return false;
		}
		if (!canMove(rowStart, colStart) || isEmpty(rowEnd, colEnd)
				|| (rowStart == rowEnd && colStart == colEnd)) {
			return false;
		}
		Point[] moves = validMoves(rowStart, colStart,
				getHeight(rowStart, colStart));
		boolean flag = false;
		for (int i = 0; i < moves.length; i++) {
			if (moves[i].equals(new Point(rowEnd, colEnd))) {
				Stack<Ring> temp = new Stack<Ring>();
				while (!board[rowStart][colStart].cell.isEmpty()) {
					temp.push(board[rowStart][colStart].cell.pop());
				}
				while (!temp.isEmpty()) {
					Ring r = temp.pop();
					r.setPos(new Point(rowEnd, colEnd));
					board[rowEnd][colEnd].cell.push(r);
				}
				flag = true;
				break;
			}
		}
		if (!flag) {
			return false;
		}
		turn = (getTurn() == PLAYER1) ? PLAYER2 : PLAYER1;
		removeInvalid();
		flipTurn();
		return true;
	}

	public Point[] validMoves(int row, int col, int steps) {
		if (steps == 0) {
			return new Point[0];
		}
		int x, y;
		Stack<Point> s = new Stack<Point>();

		x = row + steps;
		y = col;
		Point p = new Point(x, y);
		if (isMoveValid(x, y)) {
			s.push(p);
		}

		x = row - steps;
		y = col;
		p = new Point(x, y);
		if (isMoveValid(x, y)) {
			s.push(p);
		}

		x = row;
		y = col + steps;
		p = new Point(x, y);
		if (isMoveValid(x, y)) {
			s.push(p);
		}

		x = row;
		y = col - steps;
		p = new Point(x, y);
		if (isMoveValid(x, y)) {
			s.push(p);
		}

		x = row + steps;
		y = col + steps;
		p = new Point(x, y);
		if (isMoveValid(x, y)) {
			s.push(p);
		}

		x = row - steps;
		y = col - steps;
		p = new Point(x, y);
		if (isMoveValid(x, y)) {
			s.push(p);
		}

		x = row + steps;
		y = col - steps;
		p = new Point(x, y);
		if (isMoveValid(x, y)) {
			s.push(p);
		}

		x = row - steps;
		y = col + steps;
		p = new Point(x, y);
		if (isMoveValid(x, y)) {
			s.push(p);
		}

		Point[] moves = new Point[s.size()];
		for (int i = 0; i < moves.length; i++) {
			moves[i] = s.pop();
		}

		return moves;
	}

	public boolean isMoveValid(int row, int col) {
		if (evenBoard && row == rows - 1 && col == columns - 1) {
			return false;
		}
		if (row > rows - 1 || col > columns - 1 || row < 0 || col < 0
				|| isEmpty(row, col)) {
			return false;
		}
		return true;
	}

	public boolean isEmpty(int row, int col) {
		if (evenBoard && row == rows - 1 && col == columns - 1) {
			return false;
		}
		return board[row][col].cell.isEmpty();
	}

	public boolean isGameOver() {
		if (placingPhase) {
			return false;
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (evenBoard && i == rows - 1 && j == columns - 1) {
					continue;
				}
				if (getColor(i, j) != DVONN
						&& validMoves(i, j, getHeight(i, j)).length > 0) {
					return false;
				}
			}
		}
		return true;
	}

	public int getWinner() {
		int white = -1, black = -1;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (evenBoard && i == rows - 1 && j == columns - 1) {
					continue;
				}
				if (getColor(i, j) == PLAYER1 && getHeight(i, j) > white) {
					white = getHeight(i, j);
				} else if (getColor(i, j) == PLAYER2 && getHeight(i, j) > black) {
					black = getHeight(i, j);
				}
			}
		}
		if (white > black) {
			return PLAYER1;
		} else if (black > white) {
			return PLAYER2;
		} else {
			return DVONN;
		}
	}

	public int getColor(int row, int col) {
		if (evenBoard && row == rows - 1 && col == columns - 1) {
			return 3;
		}
		if (isEmpty(row, col)) {
			return 3;
		}
		return board[row][col].cell.peek().getPlayer();
	}

	public int getHeight(int row, int col) {
		if (evenBoard && row == rows - 1 && col == columns - 1) {
			return 0;
		}
		return board[row][col].cell.size();
	}

	public boolean hasRed(int row, int col) {
		if (evenBoard && row == rows - 1 && col == columns - 1) {
			return false;
		}
		if (row > rows - 1 || row < 0 || col > columns - 1 || col < 0) {
			return false;
		}
		Stack<Ring> cell = board[row][col].cell;
		Stack<Ring> temp = new Stack<Ring>();
		boolean flag = false;
		while (!cell.isEmpty()) {
			if (cell.peek().getPlayer() == DVONN) {
				flag = true;
				break;
			}
			temp.push(cell.pop());
		}
		while (!temp.isEmpty()) {
			cell.push(temp.pop());
		}
		return flag;
	}

	public void removeInvalid() {
		ArrayList<Point> p = notConnectedToDvonn();
		for (int i = 0; i < p.size(); i++) {
			if (evenBoard && p.get(i).x == rows - 1
					&& p.get(i).y == columns - 1) {
				continue;
			}
			board[p.get(i).x][p.get(i).y].cell.clear();
		}
	}

	private ArrayList<Point> notConnectedToDvonn() {
		ArrayList<Point> p = new ArrayList<Point>();
		found = new boolean[rows][columns];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (evenBoard && i == rows - 1 && j == columns - 1) {
					continue;
				}
				if (hasRed(i, j)) {
					connectedCells(i, j);
				}
			}
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (evenBoard && i == rows - 1 && j == columns - 1) {
					continue;
				}
				if (!found[i][j]) {
					p.add(new Point(i, j));
				}
			}
		}
		return p;
	}

	private void connectedCells(int i, int j) {
		found[i][j] = true;
		Point[] moves = validMoves(i, j, 1);
		for (int k = 0; k < moves.length; k++) {
			if (!found[moves[k].x][moves[k].y]) {
				connectedCells(moves[k].x, moves[k].y);
			}
		}
	}

	private void flipTurn() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (evenBoard && i == rows - 1 && j == columns - 1) {
					continue;
				}
				if (!isEmpty(i, j) && getColor(i, j) == turn
						&& validMoves(i, j, getHeight(i, j)).length > 0) {
					return;
				}
			}
		}
		turn = (getTurn() == PLAYER1) ? PLAYER2 : PLAYER1;
	}

	public boolean hasMoves(int i, int j) {
		return validMoves(i, j, getHeight(i, j)).length > 0;
	}

	public Point getPos(int i, int j) {
		return board[i][j].getPos();
	}

	public Cell getCell(int i, int j) {
		return board[i][j];
	}

	public int getTurn() {
		return turn;
	}

	public void setTurn(int turn) {
		this.turn = turn;
	}

	public void easyAIPlay() {
		if (isEasyAI() && turn == PLAYER2) {
			if (placingPhase) {
				Point p = freeRandom();
				put(p.x, p.y);
			} else {
				while (true) {
					Random rand = new Random();
					int i = rand.nextInt(rows);
					int j = rand.nextInt(columns);
					if (evenBoard && i == rows - 1 && j == columns - 1) {
						continue;
					}
					if (getColor(i, j) == PLAYER2) {
						Point[] moves = validMoves(i, j, getHeight(i, j));
						if (moves.length > 0) {
							int m = rand.nextInt(moves.length);
							if (move(i, j, moves[m].x, moves[m].y)) {
								removeInvalid();
								flipTurn();
								break;
							}
						}
					}
				}

			}
		}
	}

	public String toString() {
		String s = "";
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {

				s += getColor(i, j) + "  ";
			}
			s += "\n";
		}
		return s;
	}

	public void setEasyAI(boolean easyAI) {
		this.easyAI = easyAI;
	}

	public boolean isEasyAI() {
		return easyAI;
	}

	public boolean isEvenBoard() {
		return evenBoard;
	}

	@SuppressWarnings("unchecked")
	public Board clone() {
		Board b = new Board(rows,columns);
		
		for(int i=0; i<rows; i++){
			for(int j=0; j<columns; j++){
				if(board[i][j]==null||isEmpty(i, j)) continue;
				Stack<Ring> original = new Stack<Ring>();
				Cell c = new Cell(new Point(board[i][j].getPos().x, board[i][j].getPos().y));
				Stack<Ring> tmp = new Stack<Ring>();
				while (!board[i][j].cell.isEmpty()) {
					tmp.push(board[i][j].cell.pop());
				}
				while (!tmp.isEmpty()) {
					original.push(tmp.peek());
					c.cell.push(tmp.pop());
				}
				board[i][j].cell = original;
				b.board[i][j] = c;
			}
		}
		b.boardSize = boardSize;
		b.easyAI = easyAI;
		b.evenBoard = evenBoard;
		b.freeCells = (ArrayList<Point>)freeCells.clone();
		b.placedPieces = placedPieces;
		b.placingPhase = placingPhase;
		b.turn = turn;
		return b;
	}
}
