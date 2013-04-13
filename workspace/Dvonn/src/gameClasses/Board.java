package gameClasses;

import java.awt.Point;
import java.io.IOException;
import java.util.Random;
import java.util.Stack;

public class Board {
	protected static Point origin = new Point(90, 268);
	protected static final int width = 71, height = 61;
	protected Cell[][] cells;
	protected Game game;
	protected Ring[] dvonn;
	private boolean[][] found;

	public Board(Game g, boolean random) throws IOException {
		game = g;
		dvonn = new Ring[3];

		// Initialize the lengths of the cells
		cells = new Cell[11][5];

		// Initializing new Cells
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 5; j++) {
				if ((i == 0 && (j == 3 || j == 4))
						|| ((i == 1 && j == 4)
								|| (i == 10 && (j == 0 || j == 1)) || (i == 9 && j == 0)))
					cells[i][j] = new Cell(false, null);
				else {
					Point p = new Point();
					p.x = (int) (origin.x + i * width - j * 0.5 * width - i * 0.3);
					p.y = origin.y - j * height;
					cells[i][j] = new Cell(true, p);
				}
			}
		}
		if (random) {
			randomInit();
		}
	}

	public void randomInit() throws IOException {
		// 3 Red Dvonn Rings
		for (int i = 0; i < 3; i++) {
			Ring r = new Ring(
					'r',
					Game.DVONN,
					"C:\\Users\\Ahmad Adel\\workspace\\Dvonn\\src\\images\\red.png",
					"");
			puchRing(r);
			dvonn[i] = r;
		}
		// 23 White, 23 Black Rings
		for (int i = 0; i < 23; i++) {
			Ring r = new Ring(
					'w',
					Game.PLAYER1,
					"C:\\Users\\Ahmad Adel\\workspace\\Dvonn\\src\\images\\white.png",
					"C:\\Users\\Ahmad Adel\\workspace\\Dvonn\\src\\images\\whiteSelected.png");
			puchRing(r);
			r = new Ring(
					'b',
					Game.PLAYER2,
					"C:\\Users\\Ahmad Adel\\workspace\\Dvonn\\src\\images\\black.png",
					"C:\\Users\\Ahmad Adel\\workspace\\Dvonn\\src\\images\\blackSelected.png");
			puchRing(r);
		}
	}

	public void puchRing(Ring r) {
		Random rand = new Random();
		Random rand2 = new Random();
		boolean found = false;
		while (!found) {
			int x = rand.nextInt(11), y = rand2.nextInt(5);
			if (cells[x][y].valid && cells[x][y].cell.size() == 0) {
				cells[x][y].cell.push(r);
				r.setPos(new Point(x, y));
				found = true;
			}
		}
	}

	public void puchRing(Ring r, Point p) {
		cells[p.x][p.y].cell.push(r);
		r.setPos(p);
	}

	public boolean canMove(Point p) {
		int x = p.x, y = p.y;
		if (y == 0 || y == 4 || x == 0 || x == 10 || (x == 1 && y == 3)
				|| (x == 9 && y == 1))
			return true;

		Move m = new Move(p, null, game);
		m.setSteps(1);
		Point[] moves = m.validMoves();
		for (int i = 0; i < moves.length; i++) {
			x = moves[i].x;
			y = moves[i].y;
			if (cells[x][y].blanked)
				return true;
		}
		return false;
	}

	public boolean isDvonn(Point p) {
		for (int i = 0; i < dvonn.length; i++) {
			if (dvonn[i].getPos().equals(p))
				return true;
		}
		return false;
	}

	public Point[] invalidRings() {
		Stack<Point> res = new Stack<Point>();
		Point[] dvonns = new Point[3];
		for (int i = 0; i < dvonn.length; i++)
			dvonns[i] = dvonn[i].getPos();

		found = new boolean[11][5];

		for (int i = 0; i < dvonns.length; i++) {
			connectedCells(dvonns[i]);
		}

		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 5; j++) {
				if (game.board.cells[i][j].valid) {
					if (!found[i][j])
						res.push(new Point(i, j));
				}
			}
		}

		Point[] resArray = new Point[res.size()];
		for (int i = 0; i < resArray.length; i++)
			resArray[i] = res.pop();
		return resArray;
	}

	public void connectedCells(Point current) {
		found[current.x][current.y] = true;
		Move m = new Move(current, null, game);
		m.setSteps(1);
		Point[] moves = m.validMovesNoBlanked();
		for (int i = 0; i < moves.length; i++)
			if (!found[moves[i].x][moves[i].y])
				connectedCells(moves[i]);
	}

	public boolean checkEnd() {
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 5; j++) {
				if (game.board.cells[i][j].valid
						&& !game.board.cells[i][j].blanked) {
					if (game.board.cells[i][j].cell.peek().getPlayer() == Game.DVONN)
						continue;
					Point p = new Point(i, j);
					Move m = new Move(p, null, game);
					if (m.validMovesNoBlanked().length > 0)
						return false;
				}
			}
		}
		return true;
	}

	public boolean canPlayerMove() {
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 5; j++) {
				if (game.board.cells[i][j].valid
						&& !game.board.cells[i][j].blanked) {
					if (game.board.cells[i][j].cell.peek().getPlayer() == game.playerTurn) {
						Point p = new Point(i, j);
						Move m = new Move(p, null, game);
						if (m.validMovesNoBlanked().length > 0)
							return true;
					}
				}
			}
		}
		return false;
	}

}
