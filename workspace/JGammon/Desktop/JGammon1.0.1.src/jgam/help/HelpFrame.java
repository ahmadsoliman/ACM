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
package jgam.help;

import java.awt.BorderLayout;

import javax.swing.JFrame;
import javax.swing.JSplitPane;
import java.awt.*;
import javax.swing.JTabbedPane;
import javax.swing.JEditorPane;
import javax.swing.JLabel;
import javax.swing.JCheckBox;
import javax.swing.JPanel;
import javax.swing.JTree;
import javax.swing.JTextField;
import javax.swing.JScrollPane;
import javax.swing.JList;
import javax.swing.JToolBar;
import javax.swing.JButton;
import java.net.*;
import java.io.IOException;
import javax.swing.event.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * A HelpWindow with a content + index frame on the left and a content window on
 * the right
 *
 * @author Mattias Ulbrich
 */
public class HelpFrame extends JFrame implements HyperlinkListener {

    private BorderLayout borderLayout1 = new BorderLayout();
    private JSplitPane jSplitPane1 = new JSplitPane();
    private JTabbedPane jTabbedPane1 = new JTabbedPane();
    private JPanel jPanel1 = new JPanel();
    private JPanel jPanel2 = new JPanel();
    private JTree topicTree;
    private BorderLayout borderLayout2 = new BorderLayout();
    private JTextField search = new JTextField();
    private BorderLayout borderLayout3 = new BorderLayout();
    private JScrollPane jScrollPane1 = new JScrollPane();
    private JList jList1 = new JList();
    private JScrollPane jScrollPane2 = new JScrollPane();
    private BorderLayout borderLayout4 = new BorderLayout();
    private JToolBar jToolBar1 = new JToolBar();
    private JButton buttonBack = new JButton();
    private JButton buttonClose = new JButton();
    private JScrollPane jScrollPane3 = new JScrollPane();
    private JEditorPane browser = new JEditorPane();

    private static HelpFrame theOneAndOnly;
    private JButton buttonHome = new JButton();

    private HelpFrame() {
        try {
            jbInit();
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    private void jbInit() throws Exception {
        setTitle("JGammon Help");
        topicTree = new ContentTree(this);
        browser.addHyperlinkListener(this);
        getContentPane().setLayout(borderLayout1);
        jSplitPane1.setOneTouchExpandable(true);
        jPanel1.setLayout(borderLayout2);
        jPanel2.setLayout(borderLayout3);
        buttonBack.setText("Back");
        buttonClose.setText("Close");
        buttonClose.addActionListener(new HelpFrame_buttonClose_actionAdapter(this));
        browser.setEditable(false);
        jScrollPane3.setPreferredSize(new Dimension(200, 200));
        buttonHome.setText("Home");
        buttonHome.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                home();
            }
        });
        jPanel2.setEnabled(false);
        this.getContentPane().add(jSplitPane1, java.awt.BorderLayout.CENTER);
        jScrollPane2.getViewport().add(topicTree);
        jScrollPane1.getViewport().add(jList1);
        jPanel2.add(jScrollPane1, java.awt.BorderLayout.CENTER);
        jPanel2.add(search, java.awt.BorderLayout.NORTH);
        jSplitPane1.add(jScrollPane3, JSplitPane.RIGHT);
        jScrollPane3.getViewport().add(browser);
        jPanel1.add(jScrollPane2, java.awt.BorderLayout.CENTER);
        this.getContentPane().add(jToolBar1, java.awt.BorderLayout.NORTH);
        jToolBar1.add(buttonClose);
        jToolBar1.add(buttonBack);
        jToolBar1.add(buttonHome);
        jSplitPane1.add(jTabbedPane1, JSplitPane.LEFT);
        jTabbedPane1.add(jPanel1, "Table of content");
        jTabbedPane1.add(jPanel2, "Index");
    }

    public static void main(String args[]) {
        HelpFrame f = HelpFrame.theFrame();
        try {
            f.showPage("newGameDialog");
        } catch (IOException ex) {
        }
        f.pack();
        f.setVisible(true);
    }


    public void hyperlinkUpdate(HyperlinkEvent event) {
        if (event.getEventType() == HyperlinkEvent.EventType.ACTIVATED) {
            try {
                browser.setPage(event.getURL());
            } catch (IOException ioe) {
                ioe.printStackTrace();
            }
        }
    }

    public void showPage(String page) throws IOException {
        URL url = getClass().getResource(page);
        browser.setPage(url);
    }

    public static HelpFrame theFrame() {
        if(theOneAndOnly == null)
            theOneAndOnly = new HelpFrame();
        return theOneAndOnly;
    }

    public void close() {
        setVisible(false);
    }

    /**
     * select the top item in the tree. the selection listener changes the
     * address.
     */
    public void home() {
        topicTree.setSelectionInterval(0,0);
    }

}


class HelpFrame_buttonClose_actionAdapter implements ActionListener {
    private HelpFrame adaptee;
    HelpFrame_buttonClose_actionAdapter(HelpFrame adaptee) {
        this.adaptee = adaptee;
    }

    public void actionPerformed(ActionEvent e) {
        adaptee.close();
    }
}

