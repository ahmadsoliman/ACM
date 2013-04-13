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

package jgam.util;

import java.awt.BorderLayout;

import javax.swing.JFrame;
import java.awt.GridBagLayout;
import javax.swing.JLabel;
import java.awt.*;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.*;
import jgam.*;

/**
 * This class provides a message window which will pop up on top of the other
 * windows without blocking.
 *
 * A work in progress component will be drawn as well.
 *
 * A button (eg for Abort) can be added and checked for pressing.
 *
 * @author Mattias Ulbrich
 * @version 1.0
 */
public class AsynchronousWaitingWindow extends JDialog {
    private GridBagLayout gridBagLayout1 = new GridBagLayout();
    private JLabel msg = new JLabel();
    private JButton jButton1;
    public static final ImageIcon clock = new ImageIcon(AsynchronousWaitingWindow.
                                            class.getResource("clock.gif"));

    private boolean buttonpressed;

    public AsynchronousWaitingWindow(Frame parent, String title, String message,
                                     String button) {
        super(parent, title, true);
        if (button != null) {
            jButton1 = new JButton(button);
        }
        msg = new JLabel(message);
        try {
            jbInit();
            pack();
            JGammon.centerFrame(this);
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    private void jbInit() throws Exception {
        setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
        getContentPane().setLayout(gridBagLayout1);
        if (jButton1 != null) {
            this.getContentPane().add(jButton1,
                                      new GridBagConstraints(0, 1, 2, 1, 0.0,
                    0.0
                    , GridBagConstraints.CENTER, GridBagConstraints.NONE,
                    new Insets(10, 10, 10, 10), 0, 0));
            jButton1.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    buttonpressed = true;
                }
            });
        }
        this.getContentPane().add(new JLabel(clock),
                                  new GridBagConstraints(0, 0, 1, 1, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.BOTH,
                new Insets(10, 10, 10, 10), 0, 0));

        this.getContentPane().add(msg,
                                  new GridBagConstraints(1, 0, 1, 1, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.BOTH,
                new Insets(10, 10, 10, 10), 0, 0));
    }

    public boolean buttonPressed() {
        return buttonpressed;
    }

    public void asyncShow() {
        new Thread(new Runnable() {
            public void run() { show(); }
        }).start();
    }
}
