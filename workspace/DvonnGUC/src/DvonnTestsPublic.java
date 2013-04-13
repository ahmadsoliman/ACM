import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertEquals;

import org.junit.Test;

import eg.edu.guc.dvonn.engine.Board;

public class DvonnTestsPublic {

	@Test(timeout = 5000)
	public void testConstructor() {
		new Board(5, 11);
	}

	@Test(timeout = 5000)
	public void testRandomFill() {
		Board board = new Board(5, 11);
		board.fillRandom();
		for (int row = 0; row < 5; row++) {
			for (int col = 0; col < 11; col++) {
				assertFalse("Every cell in the board must contain something",
						board.isEmpty(row, col));
			}
		}
	}

	@Test(timeout = 5000)
	public void testEvenSizedBoard() {
		Board board = new Board(3, 2);
		board.fillRandom();
		int numberRed = 0, numberWhite = 0, numberBlack = 0;
		for (int row = 0; row < 3; row++) {
			for (int col = 0; col < 2; col++) {
				switch (board.getColor(row, col)) {
				case 0:
					numberRed++;
					break;
				case 1:
					numberWhite++;
					break;
				case 2:
					numberBlack++;
					break;
				}
			}
		}
		assertEquals(3, numberRed);
		assertEquals(1, numberWhite);
		assertEquals(1, numberBlack);
	}

	@Test(timeout = 5000)
	public void testPutInFirstPhase() {
		Board board = new Board(5, 11);
		assertTrue(board.put(0, 0));
		assertFalse(board.isEmpty(0, 0));
	}

	@Test(timeout = 5000)
	public void testPutInSecondPhase() {
		Board board = new Board(5, 11);
		board.fillRandom();
		assertFalse(board.put(1, 1));
	}

	@Test(timeout = 5000)
	public void testCorrectMove() {
		Board board = TestHelper.setupGame();
		assertTrue(board.move(0, 1, 0, 0)); // Black's turn
		assertTrue(board.move(0, 2, 0, 3)); // White's turn
	}

	@Test(timeout = 5000)
	public void testMoveToEmptyPlace() {
		Board board = TestHelper.setupGame();
		board.move(0, 1, 0, 0); // Black's turn
		assertFalse(board.move(0, 2, 0, 1)); // White's turn
	}

	@Test(timeout = 5000)
	public void testMovingTowerOfSpecificHeight() {
		Board board = TestHelper.setupGame();
		board.move(0, 1, 0, 0); // Black's turn
		board.move(0, 2, 1, 1); // White's turn
		assertTrue(board.move(0, 0, 2, 0)); // Black's turn
	}

	@Test(timeout = 5000)
	public void testNotAllowingTowerToMoveMoreThanHeight() {
		Board board = TestHelper.setupGame();
		board.move(0, 1, 0, 0); // Black's turn
		board.move(0, 2, 1, 1); // White's turn
		assertFalse(board.move(0, 0, 3, 0)); // Black's turn
	}

	@Test(timeout = 5000)
	public void testMoveFromEmptyPlace() {
		Board board = TestHelper.setupGame();
		board.move(0, 1, 0, 0); // Black's turn
		board.move(0, 2, 0, 3); // White's turn
		assertFalse(board.move(0, 1, 0, 0));
	}

	@Test(timeout = 5000)
	public void testNotAllowingMoveWhenNotInYourTurn() {
		Board board = TestHelper.setupGame();
		assertFalse(
				"Should not allow moving a white piece when it is the turn of the black player",
				board.move(0, 0, 0, 1)); // Black's turn
	}

	@Test(timeout = 5000)
	public void testKeepingTurnAfterWrongMove() {
		Board board = TestHelper.setupGame();
		board.move(0, 0, 0, 1); // Black's turn
		assertTrue(board.move(0, 1, 0, 0)); // Black's turn
	}

	@Test(timeout = 5000)
	public void testIsEmptyByDefault() {
		Board board = new Board(5, 11);
		for (int row = 0; row < 5; row++) {
			for (int col = 0; col < 11; col++) {
				assertTrue(board.isEmpty(row, col));
			}
		}
	}

	@Test(timeout = 5000)
	public void testCellEmptyAfterMove() {
		Board board = TestHelper.setupGame();
		board.move(0, 1, 0, 0); // Black's turn
		assertTrue(board.isEmpty(0, 1));
	}

	@Test(timeout = 5000)
	public void testRemovingTowers() {
		Board board = TestHelper.setupGame();
		board.move(0, 1, 0, 0); // Black's turn
		board.move(0, 2, 0, 3); // White's turn
		board.move(1, 1, 0, 0); // Black's turn
		board.move(2, 1, 1, 0); // White's turn
		board.move(2, 0, 1, 0); // Black's turn
		assertTrue(board.isEmpty(0, 0));
		assertTrue(board.isEmpty(1, 0));
	}

	@Test(timeout = 5000)
	public void testGameOverInitial() {
		Board board = TestHelper.setupGame();
		assertFalse(board.isGameOver());
	}
	
	@Test(timeout = 5000)
	public void testGameOverAfterSomeMoves() {
		Board board = TestHelper.setupGame();
		board.move(0, 1, 0, 0); // Black's turn
		board.move(0, 2, 0, 3); // White's turn
		assertFalse(board.isGameOver());
	}
	
	@Test(timeout = 5000)
	public void testGameOver() {
		Board board = TestHelper.setupGame();
		TestHelper.playSetupBoard(board);
		assertTrue(board.isGameOver());
	}

	@Test(timeout = 5000)
	public void testGetWinner() {
		Board board = TestHelper.setupGame();
		TestHelper.playSetupBoard(board);
		assertEquals(
				"Number of white player should be 1 and " +
				"number for black player should be 2. " +
				"Here, white player wins.",
				1, board.getWinner()); // White (Player 1) wins
	}

	@Test(timeout = 5000)
	public void testGetColorRed() {
		Board board = TestHelper.setupGame();
		assertEquals(0, board.getColor(1, 2));
	}

	@Test(timeout = 5000)
	public void testGetColorWhite() {
		Board board = TestHelper.setupGame();
		assertEquals(1, board.getColor(0, 0));
	}

	@Test(timeout = 5000)
	public void testGetColorBlack() {
		Board board = TestHelper.setupGame();
		assertEquals(2, board.getColor(0, 1));
	}

	@Test(timeout = 5000)
	public void testGetHeight() {
		Board board = TestHelper.setupGame();
		assertEquals(1, board.getHeight(0, 1));
		board.move(0, 1, 0, 0);
		assertEquals(0, board.getHeight(0, 1));
		assertEquals(2, board.getHeight(0, 0));
	}

	@Test(timeout = 5000)
	public void testHasRed() {
		Board board = TestHelper.setupGame();
		assertTrue(board.hasRed(1, 2));
		board.move(0, 1, 1, 2);
		assertTrue(board.hasRed(1, 2));
	}
}
