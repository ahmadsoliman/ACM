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

import java.io.*;
import java.util.*;

import com.Ostermiller.util.Base64;
import jgam.util.FormatException;

/**
 *
 * A BoardSnapshot describes a snapshot of a backgammon board.
 *
 * Such a snapshot can be saved to disk.
 * It can be also loaded to continue a game.
 * It can be transmitted and received on a single line.
 *
 * transmitted data is:
 *    0-23 jags:  [i] > 0 ==> white[i+1] = [i]
 *                [i] < 0 ==> blue[24-i] = [i]
 *    24 : white[25]
 *    25 : blue[25]
 *    26 : doubleCube   >= 1 white may double
 *                      <= 1 blue may double
 *    27 : white's turn?
 *    28 : the dice  (0-35)
 *
 * File Format:
 *
 * #.... are ignored
 * empty lines are ignored
 *
 * 1. white board
 * 2. blue board
 * 3. whose turn line
 * 4. double cube
 * 5. dice line
 *
 *
 * The following data is stored locally but neither transmitted over the
 * connection nor saved to / read from a file
 *  History
 * @todo transmit history over the connection and save/load in files
 *
 * @author Mattias Ulbrich
 * @version 1.0
 */
public class BoardSnapshot {

    public final static String NEWGAME = "NEWGAME";
    public final static String SETUPBOARD = "SETUPBOARD";

    // stores all the data!
    private int[] whiteBoard = new int[26];
    private int[] blueBoard = new int[26];

    // the comment for this board. Can be read from the stream or set
    // by setComment
    private String comment;

    private boolean whitesTurn;
    private int doubleCube = 1;
    private int[] dice;

    private List history;

    private BoardSnapshot() {}

    /**
     * read a snapshot saved to a file.
     * @param f File to be read
     * @throws IOException file not found or read error
     */
    public BoardSnapshot(File f) throws IOException, FormatException {
        this(new FileReader(f));
    }

    /**
     * read a snapshot from a Reader
     */
    public BoardSnapshot(Reader r) throws IOException, FormatException {

        try {
            String header = readLine(r);
            if (!new String(header).equals("JGAM")) {
                throw new FormatException("Expected JGAM Header; received: " +
                                          header);
            }

            comment = readLine(r);
            String whiteLine = readLine(r);
            String blueLine = readLine(r);
            String turnLine = readLine(r);
            String cubeLine = readLine(r);
            String diceLine = readLine(r);

            parseLine(whiteBoard, whiteLine);
            parseLine(blueBoard, blueLine);
            whitesTurn = turnLine.equalsIgnoreCase("white");

            String d[] = cubeLine.split(" ");
            doubleCube = Integer.parseInt(d[0]);
            if (d.length == 2 && d[1].equalsIgnoreCase("blue")) {
                doubleCube *= -1;
            }

            d = diceLine.split(" ");
            if (d.length == 2) {
                dice = new int[2];
                dice[0] = Integer.parseInt(d[0]);
                dice[1] = Integer.parseInt(d[1]);
            }
        } catch (IOException ex) {
            throw ex;
        } catch (Exception ex) {
            throw new FormatException(ex);
        }
    }

    /**
     * parse a line that describes a board:
     * read in the jags 1-24 and the bar (25), separated by ":"
     * the chips already played off are then calculated
     *
     * @param board int[] array to write to
     * @param line read line
     */
    private void parseLine(int[] board, String line) {
        String elems[] = line.split(":");
        assert elems.length == 25;
        int total = 0;
        for (int i = 0; i < elems.length; i++) {
            board[i + 1] = Integer.parseInt(elems[i]);
            total += board[i + 1];
        }
        board[0] = 15 - total;
    }

    /**
     * take a snapshot from a game
     * @param game Game to snapshoot
     */
    public BoardSnapshot(Game game) {
        whiteBoard = game.getPlayerWhite().getBoard();
        blueBoard = game.getPlayerBlue().getBoard();
        whitesTurn = (game.getCurrentPlayer() == game.getPlayerWhite());
        doubleCube = game.getDoubleValue();
        doubleCube *= (game.mayDouble(game.getPlayerWhite()) ? 1 : -1);
        dice = game.getDice();
        history = new LinkedList(game.getHistory());
    }

    /**
     * read a line that is received on the reader.
     *
     * it is either NEWGAME --> return null ; no snapshot
     * or is SETUPBOARD --> set board accordingly
     * @param r BufferedReader
     * @return BoardSnapshot
     * @throws ProtocolException
     * @throws IOException
     */
    public static BoardSnapshot readSnapshotLine(BufferedReader r) throws
            ProtocolException, IOException {

        String line = r.readLine();
        if (line.equals(NEWGAME)) {
            return null; // null is for new game here
        }

        if (!line.startsWith(SETUPBOARD)) {
            throw new ProtocolException(SETUPBOARD + " or " + NEWGAME +
                                        " expected; got:" + line);
        }

        byte[] data = Base64.decodeToBytes(line.substring(11));
        BoardSnapshot ret = new BoardSnapshot();

        // 1. the board
        int whiteTotal = 0, blueTotal = 0;
        for (int i = 0; i < 24; i++) {
            if (data[i] > 0) {
                ret.whiteBoard[i + 1] = data[i];
                whiteTotal += data[i];
            } else {
                ret.blueBoard[24 - i] = -data[i];
                blueTotal += -data[i];
            }
        }

        // 2. the bars
        ret.whiteBoard[25] = data[24];
        whiteTotal += data[24];
        ret.blueBoard[25] = data[25];
        blueTotal += data[25];

        // ==> the outs
        ret.whiteBoard[0] = 15 - whiteTotal;
        ret.blueBoard[0] = 15 - blueTotal;

        // 3. doubleCube
        ret.doubleCube = data[26];

        // 4. white's turn
        ret.whitesTurn = data[27] == 1;

        if (data[28] != -1) {
            ret.dice = new int[2];
            ret.dice[0] = (data[28] / 6) + 1;
            ret.dice[1] = (data[28] % 6) + 1;
        }

        return ret;
    }

    public String toSendLine() {

        byte[] data = new byte[29];

        // 1. the board
        for (int i = 0; i < 24; i++) {
            data[i] = (byte) (whiteBoard[i + 1] - blueBoard[24 - i]);
        }

        // 2. the bars
        data[24] = (byte) whiteBoard[25];
        data[25] = (byte) blueBoard[25];

        // 3.+4. doubleCube and white's turn
        data[26] = (byte) doubleCube;
        data[27] = whitesTurn ? (byte) 1 : (byte) 0;

        if (dice == null) {
            data[28] = -1;
        } else {
            data[28] = (byte) ((dice[0] - 1) * 6 + dice[1] - 1);
        }

        return SETUPBOARD + " " + Base64.encodeToString(data, false);
    }

    /**
     * ignore comments (#....)
     * return null at end of stream
     * @param r Reader
     * @return String
     * @throws IOException
     */
    public static String readLine(Reader r) throws IOException {
        while (true) {
            StringBuffer ret = new StringBuffer();
            int c = r.read();
            while (c != -1 && c != '\n') {
                if (c != '\r') {
                    ret.append((char) c);
                }
                c = r.read();
            }
            if (c == -1 && ret.length() == 0) {
                return null;
            }

            String s = ret.toString();
            if (!s.startsWith("#") && s.trim().length() > 0) {
                return s;
            }
        }
    }

    public Player getCurrentPlayer(Player white, Player blue) {
        return whitesTurn ? white : blue;
    }

    public int[] getWhiteBoard() {
        return whiteBoard;
    }

    public int[] getBlueBoard() {
        return blueBoard;
    }

    public int getDoubleDice() {
        return Math.abs(doubleCube);
    }

    public Player getDoublePlayer(Player white, Player blue) {
        if (doubleCube == 1) {
            return null; // both may double
        }

        if (doubleCube > 1) {
            return white;
        }

        return blue;
    }

    public List getHistory() {
        return history;
    }

    public int[] getDice() {
        return dice;
    }

    public void saveTo(File file) throws IOException {
        PrintWriter pw = new PrintWriter(new FileWriter(file));
        pw.println("JGAM");
        pw.println("# This is a JGam saved backgammon board");
        pw.println("# Created: " + new Date());
        pw.println("# Comment: ");
        pw.println(comment);

        pw.println("\n#white's board:");
        for (int i = 1; i < 25; i++) {
            pw.print("" + whiteBoard[i] + ":");
        }
        pw.println(whiteBoard[25]);

        pw.println("\n#blue's board:");
        for (int i = 1; i < 25; i++) {
            pw.print("" + blueBoard[i] + ":");
        }
        pw.println(blueBoard[25]);

        pw.println("\n# Whose turn is it?");
        pw.println(whitesTurn ? "white" : "blue");

        pw.println("\n# Double cube");
        pw.println(doubleCube);

        pw.println("\n# the dice (if any)");
        if (dice == null) {
            pw.println("nodice");
        } else {
            pw.println(dice[0] + " " + dice[1]);
        }

        pw.flush();
        pw.close();

    }

    public String getComment() {
        return comment;
    }

    public void setComment(String comment) {
        this.comment = comment;
    }

    /**
     * Indicates whether this snapshot is equal to a different one.
     *
     * Snapshots are equal if:
     * - boards are equally setup.
     * - player in turn are equal
     * - dice are equal
     * - doubleDice are equal
     *
     * @param obj the snapshot object with which to compare.
     * @return <code>true</code> if this object is the same as the obj
     *   argument; <code>false</code> otherwise.
     */
    public boolean equals(Object obj) {
        BoardSnapshot other = (BoardSnapshot)obj;
        return (intArrayEqual(this.getBlueBoard(), other.getBlueBoard()) &&
                intArrayEqual(this.getWhiteBoard(), other.getWhiteBoard()) &&
                this.getDoubleDice() == other.getDoubleDice() &&
                this.whitesTurn == other.whitesTurn &&
                intArrayEqual(this.getDice(), other.getDice()));
    }

    private boolean intArrayEqual(int[]a, int[]b) {
        if(b.length != a.length)
            return false;

        for (int i = 0; i < a.length; i++) {
            if(a[i] != b[i])
                return false;
        }

        return true;
    }

}
