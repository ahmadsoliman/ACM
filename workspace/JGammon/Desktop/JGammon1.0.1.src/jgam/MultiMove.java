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

import java.util.Collections;
import java.util.List;
import java.util.*;

/**
 * A MultiMove is a move that is composed of two Move-Objects m1 and m2.
 *
 * But m1.to = m2.from must always be true!
 *
 * Both m1 or m2 may be MultiMove-Objects themselves.
 *
 * @author Mattias Ulbrich
 */
public class MultiMove implements Move {

    private Move move1, move2;

    public MultiMove(Move m1, Move m2) {
        if (m1.to() != m2.from()) {
            throw new IllegalArgumentException("m2 does not continue m2: " + m1 +
                                               " " + m2);
        }
        //assert m1.player()==m2.player();
        move1 = m1;
        move2 = m2;
    }

    public void setPlayer(Player player) {
        move1.setPlayer(player);
        move2.setPlayer(player);
    }

    public Move move1() {
        return move1;
    }

    public Move move2() {
        return move2;
    }

    /**
     * get the SingleMoves of which this move is compound
     */
    public List getSingleMoves() {
        List ret = new LinkedList(move1.getSingleMoves());
        ret.addAll(move2.getSingleMoves());
        return ret;
    }

    public int from() {
        return move1.from();
    }

    public int to() {
        return move2.to();
    }

    public Player player() {
        return move1.player();
    }

    public String toString() {
        String ret = ""+move1.from();
        SingleMove item = null;
        for (Iterator iter = getSingleMoves().iterator(); iter.hasNext(); ) {
            item = (SingleMove) iter.next();
            ret += "/" + item.to();
        }
        /** @todo append "*" if beat */
        return ret;
    }

    public int length() {
        return from()-to();
    }

    public int getSingleMovesCount() {
        return move1.getSingleMovesCount() + move2.getSingleMovesCount();
    }

    // sorting moves according to the number of hops
    public int compareTo(Object o) {
        return getSingleMovesCount() - ((Move)o).getSingleMovesCount();
    }

}
