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

import java.awt.BorderLayout;
import java.awt.Frame;

import javax.swing.JDialog;
import javax.swing.JPanel;
import java.util.*;
import java.util.List;
import javax.swing.JButton;
import java.awt.*;
import javax.swing.JScrollPane;
import javax.swing.JList;

/**
 * A little window that lists the history of moves in the ongoing game.
 *
 * @todo add also recent items that are added while the window is open.
 * @author Mattias Ulbrich
 * @version 1.0
 */
public class HistoryDialog extends JDialog {

    public HistoryDialog(Frame owner, Game game) {
        super(owner, "History", true);
        jList = new JList(makeStrings(game));
        try {
            setDefaultCloseOperation(DISPOSE_ON_CLOSE);
            jbInit();
            setSize(new Dimension(279,340));
            JGammon.centerFrame(this);
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    private static final String space = "                                   ";
    private JScrollPane jScrollPane1 = new JScrollPane();
    private JList jList;

    /**
     * get the moves and make strings of them.
     * @param game Game
     * @return Vector
     */
    private Vector makeStrings(Game game) {
        Vector strings = new Vector();
        // Players
        strings.add(game.getPlayerWhite().getName() + " plays white");
        strings.add(space + game.getPlayerBlue().getName() + " plays blue");

        // Moves
        for (Iterator iter = game.getHistory().iterator(); iter.hasNext(); ) {
            PlayerOwnedObject item = (PlayerOwnedObject) iter.next();
            String s = "";
            if(item.player() != game.getPlayerWhite())
                s = space;
            s += item.toString();
            strings.add(s);
        }
        return strings;
    }


    private void jbInit() throws Exception {
        this.getContentPane().add(jScrollPane1);
        jScrollPane1.getViewport().add(jList);
    }
}
