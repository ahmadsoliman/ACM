import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import eg.edu.guc.chessboard.ChessBoard;

public class ChessBoardPublicTests
{
    static final int   PLAYER0 = 0;
    static final int   PLAYER1 = 1;

    private ChessBoard instance;

    @Before
    public void before()
    {
        instance = new ChessBoard();
    }

    @Test(timeout = 1000)
    public void testKingPlayer0()
    {
        String[] board = {"....k...", "........", "........", "........",
                "........", "........", "....K..." };
        assertEquals("Player 0 has the king only.", 1, instance.getCount(board,
                PLAYER0));
    }

    @Test(timeout = 1000)
    public void testKingAndQueenPlayer0()
    {
        String[] board = {"....k...", "........", "........", "........",
                "........", "........", "........", "...QK..." };
        assertEquals("Player 0 has the king and queen.", 2, instance.getCount(
                board, PLAYER0));
    }

    @Test(timeout = 1000)
    public void test8PawnsAndKingPlayer1()
    {
        String[] board = {"....k...", "pppppppp", "........", "........",
                "........", "........", "........", "...QK..." };
        assertEquals("Player 1 has 1 king and 8 pawns.", 9, instance.getCount(
                board, PLAYER1));
    }

    @Test(timeout = 1000)
    public void testNoPlayer0()
    {
        String[] board = {"....k...", "pppppppp", "........", "........",
                "........", "........", "........", "........" };
        assertEquals("Player 0 has nothing left.", 0, instance.getCount(board,
                PLAYER0));
    }

    @Test(timeout = 1000)
    public void testFullHouse()
    {
        String[] board = {"rnbqkbnr", "pppppppp", "........", "........",
                "........", "........", "PPPPPPPP", "RNBQKBNR" };
        assertEquals("Both players have all their pieces.", 16, instance
                .getCount(board, PLAYER0));
    }

}
