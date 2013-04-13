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

/**
*
 * Message handled by a ConnectionListener.
 *
 * it has got a type which is either MESSAGE or CLOSED.
 *
 * MESSAGE if a message has arrived
 * CLOSED if the connection has recently been closed.
 *
 * @author Mattias Ulbrich
 */
public class ConnectionMessage {

    public static final int MESSAGE = 0;
    public static final int CLOSED = 1;

    int type;
    String message;
    IOException exception;

    public ConnectionMessage(String string) {
        message = string;
        type = MESSAGE;
    }

    public ConnectionMessage(int index) {
        type = index;
    }

    public String getMessage() {
        return message;
    }

    public int getType() {
        return type;
    }
}
