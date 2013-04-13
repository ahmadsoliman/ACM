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

import java.util.regex.*;
import java.text.ParseException;
import java.util.*;

/**
 * Objects of class Move describe a Move in the Backgammon game.
 *
 * Normally this is the act of moving a chip from one jag to another.
 * For logging reasons this may also br an arbitrary String associated with
 * a user.
 *
 * Normal moves can represented as Text. This is in the form
 *     from/to(*)
 * where from and to are jags. The * is appended if a chip is thrown out
 * of the game.
 *
 * Other notational abbreviations are allowed but not yet implemented.
 *
 * @author Mattias Ulbrich
 */
public class SingleMove implements Move {

    private int from;
    private int to;
    private boolean beat;
    private Player player;

    public SingleMove(Player player, int from, int to, boolean beat) {
        this.player = player;
        this.from = from;
        this.to = to;
        this.beat = beat;
    }

    public SingleMove(Player player, int from, int to) {
        this(player,from,to,false);
    }

    public SingleMove(String desc) throws IllegalArgumentException {
        try {
            Matcher m = Pattern.compile("([0-9]+)/([0-9]+)\\*?").matcher(desc);
            m.matches();
            from = Integer.parseInt(m.group(1));
            to = Integer.parseInt(m.group(2));
        } catch (Exception ex) {
            throw (IllegalArgumentException) (new IllegalArgumentException(desc +
                    " does not describe a move")).initCause(ex);
        }
    }

    public String toString() {
        return "" + from + "/" + to + (beat ? "*" : "");
    }

    public int from() {
        return from;
    }

    public int to() {
        return to;
    }


    public void setPlayer(Player player) {
        this.player = player;
    }

    public void setBeat(boolean b) {
        beat = b;
    }

    /**
     * get the moves of which this move is compound
     */
    public List getSingleMoves() {
        return Collections.singletonList(this);
    }

    public Player player() {
        return player;
    }

    public int length() {
        return from-to;
    }

    public int getSingleMovesCount() {
        return 1;
    }

    // sorting moves according to the number of hops
    public int compareTo(Object o) {
        return getSingleMovesCount() - ((Move)o).getSingleMovesCount();
    }

}
