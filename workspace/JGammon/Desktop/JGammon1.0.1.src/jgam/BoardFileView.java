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

import java.awt.*;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.io.File;

import javax.swing.*;
import javax.swing.border.*;


/**
 * Show additional information about .board-Files in the load/save-dialogs.
 *
 * @author Mattias Ulbrich
 */
public class BoardFileView extends JPanel implements PropertyChangeListener {
    public BoardFileView() {
        try {
            jbInit();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    public BoardFileView(JFileChooser fc) {
        fc.addPropertyChangeListener(this);
        try {
            jbInit();
        } catch (Exception ex) {
            ex.printStackTrace();
        }

    }

    File file = null;
    private JLabel jLabel1 = new JLabel();
    private GridBagLayout gridBagLayout1 = new GridBagLayout();
    private JLabel jLabel2 = new JLabel();
    private JTextPane commentArea = new JTextPane();
    private Border border5 = BorderFactory.createBevelBorder(BevelBorder.
            LOWERED, Color.white, Color.white, new Color(109, 109, 110),
            new Color(156, 156, 158));
    private JLabel dateArea = new JLabel();
    private Border border1 = BorderFactory.createEtchedBorder(EtchedBorder.
            RAISED, Color.white, new Color(156, 156, 158));
    private Border border2 = new TitledBorder(border1, "File Information:");
    private Border border3 = BorderFactory.createCompoundBorder(border2,
            BorderFactory.createEmptyBorder(4, 4, 4, 4));

    public void propertyChange(PropertyChangeEvent e) {
        boolean update = false;
        String prop = e.getPropertyName();

        // If the directory changed, don't show an image.
        if (JFileChooser.DIRECTORY_CHANGED_PROPERTY.equals(prop)) {
            file = null;
            update = true;
        } else
        // If a file became selected, find out which one.
        if (JFileChooser.SELECTED_FILE_CHANGED_PROPERTY.equals(prop)) {
            file = (File) e.getNewValue();
            update = true;
        }

        // Update the preview accordingly.
        if (update) {
            BoardSnapshot snap = null;
            commentArea.setText("");
            dateArea.setText("not yet");
            try {
                snap = new BoardSnapshot(file);
                String comment = snap.getComment();
                commentArea.setText(comment);
                /**@todo localised date
                 dateArea.setText(new Date(file.lastModified()).toString());*/
            } catch (Exception ex) {}
        }
    }


    private void jbInit() throws Exception {
        border3 = BorderFactory.createCompoundBorder(border2,
                BorderFactory.createEmptyBorder(4, 4, 4, 4));
        jLabel1.setText("Comment:");
        this.setLayout(gridBagLayout1);
        jLabel2.setText("Date:");
        commentArea.setBackground(UIManager.getColor("Label.background"));
        commentArea.setBorder(null);
        commentArea.setEditable(false);
        this.setBorder(border3);
        this.setPreferredSize(new Dimension(200, 100));
        this.add(jLabel2, new GridBagConstraints(0, 2, 1, 1, 0.0, 0.0
                                                 , GridBagConstraints.EAST,
                                                 GridBagConstraints.NONE,
                                                 new Insets(0, 0, 0, 0), 0, 0));
        this.add(jLabel1, new GridBagConstraints(0, 0, 2, 1, 0.0, 0.0
                                                 , GridBagConstraints.WEST,
                                                 GridBagConstraints.NONE,
                                                 new Insets(0, 0, 0, 0), 0, 0));
        this.add(dateArea, new GridBagConstraints(1, 2, 1, 1, 0.0, 0.0
                                                  , GridBagConstraints.WEST,
                                                  GridBagConstraints.BOTH,
                                                  new Insets(0, 0, 0, 0), 0, 0));
        this.add(commentArea, new GridBagConstraints(1, 1, 1, 1, 1.0, 0.5
                , GridBagConstraints.CENTER, GridBagConstraints.BOTH,
                new Insets(0, 0, 0, 0), 0, 0));
    }
}
