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

/**
 * Dummy player - no longer used
 * @author Mattias Ulbrich
 * @version 1.0
 */
public class NoPlayer extends Player {
    public NoPlayer(String name) {
        super(name);
    }

    /**
     * the other player offers something.
     *
     * @param offer String
     * @return boolean
     * @todo Implement this jgam.Player method
     */
    public boolean acceptOffer(String offer) {
        return false;
    }

    /**
     * a message is passed from the awtthread.
     *
     * @param msg Message-Object
     * @todo Implement this jgam.Player method
     */
    public void handle(Object msg) {
        System.out.println(""+getName()+ " handles "+msg);
    }

    /**
     *
     * @return int[] must have length of two!!
     * @todo Implement this jgam.Player method
     */
    public int[] rollDice(int count) {
        setDice(new int[] {3,3});
        return new int[] {3,3};
    }

    /**
     * get the next Move.
     *
     * @return Move
     * @todo Implement this jgam.Player method
     */
    public Move move() {
        return null;
    }

    /**
     * if this player wants to doube or give up before his/her/move.
     *
     * @return one of ROLL, DOUBLE, GIVE_UP_*
     * @todo Implement this jgam.Player method
     */
    public int nextStep(boolean rollonly) {
        return ROLL;
    }

    public boolean acceptsOffer(int offer) {
        return false;
    }

    public boolean isRemote() {
        return false;
    }

    public void informRoll() {
    }

    public void informMove(SingleMove move) {
    }

    public boolean isWaitingForUIMove() {
        return false;
    }

    public void abort() {
    }

    public void informAccept(boolean answer) throws Exception {
    }

    public void animateMove(Move m) {
    }
}
