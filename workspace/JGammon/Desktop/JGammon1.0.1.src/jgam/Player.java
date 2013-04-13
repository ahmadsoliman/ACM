/*
 JGammon: A Backgammon client with nice graphics written in Java
 Copyright (C) 2005 Mattias Ulbrich

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
package jgam;

import java.io.IOException;
import java.util.*;

import jgam.util.IntList;

/**
 * This class captures a player(party) involved in the backgammon game.
 *
 * Each player knows about its chips in the game.
 * Can thus calculate possible moves and check whether a move is valid or not.
 *
 * Some behaviour is different between remote and local players so this class is
 * abstract.
 *
 * @author Mattias Ulbrich
 */
public abstract class Player {

    public static final int GAMMON = 2;
    public static final int BACKGAMMON = 3;
    public static final int ORDINARY = 1;

    public static final int ROLL = 0;
    public static final int DOUBLE = 100;

    public static final int GIVE_UP = ORDINARY;
    public static final int GIVE_UP_GAMMON = GAMMON;
    public static final int GIVE_UP_BACKGAMMON = BACKGAMMON;

    private String name;
    private Game game;
    private int shownDice[];

    private ResourceBundle msg = ResourceBundle.getBundle("jgam.msg.Player");

    // 0:off  1:24 board  25:bar
    private int board[];
    // one chip can be dragged arround
    // this is substracted for the the draggingQueries!
    private int draggingAround;
    private IntList remainingHops;
    // number of chips placed during iniboard

    public Player(String name) {
        this.name = name;
        initBoard();
    }

    public Player() {
        initBoard();
    }

    /**
     * sets the Game.
     * @param game Game
     * @throws happens in NetworkPlayer
     */
    public void setGame(Game game) throws IOException, ProtocolException {
        this.game = game;
    }

    public Player getOtherPlayer() {
        return game.getOtherPlayer(this);
    }

    /**
     * initial position of the chips.
     *
     * Can be changed for debug purposes with system property
     */
    private void initBoard() {
        String sys = System.getProperty("jgam.initialboard");
        board = new int[26];

        if (sys == null) {
            board[24] = 2;
            board[13] = 5;
            board[8] = 3;
            board[6] = 5;
        } else {
            int total = 0;
            for (int i = 1; i < board.length; i++) {
                board[i] = (int) (sys.charAt(i - 1) - '0');
                total += board[i];
            }
            board[0] = 15 - total;
        }
    }

    /**
     * call this with care!
     */
    public void setBoard(int[] newBoard) {
        assert newBoard.length == 26;
        board = (int[])newBoard.clone();
    }

    public int getJag(int pos) {
        return board[pos];
    }

    /**
     * get the content of a jag.
     * If one of these is currently dragged around (UI)
     * one less is returned
     * @param pos jag number
     * @return number of chips on this jag
     */
    public int getJagWithDragging(int pos) {
        if (pos == draggingAround) {
            return getJag(pos) - 1;
        } else {
            return getJag(pos);
        }
    }

    /**
     * is at this jag a single chip that can be thrown out?
     * @param i jagindex
     * @return true iff there is
     */
    private boolean isPlot(int i) {
        return getJag(i) == 1;
    }

    /**
     * check whether all are at home.
     * I can start playing out by then.
     * @return true iff there are no chips on jags 7 - 25.
     */
    public boolean areAllAtHome() {
        return maxJag() <= 6;
    }

    public int[] getShownDice() {
        return shownDice;
    }


    /**
     * can i still make a move with the remaining dice-moves.
     *
     * To be able to make a move, it suffices to be able to
     * move from one jag one length.
     *
     * @return true iff I can still move
     */
    public boolean canMove() {
        IntList dist = remainingHops.distinctValues();
        for (int i = 0; i < dist.length(); i++) {
            for (int jag = 1; jag <= 25; jag++) {
                if (isValidMove(jag, dist.at(i))) {
                    return true;
                }
                if (isValidMove(jag, jag)) { // play out
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * is a move from a jag with a given length possible.
     * The remaininging steps are taken into consideration.
     * If all are at home then steps can be used to play out
     * @param from jag to start at
     * @param length length ot the move
     * @return true iff possible
     */
    public boolean isValidMove(int from, int length) {
        return canMove(board, from, length, remainingHops);
    }


    /**
     * get all moves that are possible from a specific startjag on.
     * The remaining steps are taken into consideration. A move may consist
     * of multiple hops.
     *
     * @param from jag to start at
     * @param List of Move objects
     */
    public List getPossibleMovesFrom(int from) {
        IntList rem = (IntList) remainingHops.clone();
        int[] brd = (int[])board.clone();

        return getPossibleMovesFrom(from, brd, rem);
    }

    private List getPossibleMovesFrom(int from, int[] locBoard,
                                      IntList locRemaining) {
        IntList hops = locRemaining.distinctValues();
        List ret = new ArrayList();

        for (int i = 0; i < hops.length(); i++) {
            int length = hops.at(i);
            if (canMove(locBoard, from, length, locRemaining)) {
                // change localBoard
                int to = Math.max(0, from-length);
                locRemaining.remove(length);
                locBoard[from]--;
                locBoard[to]++;
                SingleMove origMove = new SingleMove(this, from, to);
                ret.add(origMove);
                for (Iterator iter = getPossibleMovesFrom(to,
                        locBoard,
                        locRemaining).iterator(); iter.hasNext(); ) {
                    Move move = (Move) iter.next();
                    ret.add(new MultiMove(origMove, move));
                }
                // undo changes
                locRemaining.add(length);
                locBoard[to]--;
                locBoard[from]++;
            }
        }
        return ret;
    }


    /**
     * checks for a given board whether a certain single hop can be made or not.
     *
     * 0. 1<=length<=6, from >= length
     * 1. 1<=from<=25 (not 0!) must have at least one chip of my colour
     * 2. if bar > 0 then from must be 25
     * 3. to(=from-length) may have at most one chip of the opponent.
     * 4. if to==0 then maxjag must be <= 6
     * 5. length must be in remainingMoves or maxJag() == from and remainingMoves.max() > from
     *
     * The parameters got the prefix loc to distinguish them from the gloabal
     * values
     *
     * @param board int[] the board to check the move upon
     * @param remainingMoves the remaining moves
     * @return true if a move can be made
     */
    private boolean canMove(int[] locBoard, int from, int length,
                            IntList locHops) {

        // correct the length if it left the board!
        length = Math.min(from, length);    // ensures length <= from
        int to = from - length;
        int maxjag = 0;
        for (int i = 0; i < locBoard.length; i++) {
            if (locBoard[i] > 0) {
                maxjag = i;
            }
        }

        // 0.
        if (length <= 0 || length > 6) {
            return false;
        }

        // 1.
        if (from <= 0 || from > 25) {
            return false;
        }

        if (locBoard[from] == 0) {
            return false;
        }

        // 2.
        if (locBoard[25] > 0 && from != 25) {
            return false;
        }

        // bugfix => goal == 0 ==> other[25] may be > 1 (0.9.24)
        // 3.
        if (to != 0 && getOtherPlayer().getJag(25 - to) > 1) {
            return false;
        }

        // 4.
        if (to == 0 && maxjag > 6) {
            return false;
        }

        // 5.
        if (locHops.contains(length)) {
            return true;
        }

        if (from < 6 && maxjag == from && locHops.max() > length) {
            return true;
        }

        return false;
    }

    public int getBar() {
        return board[25];
    }

    public int getOff() {
        return board[0];
    }


    /**
     * from the given dice deduce what move-lengths i could make.
     * doublets count 4 times! Store the result in remainingMoves.
     * @return IntList
     */
    public IntList setPossibleHops(int dice[]) {

        if (dice == null || dice.length != 2) {
            return remainingHops = null;
        }

        int[] steps = dice;

        if (dice[0] == dice[1]) { // doublets
            steps = new int[] {dice[0], dice[0], dice[0],
                    dice[0]};
        }

        remainingHops = new IntList(steps);

        return remainingHops;

    }


    /**
     * sets the dice that have been thrown and deduce the moves that can be made
     * with these.
     * @param dice int[]
     */
    public void setDice(int[] dice) {
        setShownDice(dice);
        setPossibleHops(dice);
    }

    public void setDice(int a) {
        setDice(new int[] { a });
    }

    /**
     * sets the dice that are shown. The moves that can be made are NOT changed.
     */
    public void setShownDice(int[] dice) {
        shownDice = dice;
    }

    public String getName() {
        return name;
    }

    public void setName(String n) {
        name = n;
    }

    public String toString() {
        return getName();
    }

    /**
     * player 1 is white, player 2 is blue
     * @return String "blue" or "white"
     */
    public String getColor() {
        return msg.getString(isWhite() ? "white" : "blue");
    }

    public javax.swing.ImageIcon getChipIcon() {
        return isWhite() ? Board.whiteChip : Board.blueChip;
    }

    /**
     * a message is passed from the awtthread. This can be a move or a button
     * push. Only human players pay attention
     *
     * @param msg Message-Object
     */
    public abstract void handle(Object msg);

    /**
     * get the next Move.
     * This either single move, or a multi move
     */
    public abstract Move move() throws Exception;

    /**
     * if this player wants to doube or give up before his/her/move.
     * @return one of ROLL, DOUBLE, GIVE_UP_*
     * @param rollOnly if true, only ROLL is permitted
     */
    public abstract int nextStep(boolean rollOnly) throws Exception;

    public int nextStep() throws Exception {
        return nextStep(false);
    }

    /**
     * the other player offers something. This player may accept or not.
     * Neither true nor false do imply finishing the game!
     *
     * @param offer the offer as index number DOUBLE, GIVE_UP_*
     * @return true if the offer is accepted.
     */
    public abstract boolean acceptsOffer(int offer) throws Exception;

    /**
     * is this player a remote player?
     * @return true if so
     */
    abstract public boolean isRemote();

    /**
     * tell this player that the opponent wants to throw the dice
     */
    abstract public void informRoll() throws Exception;

    /**
     * tell this player that the opponent has made a move
     * @param move the move made
     */
    abstract public void informMove(SingleMove move) throws Exception;

    /**
     * free resources such as sockets ...
     */
    public void dispose() { }

    /**
     * tell this player whether the opponent accepted an offer or not
     * @param answer the answer to be told.
     */
    abstract public void informAccept(boolean answer) throws Exception;

    /**
     * are UI-moves to be made right now?
     * @return true if yes
     */
    abstract public boolean isWaitingForUIMove();


    /**
     * a player has won when all the chips are in the jag 0
     * @return true iff this player has won
     */
    public boolean hasWon() {
        return getJag(0) == 15;
    }

    /**
     * get the underlying game
     * @return game to which this belongs
     */
    public Game getGame() {
        return game;
    }


    /**
     * apply a move to the data.
     * This move must be a single hop
     * @param m Move to be archived.
     */
    public void performMove(SingleMove m) {

        if (!isValidMove(m.from(), m.length())) {
            throw new IllegalArgumentException("Illegal move " + m);
        }

        m.setPlayer(this);
        animateMove(m);
        if (getOtherPlayer().isPlot(25 - m.to())) {
            m.setBeat(true);
            getOtherPlayer().discardAtJag(25 - m.to());
        }
        board[m.from()]--;
        board[m.to()]++;
        if (!remainingHops.remove(m.length())) {
            remainingHops.removeMax();
        }
    }

    /**
     * show the animation for this move. only remote players do
     * @param m Move to animate
     */
    abstract public void animateMove(Move m);

    /**
     * throw out a chip.
     * @param i jag to operate on
     */
    private void discardAtJag(int i) {
        if (isPlot(i)) {
            board[i]--;
            board[25]++;
        }
    }

    /**
     * by convention player 1 is white
     * @return true iff this is player 1
     */
    public boolean isWhite() {
        return game.getPlayerWhite() == this;
    }

    /**
     * set the jag from that is currently one chipped dragged around.
     * set -1 to clear this.
     *
     * @param jag jag the chip is from.
     */
    public void setDragged(int jag) {
        draggingAround = jag;
    }

    /**
     *  get the jag with the highest index that contains at least 1 chip
     */
    public int maxJag() {
        for (int i = 25; i >= 0; i--) {
            if (getJag(i) > 0) {
                return i;
            }
        }

        return -1;
    }

    /**
     * adjust local jag number to (glibal) hite jag number.
     * this is only done, if 1<=no<=24, not for 0, 25
     * White doesnt need to be adjusted
     */
    public int adjustJag(int jag) {
        if (!isWhite() && jag >= 1 && jag <= 24) {
            return 25 - jag;
        } else {
            return jag;
        }
    }

    public int[] getBoard() {
        return (int[])board.clone();
    }

    public IntList getRemainingHops() {
        return (IntList)remainingHops.clone();
    }

}
