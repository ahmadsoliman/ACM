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

import java.net.*;
import java.io.*;
import java.util.*;
import javax.swing.*;

/**
 * This derivate of player is used to connect to a gnu backgammon server.
 *
 * In order to start the server you have to run the gnubg on commandline
 * and enter something like "external localhost:2222" to listen on port 2222
 *
 * You can then connect to this port with this class here.
 *
 * Attention:
 * I do not know anything about the protocol that is used by gnubg.
 * I have just guessed a little, but it seems to work.
 *
 * @author Mattias Ulbrich
 */
public class GnubgPlayer extends Player {

    private Socket socket;
    private BufferedReader reader;
    private Writer writer;
    private List storedMoves;
    private Random random;

    public GnubgPlayer(String server, int port) throws IOException {
        socket = new Socket(server, port);
        reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        writer = new OutputStreamWriter(socket.getOutputStream());
        setName("GNU Backgammon");
        random = new Random();
    }

    /**
     * the game to which this player belongs is about to be aborted.
     *
     */
    public void abort() {
        try {
            socket.close();
        } catch (Exception ex) {
            // savely ignore
        }
    }

    /**
     * the other player offers something.
     *
     * Send offer to gnubg.
     * Give ups are not accepted ...
     *
     * @param offer the offer as index number DOUBLE, GIVE_UP_*
     * @return true if the offer is accepted.
     * @throws Exception
     */
    public boolean acceptsOffer(int offer) throws Exception {
        if (offer == DOUBLE) {
            sendBoard(true);
            String line = reader.readLine();
            if (!line.equals("take") && !line.equals("drop")) {
                throw new ProtocolException("Expected ACCEPT or DECLINE; got: " +
                                            line);
            }
            return line.equals("take");
        } else if (offer == GIVE_UP_BACKGAMMON) {
            return true;
        } else {
            JOptionPane.showMessageDialog(getGame().getJGam().getFrame(),
                                          "GNUbg will never accept a give up (except backgammon)");
            return false;
        }
    }

    /**
     * show the animation for this move.
     *
     * @param m Move to animate
     */
    public void animateMove(Move m) {
        BoardAnimation anim = new BoardAnimation(m.player(), m.from(), m.to());
        anim.animate(getGame().getBoard());
    }

    /**
     * a message is passed from the awtthread.
     *
     * THis is not an interactive player.
     *
     * @param msg Message-Object
     */
    public void handle(Object msg) {}

    /**
     * send the appropriate board
     *
     * @param answer the answer to be told.
     * @throws Exception
     */
    public void informAccept(boolean answer) throws Exception {    }

    /**
     * send the appropriate board if it has been the last move
     *
     * @param move the move made
     * @throws Exception
     * @todo Implement this jgam.Player method
     */
    public void informMove(SingleMove move) throws Exception {}

    /**
     * tell this player that the opponent has thrown the dice.
     * send the appropriate board
     *
     * @param val the value of the dice
     * @throws Exception
     * @todo Implement this jgam.Player method
     */
    public void informRoll() throws Exception {
    }

    /**
     * gnubg is remote
     *
     * @return true if so
     */
    public boolean isRemote() {
        return true;
    }

    /**
     * we dont
     *
     * @return true if yes
     * @todo Implement this jgam.Player method
     */
    public boolean isWaitingForUIMove() {
        return false;
    }

    /**
     * get the next Move.
     *
     * when rolling the dice read one line and parse it. separated by
     * spaces there several moves.
     *
     * Upon the next call to move return one of them
     *
     * @throws Exception
     * @return Move
     * @todo Implement this jgam.Player method
     */
    public Move move() throws Exception {
        if (storedMoves == null) {
            sendBoard();
            String line = reader.readLine();
            String[] moves = line.split(" ");
            storedMoves = new LinkedList();
            for (int i = 0; i < moves.length; i++) {
                storedMoves.add(new SingleMove(moves[i]));
            }
        }
        return (Move) storedMoves.remove(0);
    }

    /**
     * if this player wants to doube or give up before his/her/move.
     *
     * @return one of ROLL, DOUBLE, GIVE_UP_*
     * @throws Exception
     * @todo Implement this jgam.Player method
     */
    public int nextStep(boolean rollOnly) throws Exception {
        if (rollOnly) {
            return ROLL;
        }

        setDice(null);
        sendBoard();
        String line = reader.readLine();
        if (line.equals("roll")) {
            storedMoves = null;
            return ROLL;
        } else if (line.equals("double")) {
            return DOUBLE;
        } else {
            throw new ProtocolException("roll or double expected: " + line);
        }
    }


    /**
     * make a FIBS String to send to gnubg. Not all of the fields are set
     * correctly only the ones needed!
     *
     * gnubg is player2
     *
     * Format: (separated by ":")
     *   "board"
     *   name player1     (here only "player1")
     *   name player2
     *   match bestOf     (use 7 here)
     *   score player1    (use 0:0 here)
     *   score player0
     *   bar player2      (<0)
     *   all the jags : >0 player1 <0 player2
     *   bar player1
     *   who's turn       (here -1)
     *   dice1
     *   dice2
     *   dice1
     *   dice2
     *   DoubleCube
     *   player1 can double
     *   player2 can double
     *   double proposed
     *   "1"
     *   "-1"
     *   "0"
     *   "25"
     *   off player1
     *   off player2
     *   "0" x 6
     *
     * @return String FIBS board-string
     */
    private String makeBoard(boolean doubleProposed) {
        StringBuffer ret = new StringBuffer("board");

        ret.append(":gnubg:user:7:0:0:");
        ret.append( -getBar());
        ret.append(":");
        for (int i = 0; i < 24; i++) {
            ret.append(getOtherPlayer().getJag(i + 1) - getJag(24 - i));
            ret.append(":");
        }
        ret.append(getOtherPlayer().getBar());
        ret.append(":-1:");
        int[] dice = getShownDice();
        if (dice == null) {
            ret.append("0:0:0:0:");
        } else if(dice.length==1) {
            String D = "" + dice[0] + ":" + getOtherPlayer().getShownDice()[0] + ":";
            ret.append(D).append(D);
        } else {
            String D = "" + dice[0] + ":" + dice[1] + ":";
            ret.append(D).append(D);
        }
        ret.append(getGame().getDoubleValue()).append(":");
        ret.append(getGame().mayDouble(getOtherPlayer()) ? "1:" : "0:");
        ret.append(getGame().mayDouble(this) ? "1:" : "0:");
        ret.append(doubleProposed ? "1:" : "0:");
        ret.append("1:-1:0:25:");
        ret.append(getOtherPlayer().getOff()).append(":");
        ret.append(getOff()).append(":");
        ret.append("0:0:0:0:0:0");
        ret.append("\n");

        return ret.toString();
    }

    private void sendBoard(boolean doubleProposed) throws IOException {
        writer.write(makeBoard(doubleProposed));
        writer.flush();
    }

    private void sendBoard() throws IOException {
        sendBoard(false);
    }

    public void dispose() {
        try {
            socket.close();
        } catch (IOException ex) {     }
    }
}
