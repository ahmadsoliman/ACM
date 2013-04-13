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

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.*;
import javax.swing.BorderFactory;
import javax.swing.border.Border;
import javax.swing.JTextField;
import javax.swing.JScrollPane;
import javax.swing.JList;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.*;
import javax.swing.text.*;
import java.text.*;
import java.util.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.io.*;

/**
 * A simple chatter window that
 * reacts on special messages send over the connection and sends messages
 * as well.
 * @author Mattias Ulbrich
 */
public class Chatter extends JFrame implements ConnectionListener {
    private BorderLayout borderLayout1 = new BorderLayout();
    private JPanel jPanel2 = new JPanel();
    private Border border1 = BorderFactory.createLineBorder(new Color(199, 199,
            207), 3);
    private Border border2 = BorderFactory.createLineBorder(new Color(199, 199,
            207), 3);
    private JTextField input = new JTextField();
    private JScrollPane jScrollPane1 = new JScrollPane();
    private Border border3 = BorderFactory.createLineBorder(new Color(199, 199,
            207), 3);
    private JLabel jLabel1 = new JLabel();
    private JButton send = new JButton();
    private JTextPane output = new JTextPane();

    private JGammon jgam;

    public Chatter(JGammon jgam) {
        super("Chat");
        this.jgam = jgam;
        try {
            jbInit();
            pack();
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    private void jbInit() throws Exception {
        getContentPane().setLayout(borderLayout1);
        jScrollPane1.setBorder(border3);
        input.setPreferredSize(new Dimension(220, 20));
        jPanel2.setBorder(border1);
        jLabel1.setText("Message:");
        send.setText("Send");
        getRootPane().setDefaultButton(send);
        send.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                send();
            }
        });
        jScrollPane1.setPreferredSize(new Dimension(350, 200));
        output.setEditable(false);
        this.getContentPane().add(jPanel2, java.awt.BorderLayout.SOUTH);
        jPanel2.add(jLabel1);
        jPanel2.add(input);
        jPanel2.add(send);
        this.getContentPane().add(jScrollPane1, java.awt.BorderLayout.CENTER);
        jScrollPane1.getViewport().add(output);
    }

    synchronized public void handleConnectionMessage(ConnectionMessage cm) {

        String msg = cm.getMessage();

        if (cm.getType() != cm.MESSAGE || !msg.startsWith(">MSG ")) {
            return;
        }

        try {
            addMsg(msg.substring(5), true);
        } catch (BadLocationException ex) {
            ex.printStackTrace();
        }

    }

    public void send() {
        Game g = jgam.getGame();

        if (g == null || g.getGameConnection() == null) {
            return;
        }

        if (input.getText().length() == 0) {
            return;
        }

        Writer w = jgam.getGame().getGameConnection().getWriter();
        try {
            w.write(">MSG " + input.getText() + "\n");
            w.flush();
            addMsg(input.getText(), false);
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        input.setText("");

    }

    public void addMsg(String message, boolean remote) throws
            BadLocationException {

        // insert text in the editor

        Game g = jgam.getGame();
        // remotePlayer
        Player player = g.getPlayerWhite().isRemote() == remote ?
                        g.getPlayerWhite() :
                        g.getPlayerBlue();
        SimpleAttributeSet norm = new SimpleAttributeSet();
        if (!player.isWhite()) {
            StyleConstants.setForeground(norm, Color.blue);
        }
        SimpleAttributeSet bold = new SimpleAttributeSet(norm);
        StyleConstants.setBold(bold, true);
        Document d = output.getStyledDocument();

        DateFormat df = DateFormat.getTimeInstance(DateFormat.SHORT);

        d.insertString(d.getLength(), player.getName(), bold);
        d.insertString(d.getLength(), " (" + df.format(new Date()) + "): ",
                       norm);
        d.insertString(d.getLength(), message + "\n", norm);
        Dimension size = output.getSize();
        output.scrollRectToVisible(new Rectangle(0,size.height-1, 1, size.height));
    }
}
