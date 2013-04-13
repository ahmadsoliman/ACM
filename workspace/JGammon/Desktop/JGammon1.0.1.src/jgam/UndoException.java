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
 *
 * Used to handle Undo-Requests
 *
 * @author Mattias Ulbrich
 * @version 1.0
 */
public class UndoException extends Exception {

    /**
     * this is true if a message is to be sent to the opponent (if there is
     * a connection
     * this is false if this is the reaction upon such a message and no
     * new message is to be generated;
     */
    private boolean sendMessage = false;

    public UndoException(boolean sendMessage) {
        this.sendMessage = sendMessage;
    }

    public boolean sendMessage() {
        return sendMessage;
    }
}
