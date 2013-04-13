import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import eg.edu.guc.chessboard.ChessBoard;

public class ChessBoardPrivateTests {
	static final int PLAYER0 = 0;
	static final int PLAYER1 = 1;
	
	private ChessBoard instance;
    @Before
    public void before()
    {
        instance = new ChessBoard();
    }
	
	@Test(timeout = 1000)
	public void testEmptyBoard() {
		String[] board = {
				"........",
				"........",
				"........",
				"........",
				"........",
				"........",
				"........",
				"........"
			};
		assertEquals("Board has no pieces.", 
		        0, instance.getCount(board, PLAYER0));
		assertEquals("Board has no pieces.", 
                0, instance.getCount(board, PLAYER1));
	}

	@Test(timeout = 1000)
	public void testZeroSizedBoard() {
		String[] board = {};
		assertEquals("Board size is 0x0.", 
		        0, instance.getCount(board, PLAYER0));
	}

	@Test(timeout = 1000)
	public void test1RowBoard() {
		String[] board = {
				"K......."
			};
		assertEquals("Board size is 1x8 with one player 0 king", 
		        1, instance.getCount(board, PLAYER0));
	}

	@Test(timeout = 1000)
	public void test1ColumnBoard() {
		String[] board = {
				".",
				".",
				".",
				".",
				"k",
				".",
				".",
				".",
			};
		assertEquals("Board size is 8x1 with one player 1 king.", 
		        1, instance.getCount(board, PLAYER1));
	}

	@Test(timeout = 1000)
	public void test8KingsPlayer1() {
		String[] board = {
				"kkkkkkkk"
			};
		assertEquals("Player 1 has cloned his king and has dominated", 
		        8, instance.getCount(board, PLAYER1));
	}

	@Test(timeout = 1000)
	public void testSymbolsBoardNoPieces() {
		String[] board = {
				"123",
				"456",
				"789",
				"*0#"
			};
		assertEquals("Pieces are either upper case or lower case alphabet characters.", 
		        0, instance.getCount(board, PLAYER0));
	}

	@Test(timeout = 1000)
	public void testAPieceOfCode() {
		String[] board = {
				"int factorIal(int n) {",
				"    int n = 8, r = 1; ",
				"    while (n-- > 1)   ",
				"        r *= n;       ",
				"    return r;         ",
				"}                     "
			};
		assertEquals("Symbols should be treated as empty cells.", 
		        1, instance.getCount(board, PLAYER0));
	}

	@Test(timeout = 1000)
	public void testAllKeyBoardKeysWithShift() {
		String[] board = {
				"!@#$%^&*()_+",
				"QWERTYUIOP{}",
				"ASDFGHJKL:\"\\",
				"ZXCVBNM<>???"
			};
		assertEquals("All 26 upper case alphabet characters.", 
		        26, instance.getCount(board, PLAYER0));
	}

	@Test(timeout = 1000)
	public void testAllKeyBoardKeysWithoutShift() {
		String[] board = {
				"1234567890-=",
				"qwertyuiop[]",
				"asdfghjkl;'\\",
				"zxcvbnm,./~\\"
			};
		assertEquals("All 26 upper case alphabet characters.", 
		        26, instance.getCount(board, PLAYER1));
	}
}
