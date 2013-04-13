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
 * An object that has a string representation and belongs to a player
 * @author Mattias Ulbrich
 */
public interface PlayerOwnedObject {

    /**
     * get the owner of this object
     *
     * @return Player to which this belongs
     */
    public Player player();

    /**
     * set the owner of this.
     * OPtional operation
     * @param player the owner to be set
     */
    public void setPlayer(Player player);

}
