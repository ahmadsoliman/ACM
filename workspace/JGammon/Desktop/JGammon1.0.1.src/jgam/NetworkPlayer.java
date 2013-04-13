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
import java.nio.charset.Charset;
import jgam.util.*;

/**
 * This subclass of Player is used for remote players.
 *
 * It communicates with a remote instance over a GameConnection.
 *
 * It listens to UI-Input only for the "undo"-Button in order to inform the
 * counter-part.
 *
 * @author Mattias Ulbrich
 */
public class NetworkPlayer extends Player {
    public NetworkPlayer() {}

    // the underlying connection
    GameConnection gameConnection;
    Writer writer;
    BufferedReader reader;

    public NetworkPlayer(GameConnection gameConnection) {
        this.gameConnection = gameConnection;
        writer = gameConnection.getWriter();
        reader = gameConnection.getGameReader();
    }

    /**
     * tell each other the names of the opponents;
     * this can only be done when a valid copy of Game is available
     */
    public void setGame(Game game) throws IOException, ProtocolException {
        super.setGame(game);
        writer.write("CALLME " + getOtherPlayer().getName() + "\n");
        writer.flush();
        String line = reader.readLine();
        if (!line.startsWith("CALLME ")) {
            throw new ProtocolException("Expected CALLME but received: " + line);
        }
        String name = line.substring(7);
        setName(name);
    }

    /**
     * the other player offers something.
     *
     * send the offer over the socket and wait for the answer;
     *
     * @param offer the offer as index number DOUBLE, GIVE_UP_*
     * @return true if the game is to finish, false if it goes on
     * @todo Implement this jgam.Player method
     */
    public boolean acceptsOffer(int offer) throws IOException,
            ProtocolException {

        switch (offer) {
        case DOUBLE:
            writer.write("DOUBLE\n");
            break;
        case GIVE_UP:
            writer.write("GIVE_UP\n");
            break;
        case GIVE_UP_GAMMON:
            writer.write("GIVE_UP_GAMMON\n");
            break;
        case GIVE_UP_BACKGAMMON:
            writer.write("GIVE_UP_BACKGAMMON\n");
            break;
        default:
            throw new IllegalArgumentException("" + offer + " not allowed");
        }
        writer.flush();

        String line = reader.readLine();
        if (!line.equals("ACCEPT") && !line.equals("DECLINE")) {
            throw new ProtocolException("Expected ACCEPT or DECLINE; got: " +
                                        line);
        }

        return line.equals("ACCEPT");
    }

    /**
     * a message is passed from the awtthread.
     *
     * only react upon "undo". Send a undo request to the opponent
     *
     * @param msg Message-Object
     */
    public void handle(Object msg) {
        if (msg.equals("undo")) {
            try {
                writer.write(">UNDO_REQUEST\n");
                writer.flush();
            } catch (IOException ex) {}
        }
    }

    /**
     * tell thus player the opponent has made a move
     *
     * @param move the move made
     * @todo Implement this jgam.Player method
     * @throws IOException in writer.write
     */
    public void informMove(SingleMove move) throws IOException {
        writer.write("MOVE " + move + "\n");
        writer.flush();
    }

    /**
     * tell this player that the opponent has thrown the dice.
     *
     * @throws IOException in writer.write
     */
    public void informRoll() throws IOException {
        writer.write("ROLL\n");
    }

    /**
     * Yes, I am remote!
     *
     * @return true
     */
    public boolean isRemote() {
        return true;
    }

    /**
     * I dont use UI - so no
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
     * @return Move read from network
     * @throws IOException in reader.readline
     * @throws ProtocolException if unexpected line read
     */
    public Move move() throws IOException, ProtocolException, UndoException {

        String line = reader.readLine();

        if(line.equals("UNDO"))
            throw new UndoException(false);

        if (!line.startsWith("MOVE ")) {
            throw new ProtocolException("Expected MOVE, got: " + line);
        }

        try {
            return new SingleMove(line.substring(5));
        } catch (IllegalArgumentException ex) {
            throw new ProtocolException(ex);
        }
    }

    /**
     * if this player wants to doube or give up before his/her/move.
     *
     * @return one of ROLL, DOUBLE, GIVE_UP_*
     * @throws IOException reader.readline
     * @throws ProtocolException if not DOUBLE, ROLL or GIVE_UP read
     */
    public int nextStep(boolean rollOnly) throws IOException, ProtocolException,
            UndoException {

        String line = reader.readLine();
        int ret;

        if (line.equals("DOUBLE")) {
            ret = DOUBLE;
        } else if (line.equals("GIVE_UP")) {
            ret = GIVE_UP;
        } else if (line.equals("GIVE_UP_GAMMON")) {
            ret = GIVE_UP_GAMMON;
        } else if (line.equals("GIVE_UP_BACKGAMMON")) {
            ret = GIVE_UP_BACKGAMMON;
        } else if (line.equals("ROLL")) {
            ret = ROLL;
        } else if (line.equals("UNDO")) {
            throw new UndoException(false);
        } else {
            throw new ProtocolException(
                    "Expected ROLL, GIVE_UP_*, DOUBLE, UNDO; got: " + line);
        }

        if (rollOnly && ret != ROLL) {
            throw new ProtocolException("Expected ROLL; got: " + line);
        }

        return ret;
    }


    /**
     * tell this player whether the opponent accepted an offer or not
     *
     * @param answer the answer to be told.
     */
    public void informAccept(boolean answer) throws IOException {
        writer.write(answer ? "ACCEPT\n" : "DECLINE\n");
        writer.flush();
    }

    public void animateMove(Move m) {
        BoardAnimation anim = new BoardAnimation(m.player(), m.from(), m.to());
        anim.animate(getGame().getBoard());
    }
}
