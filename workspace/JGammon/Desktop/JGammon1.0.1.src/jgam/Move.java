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

import java.util.*;

/**
 * A move of on chip on the board.
 *
 * Each move goes from a jag to a jag.
 * Possible values are 0-25.
 * The length is the difference between from() and to()
 *
 * @author Mattias Ulbrich
 */
public interface Move extends PlayerOwnedObject, Comparable {

    /**
     * a moves starts at a jag or at the bar
     * @return integer between 1 and 25.
     */
    public int from();

    /**
     * a move ends at a jag or in the off
     * @return integer between 0 and 24.
     */
    public int to();

    /**
     * length of this move. The condition length()=from()-to() is always true.
     * @return length of this move.
     */
    public int length();

    /**
     * a move may be composed of several basic moves, this methods returns how
     * many basic moves are composed
     * @return number of basic moves in this move
     */
    public int getSingleMovesCount();

    /**
     * a move may be composed of several basic moves, this methods returns these
     * basic moves
     * @return List of Move-Objets
     */
    public List getSingleMoves();
}
