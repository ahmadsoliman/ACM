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
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import javax.swing.border.Border;
import java.util.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowAdapter;

/**
 * This is the MainWindow-class.
 *
 * On top it has got several Buttons and a message area.
 * In the center lies the board (a JComponent) and in the bottom
 * there is the chat area and the turn and flip buttons.
 *
 * Buttons are partly handled by JGam and partly by this class.
 *
 * @author Mattias Ulbrich
 */
public class JGamFrame extends JFrame {
    private JPanel contentPane;
    private BorderLayout borderLayout1 = new BorderLayout();
    private JPanel jToolBar = new JPanel();
    private JButton buttonNew = new JButton();
    private JButton buttonGiveUp = new JButton();
    private JButton buttonDouble = new JButton();
    private JButton buttonAbout = new JButton();
    private JButton buttonRoll = new JButton();
    private JLabel label = new JLabel();
    private ImageIcon imageDice = new ImageIcon();
    private Board board;
    private Color bgColor = new Color(199,199,207);
    private JGammon jGam;
    private GridBagLayout gridBagLayout1 = new GridBagLayout();
    private JButton buttonTurn = new JButton();
    private Component component3 = Box.createHorizontalStrut(8);
    private JButton buttonFlip = new JButton();
    private JButton buttonHistory = new JButton();
    private JButton buttonUndo = new JButton();
    private Border border1 = BorderFactory.createEtchedBorder(Color.white,
            new Color(139, 139, 144));
    private JLabel messageLine = new JLabel();
    private JPanel bottomPanel = new JPanel();
    private JButton buttonChat = new JButton();

    private ImageIcon turnIcon = new ImageIcon(JGamFrame.class.getResource("/jgam/img/turn.gif"));
    private ImageIcon flipIcon = new ImageIcon(JGamFrame.class.getResource("/jgam/img/flip.gif"));
    private ImageIcon newMsgIcon = new ImageIcon(JGamFrame.class.getResource("/jgam/img/newmsg.gif"));
    private ImageIcon newMsgDisabledIcon = new ImageIcon(JGamFrame.class.getResource("/jgam/img/newMsgDisabled.gif"));
    private ResourceBundle msg = ResourceBundle.getBundle("jgam.msg.JGamFrame");
    private JButton buttonHelp = new JButton();
    private JButton buttonSave = new JButton();
    private GridBagLayout gridBagLayout2 = new GridBagLayout();
    private JLabel newMsgLabel = new JLabel();

    public JGamFrame(JGammon jgam) {
        jGam = jgam;
        board = new Board(jgam);
        try {
            setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
            setResizable(false);
            jbInit();
            disableButtons();
            pack();
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    /**
     * Component initialization.
     *
     * @throws java.lang.Exception
     */
    private void jbInit() throws Exception {
        contentPane = (JPanel) getContentPane();
        imageDice = new ImageIcon(jgam.JGamFrame.class.getResource("img/dice.gif"));
        contentPane.setLayout(borderLayout1);
        setTitle("JGammon");
        this.addWindowListener(new JGamFrame_this_windowAdapter(this));
        buttonNew.setActionCommand("newgame");
        buttonNew.setText(msg.getString("newgame"));
        buttonGiveUp.setActionCommand("giveup");
        buttonGiveUp.setText(msg.getString("giveup"));
        buttonDouble.setActionCommand("double");
        buttonDouble.setText(msg.getString("double"));
        buttonRoll.setActionCommand("roll");
        buttonRoll.setIcon(imageDice);
        buttonRoll.setText(msg.getString("roll"));
        buttonAbout.setText(msg.getString("about"));
        buttonAbout.addActionListener(new JGamFrame_buttonAbout_actionAdapter(this));
        buttonNew.addActionListener(jGam);
        buttonDouble.addActionListener(jGam);
        buttonGiveUp.addActionListener(jGam);
        buttonRoll.addActionListener(jGam);
        buttonUndo.addActionListener(jGam);
        label.setHorizontalAlignment(SwingConstants.CENTER);
        label.setText(msg.getString("welcome") + " JGammon " + JGammon.VERSION);
        jToolBar.setBackground(bgColor);
        jToolBar.setLayout(gridBagLayout1);
        buttonTurn.setPreferredSize(new Dimension(28, 28));
        buttonTurn.setToolTipText(msg.getString("turnboard"));
        buttonTurn.setIcon(turnIcon);
        buttonTurn.addActionListener(new JGamFrame_buttonTurn_actionAdapter(this));
        buttonFlip.setPreferredSize(new Dimension(28,28));
        buttonFlip.setToolTipText(msg.getString("flipboard"));
        buttonFlip.setIcon(flipIcon);
        buttonFlip.addActionListener(new JGamFrame_buttonFlip_actionAdapter(this));
        buttonHistory.setText(msg.getString("history"));
        buttonHistory.addActionListener(new
                                        JGamFrame_buttonHistory_actionAdapter(this));
        buttonUndo.setEnabled(true);
        buttonUndo.setActionCommand("undo");
        buttonUndo.setText(msg.getString("undo"));
        messageLine.setBackground(Color.pink);
        messageLine.setText("messages go here ...");
        bottomPanel.setLayout(gridBagLayout2);
        buttonChat.setPreferredSize(new Dimension(65, 18));
        buttonChat.setActionCommand("chat");
        buttonChat.addActionListener(jGam);
        buttonChat.setText(msg.getString("chat"));
        buttonHelp.setEnabled(true);
        buttonHelp.addActionListener(jGam);
        buttonHelp.setActionCommand("help");
        buttonHelp.setText(msg.getString("help"));
        buttonSave.setEnabled(true);
        buttonSave.setActionCommand("saveboard");
        buttonSave.setText(msg.getString("saveboard"));
        buttonSave.addActionListener(jGam);
        newMsgLabel.setEnabled(false);
        newMsgLabel.setDisabledIcon(newMsgDisabledIcon);
        newMsgLabel.setIcon(newMsgIcon);
        newMsgLabel.setText("");
        newMsgLabel.addMouseListener(new JGamFrame_newMsgLabel_mouseAdapter(this));
        contentPane.add(board, java.awt.BorderLayout.CENTER);
        contentPane.add(bottomPanel, java.awt.BorderLayout.SOUTH);
        contentPane.add(jToolBar, java.awt.BorderLayout.NORTH);
        jToolBar.add(component3, new GridBagConstraints(3, 1, 1, 2, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.NONE,
                new Insets(0, 0, 0, 0), 0, 0));
        jToolBar.add(label, new GridBagConstraints(3, 0, 1, 2, 1.0, 1.0
                , GridBagConstraints.WEST, GridBagConstraints.BOTH,
                new Insets(0, 0, 0, 0), 0, 0));
        jToolBar.add(buttonGiveUp, new GridBagConstraints(4, 0, 1, 1, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.BOTH,
                new Insets(0, 0, 0, 0), 0, 0));
        jToolBar.add(buttonDouble, new GridBagConstraints(4, 1, 1, 1, 0.0, 0.0
                , GridBagConstraints.EAST, GridBagConstraints.BOTH,
                new Insets(0, 0, 0, 0), 0, 0));
        jToolBar.add(buttonRoll, new GridBagConstraints(5, 0, 1, 2, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.BOTH,
                new Insets(0, 0, 0, 0), 0, 0));
        jToolBar.add(buttonHistory, new GridBagConstraints(2, 0, 1, 1, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.BOTH,
                new Insets(0, 0, 0, 0), 0, 0));
        jToolBar.add(buttonUndo, new GridBagConstraints(2, 1, 1, 1, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.BOTH,
                new Insets(0, 0, 0, 0), 0, 0));
        jToolBar.add(buttonNew, new GridBagConstraints(1, 0, 1, 1, 0.0, 0.0
                , GridBagConstraints.WEST, GridBagConstraints.BOTH,
                new Insets(0, 0, 0, 0), 0, 0));
        jToolBar.add(buttonHelp, new GridBagConstraints(0, 1, 1, 1, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.BOTH,
                new Insets(0, 0, 0, 0), 0, 0));
        jToolBar.add(buttonAbout, new GridBagConstraints(0, 0, 1, 1, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.BOTH,
                new Insets(0, 0, 0, 0), 0, 0));
        jToolBar.add(buttonSave, new GridBagConstraints(1, 1, 1, 1, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.BOTH,
                new Insets(0, 0, 0, 0), 0, 0));
        bottomPanel.add(messageLine,
                        new GridBagConstraints(2, 0, 1, 1, 1.0, 0.0
                                               , GridBagConstraints.WEST,
                                               GridBagConstraints.NONE,
                                               new Insets(0, 5, 0, 0), 0, 0));
        bottomPanel.add(buttonChat, new GridBagConstraints(0, 0, 1, 1, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.NONE,
                new Insets(0, 0, 0, 0), 0, 10));
        bottomPanel.add(buttonFlip, new GridBagConstraints(3, 0, 1, 1, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.NONE,
                new Insets(0, 0, 0, 0), 0, 0));
        bottomPanel.add(buttonTurn, new GridBagConstraints(4, 0, 1, 1, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.NONE,
                new Insets(0, 0, 0, 0), 0, 0));
        bottomPanel.add(newMsgLabel,
                        new GridBagConstraints(1, 0, 1, 1, 0.0, 0.0
                                               , GridBagConstraints.CENTER,
                                               GridBagConstraints.NONE,
                                               new Insets(0, 3, 0, 3), 0, 0));
    }

    public void about() {
        new JGamFrame_AboutBox(this).show();
    }

    public void showHistory() {
        if(jGam.getGame() != null)
            new HistoryDialog(this, jGam.getGame()).show();
    }

    public void turnBoard() {
        board.toggleTurn();
    }

    public void setLabel(String string) {
        label.setText(string);
    }

    public void setIcon(ImageIcon icon) {
        label.setIcon(icon);
    }


    public void flipBoard() {
        board.toggleLeftRight();
    }

    public Board getBoard() {
        return board;
    }

    public void enableButtons(boolean rollOnly) {
        if(!rollOnly) {
            buttonDouble.setEnabled(true);
            buttonGiveUp.setEnabled(true);
        }
        buttonRoll.setEnabled(true);
    }

    public void disableButtons() {
        buttonDouble.setEnabled(false);
           buttonGiveUp.setEnabled(false);
       buttonRoll.setEnabled(false);

    }

    public void setMessage(String string) {
        messageLine.setText(string);
        newMsgLabel.setEnabled(true);
    }

    public void newMsgLabel_mouseClicked(MouseEvent e) {
        newMsgLabel.setEnabled(false);
    }

    public void closed() {
        jGam.handle("close");
    }

}


class JGamFrame_this_windowAdapter extends WindowAdapter {
    private JGamFrame adaptee;
    JGamFrame_this_windowAdapter(JGamFrame adaptee) {
        this.adaptee = adaptee;
    }

    public void windowClosing(WindowEvent e) {
        adaptee.closed();
    }
}


class JGamFrame_newMsgLabel_mouseAdapter extends MouseAdapter {
    private JGamFrame adaptee;
    JGamFrame_newMsgLabel_mouseAdapter(JGamFrame adaptee) {
        this.adaptee = adaptee;
    }

    public void mouseClicked(MouseEvent e) {
        adaptee.newMsgLabel_mouseClicked(e);
    }
}


class JGamFrame_buttonHistory_actionAdapter implements ActionListener {
    private JGamFrame adaptee;
    JGamFrame_buttonHistory_actionAdapter(JGamFrame adaptee) {
        this.adaptee = adaptee;
    }

    public void actionPerformed(ActionEvent e) {
        adaptee.showHistory();
    }
}


class JGamFrame_buttonFlip_actionAdapter implements ActionListener {
    private JGamFrame adaptee;
    JGamFrame_buttonFlip_actionAdapter(JGamFrame adaptee) {
        this.adaptee = adaptee;
    }

    public void actionPerformed(ActionEvent e) {
        adaptee.flipBoard();
    }
}


class JGamFrame_buttonTurn_actionAdapter implements ActionListener {
    private JGamFrame adaptee;
    JGamFrame_buttonTurn_actionAdapter(JGamFrame adaptee) {
        this.adaptee = adaptee;
    }

    public void actionPerformed(ActionEvent e) {
        adaptee.turnBoard();
    }
}


class JGamFrame_buttonAbout_actionAdapter implements ActionListener {
    private JGamFrame adaptee;
    JGamFrame_buttonAbout_actionAdapter(JGamFrame adaptee) {
        this.adaptee = adaptee;
    }

    public void actionPerformed(ActionEvent e) {
        adaptee.about();
    }
}
