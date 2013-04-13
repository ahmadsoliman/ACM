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
import java.net.InetAddress;
import java.util.ResourceBundle;

import java.io.*;
import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.filechooser.FileFilter;
import java.util.*;


/**
 * This dialog is showed before starting a new game.
 *
 * Some pictures are taken from: iconarchive.com
 * @author Mattias Ulbrich
 */
public class NewGameDialog extends JDialog {PropertyResourceBundle r = null;
    private JPanel panel1 = new JPanel();
    private ResourceBundle msg = ResourceBundle.getBundle(
            "jgam.msg.NewGameDialog");
    private JRadioButton RBlocal = new JRadioButton();
    private GridBagLayout gridBagLayout1 = new GridBagLayout();
    private JRadioButton RBnetwork = new JRadioButton();
    private JRadioButton RBserverWhite = new JRadioButton();
    private JRadioButton RBclient = new JRadioButton();
    private JRadioButton RBgnubg = new JRadioButton();
    private Component component1 = Box.createHorizontalStrut(8);
    private JLabel jLabel1 = new JLabel();
    private JTextField name1 = new JTextField();
    private JLabel jLabel2 = new JLabel();
    private JTextField name2 = new JTextField();
    private JLabel jLabel4 = new JLabel();
    private JLabel jLabel5 = new JLabel();
    private JTextField server = new JTextField();
    private JTextField port = new JTextField();
    private JRadioButton RBserverBlue = new JRadioButton();
    private JButton cancel = new JButton();
    private JButton OK = new JButton();
    private JLabel jLabel6 = new JLabel();
    private JLabel jLabel7 = new JLabel();
    private JLabel jLabel8 = new JLabel();
    private JLabel jLabel9 = new JLabel();
    private ButtonGroup topGroup = new ButtonGroup();
    private ButtonGroup remoteGroup = new ButtonGroup();
    private JLabel jLabel3 = new JLabel();
    private JTextField locName = new JTextField();

    private ImageIcon local = new ImageIcon(NewGameDialog.class.getResource(
            "/jgam/img/local.gif"));
    private ImageIcon clientIcon = new ImageIcon(NewGameDialog.class.
                                                 getResource(
            "/jgam/img/connect.gif"));
    private ImageIcon serverIcon = new ImageIcon(NewGameDialog.class.
                                                 getResource(
            "/jgam/img/server.gif"));
    private ImageIcon openIcon = new ImageIcon(NewGameDialog.class.getResource(
            "/jgam/img/open.gif"));

    private boolean okPressed = false;
    private JGammon jgam;
    private JToggleButton loadButton = new JToggleButton();
    private JLabel fileNameLabel = new JLabel();
    private File boardFile = null;


    public NewGameDialog(JGammon jgam) {
        super(jgam.getFrame(), true);
        this.jgam = jgam;
        setTitle(msg.getString("newgame"));
        try {
            setDefaultCloseOperation(DISPOSE_ON_CLOSE);
            jbInit();
            getRootPane().setDefaultButton(OK);
            pack();
            JGammon.centerFrame(this);
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    public NewGameDialog() {
        try {
            setDefaultCloseOperation(DISPOSE_ON_CLOSE);
            jbInit();
            pack();

        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    private void jbInit() throws Exception {
        ChangeListener changeListener = new ChangeListener() {
            public void stateChanged(ChangeEvent e) {
                enableDisable();
            }
        };

        panel1.setLayout(gridBagLayout1);
        RBlocal.setSelected(true);
        RBlocal.setText(msg.getString("local"));
        RBlocal.addChangeListener(changeListener);
        RBnetwork.addChangeListener(changeListener);
        RBclient.addChangeListener(changeListener);
        RBserverBlue.addChangeListener(changeListener);
        RBserverWhite.addChangeListener(changeListener);
        RBgnubg.addChangeListener(changeListener);
        RBnetwork.setToolTipText("");
        RBnetwork.setText(msg.getString("network"));
        RBserverWhite.setText(msg.getString("whiteServer"));
        RBclient.setSelected(true);
        RBclient.setText(msg.getString("connect"));
        RBgnubg.setText(msg.getString("gnubg"));
        jLabel1.setText(msg.getString("whitename"));
        name1.setPreferredSize(new Dimension(110, 20));
        name1.setText("Anastasia");
        jLabel2.setText(msg.getString("bluename"));
        name2.setPreferredSize(new Dimension(110, 20));
        name2.setText("Basil");
        jLabel4.setText(msg.getString("server"));
        jLabel5.setText(msg.getString("port"));
        port.setPreferredSize(new Dimension(110, 20));
        port.setText("1777");
        RBserverBlue.setText(msg.getString("blueServer"));
        cancel.setText(msg.getString("cancel"));
        cancel.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                setVisible(false);
            }
        });
        OK.setText(msg.getString("OK"));
        OK.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                okPressed = true;
                setVisible(false);
            }
        });
        server.setPreferredSize(new Dimension(110, 20));
        jLabel6.setIcon(local);
        jLabel7.setIcon(serverIcon);
        jLabel8.setIcon(clientIcon);
        jLabel3.setText(msg.getString("localName"));
        locName.setPreferredSize(new Dimension(110, 20));
        locName.setText(InetAddress.getLocalHost().getCanonicalHostName());
        jLabel9.setIcon(openIcon);
        loadButton.setEnabled(false);
        loadButton.setText(msg.getString("loadBoard"));
        loadButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                loadButtonChanged();
            }
        });
        fileNameLabel.setMaximumSize(new Dimension(150, 15));
        fileNameLabel.setPreferredSize(new Dimension(150, 15));
        RBlocal.setEnabled(true);
        RBclient.setEnabled(true);
        topGroup.add(RBlocal);
        topGroup.add(RBnetwork);
        remoteGroup.add(RBclient);
        remoteGroup.add(RBserverBlue);
        remoteGroup.add(RBserverWhite);
        remoteGroup.add(RBgnubg);
        panel1.add(RBserverWhite, new GridBagConstraints(2, 4, 3, 1, 0.0, 0.0
                , GridBagConstraints.WEST, GridBagConstraints.BOTH,
                new Insets(0, 0, 0, 0), 0, 0));
        panel1.add(RBlocal, new GridBagConstraints(1, 0, 4, 1, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.BOTH,
                new Insets(20, 0, 0, 0), 2, 0));
        panel1.add(RBserverBlue, new GridBagConstraints(2, 5, 3, 1, 0.0, 0.0
                , GridBagConstraints.WEST, GridBagConstraints.NONE,
                new Insets(0, 0, 0, 0), 0, 0));
        panel1.add(component1, new GridBagConstraints(1, 4, 1, 1, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.BOTH,
                new Insets(0, 0, 0, 0), 20, 0));
        panel1.add(RBgnubg, new GridBagConstraints(2, 7, 3, 1, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.BOTH,
                new Insets(0, 0, 0, 0), 0, 0));
        panel1.add(RBclient, new GridBagConstraints(2, 6, 3, 1, 0.0, 0.0
                , GridBagConstraints.WEST, GridBagConstraints.BOTH,
                new Insets(0, 0, 0, 0), 0, 0));
        panel1.add(jLabel6, new GridBagConstraints(0, 0, 1, 3, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.NONE,
                new Insets(20, 20, 20, 20), 0, 0));
        panel1.add(name1, new GridBagConstraints(4, 1, 1, 1, 0.0, 0.0
                                                 , GridBagConstraints.CENTER,
                                                 GridBagConstraints.NONE,
                                                 new Insets(0, 0, 0, 20), 0, 0));
        panel1.add(name2, new GridBagConstraints(4, 2, 1, 1, 0.0, 0.0
                                                 , GridBagConstraints.CENTER,
                                                 GridBagConstraints.NONE,
                                                 new Insets(0, 0, 0, 20), 0, 0));
        panel1.add(server, new GridBagConstraints(4, 8, 1, 1, 0.0, 0.0
                                                  , GridBagConstraints.CENTER,
                                                  GridBagConstraints.NONE,
                                                  new Insets(0, 0, 0, 20), 0, 0));
        panel1.add(port, new GridBagConstraints(4, 9, 1, 1, 0.0, 0.0
                                                , GridBagConstraints.CENTER,
                                                GridBagConstraints.NONE,
                                                new Insets(0, 0, 0, 20), 0, 0));
        panel1.add(jLabel7, new GridBagConstraints(0, 4, 1, 2, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.NONE,
                new Insets(0, 0, 0, 0), 0, 0));
        panel1.add(jLabel8, new GridBagConstraints(0, 6, 1, 2, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.NONE,
                new Insets(0, 0, 0, 0), 0, 0));
        panel1.add(RBnetwork, new GridBagConstraints(1, 3, 4, 1, 0.0, 0.0
                , GridBagConstraints.WEST, GridBagConstraints.NONE,
                new Insets(20, 0, 0, 0), 0, 0));
        panel1.add(cancel, new GridBagConstraints(1, 13, 3, 1, 0.0, 0.0
                                                  , GridBagConstraints.WEST,
                                                  GridBagConstraints.NONE,
                                                  new Insets(0, 0, 19, 0), 0, 0));
        panel1.add(OK, new GridBagConstraints(4, 13, 1, 1, 0.0, 0.0
                                              , GridBagConstraints.EAST,
                                              GridBagConstraints.NONE,
                                              new Insets(0, 0, 20, 20), 0, 0));
        panel1.add(locName, new GridBagConstraints(4, 10, 1, 1, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.NONE,
                new Insets(0, 0, 0, 20), 0, 0));
        panel1.add(jLabel1, new GridBagConstraints(2, 1, 2, 1, 0.0, 0.0
                , GridBagConstraints.EAST, GridBagConstraints.NONE,
                new Insets(0, 0, 0, 7), 0, 0));
        panel1.add(jLabel2, new GridBagConstraints(2, 2, 2, 1, 0.0, 0.0
                , GridBagConstraints.EAST, GridBagConstraints.NONE,
                new Insets(0, 0, 0, 7), 0, 0));
        panel1.add(jLabel4, new GridBagConstraints(2, 8, 2, 1, 0.0, 0.0
                , GridBagConstraints.EAST, GridBagConstraints.NONE,
                new Insets(0, 0, 0, 7), 0, 0));
        panel1.add(jLabel5, new GridBagConstraints(2, 9, 2, 1, 0.0, 0.0
                , GridBagConstraints.EAST, GridBagConstraints.NONE,
                new Insets(0, 0, 0, 7), 0, 0));
        panel1.add(jLabel9, new GridBagConstraints(0, 11, 1, 2, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.BOTH,
                new Insets(0, 20, 0, 0), 0, 0));
        panel1.add(jLabel3, new GridBagConstraints(2, 10, 2, 1, 0.0, 0.0
                , GridBagConstraints.EAST, GridBagConstraints.NONE,
                new Insets(0, 0, 0, 7), 0, 0));
        panel1.add(loadButton, new GridBagConstraints(1, 11, 2, 1, 0.0, 0.0
                , GridBagConstraints.WEST, GridBagConstraints.NONE,
                new Insets(10, 0, 10, 0), 0, 0));
        panel1.add(fileNameLabel, new GridBagConstraints(3, 11, 1, 1, 0.0, 0.0
                , GridBagConstraints.WEST, GridBagConstraints.NONE,
                new Insets(10, 10, 10, 0), 0, 20));
        this.getContentPane().add(panel1, java.awt.BorderLayout.CENTER);

 }


    public Game showAndEval() {

        GameConnection gc = null;

        while (true) {
            okPressed = false;
            setVisible(true);

            // waiting for answer. ...
            if (!okPressed) {
                return null;
            }

            try {
                gc = null;
                if (RBlocal.isSelected()) {
                    if (name1.getText().length() == 0) {
                        JOptionPane.showMessageDialog(this, msg.getString("errorName1"),
                                msg.getString("error"),
                                JOptionPane.ERROR_MESSAGE);
                    } else
                    if (name2.getText().length() == 0) {
                        JOptionPane.showMessageDialog(this, msg.getString("errorName2"),
                                msg.getString("error"),
                                JOptionPane.ERROR_MESSAGE);
                    } else {
                        Player player1 = new LocalPlayer(name1.getText());
                        Player player2 = new LocalPlayer(name2.getText());
                        Game game = new Game(null, player1, player2, jgam);
                        if(boardFile != null) {
                            game.setSnapshot(new BoardSnapshot(boardFile));
                        }
                        return game;
                    }
                } else { // network game
                    if (locName.getText().length() == 0) {
                        JOptionPane.showMessageDialog(this,
                                msg.getString("errorLocName"),
                                msg.getString("error"),
                                JOptionPane.ERROR_MESSAGE);
                    } else if (RBgnubg.isSelected()) {
                       Player player1 = new LocalPlayer(locName.getText());
                       // Player player1 = new GnubgPlayer("localhost", 1779);
                       Player player2 = new GnubgPlayer(server.getText(),
                               Integer.parseInt(port.getText()));
                        Game game = new Game(null, player1, player2, jgam);
                        if(boardFile != null) {
                           game.setSnapshot(new BoardSnapshot(boardFile));
                       }
                       return game;
                    } else if (RBclient.isSelected()) {
                        gc = new GameConnection(server.getText(),
                                                Integer.parseInt(port.getText()));
                        Player locPlayer = new LocalPlayer(locName.getText());
                        Player remPlayer = new NetworkPlayer(gc);
                        Game game;
                        if (gc.receiveColorIsWhite()) {
                            game = new Game(gc, locPlayer, remPlayer, jgam);
                        } else {
                            game = new Game(gc, remPlayer, locPlayer, jgam);
                        }
                        BoardSnapshot snapshot = BoardSnapshot.readSnapshotLine(gc.getGameReader());
                        game.setSnapshot(snapshot);
                        return game;
                    } else { // server is checked
                        gc = new GameConnection(Integer.parseInt(port.getText()));
                        Player locPlayer = new LocalPlayer(locName.getText());
                        Player remPlayer = new NetworkPlayer(gc);
                        gc.sendColor(!RBserverWhite.isSelected());
                        Game game;
                        if (RBserverWhite.isSelected()) {
                            game= new Game(gc, locPlayer, remPlayer, jgam);
                        } else {
                            game= new Game(gc, remPlayer, locPlayer, jgam);
                        }
                        if(boardFile != null) {
                           BoardSnapshot snapshot = new BoardSnapshot(boardFile);
                           game.setSnapshot(snapshot);
                           gc.getWriter().write(snapshot.toSendLine()+"\n");
                           gc.getWriter().flush();
                       } else {
                           gc.getWriter().write(BoardSnapshot.NEWGAME + "\n");
                           gc.getWriter().flush();
                       }
                       return game;
                    }
                }
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(this,
                                              msg.getString("errorPort"),
                                              msg.getString("error"),
                                              JOptionPane.ERROR_MESSAGE);
            } catch (Exception ex) {
                ex.printStackTrace();
                JOptionPane.showMessageDialog(this, ex,
                                              msg.getString("error"),
                                              JOptionPane.ERROR_MESSAGE);

                if (gc != null) {
                    gc.close();
                }
            }

        }

    }

    public void enableDisable() {
        boolean local = RBlocal.isSelected();
        boolean client = !local && (RBclient.isSelected() || RBgnubg.isSelected());
        name1.setEnabled(local);
        jLabel1.setEnabled(local);
        name2.setEnabled(local);
        jLabel2.setEnabled(local);
        RBclient.setEnabled(!local);
        RBgnubg.setEnabled(!local);
        RBserverBlue.setEnabled(!local);
        RBserverWhite.setEnabled(!local);
        server.setEnabled(client);
        jLabel4.setEnabled(client);
        locName.setEnabled(!local);
        jLabel3.setEnabled(!local);
        port.setEnabled(!local);
        jLabel5.setEnabled(!local);
        loadButton.setEnabled(!client || (!local && RBgnubg.isSelected()));
        fileNameLabel.setEnabled(!client || (!local && RBgnubg.isSelected()));
    }

    /**
     * feed infos from command line
     */

    public void feed(String mode, String portArg, String serverArg,
                     String name1Arg, String name2Arg, String boardFileArg) {
        if (mode.equals("local")) {
            RBlocal.setSelected(true);
        } else {
            RBnetwork.setSelected(true);
            if (mode.equals("client")) {
                RBclient.setSelected(true);
            } else if (mode.equals("serverWhite")) {
                RBserverWhite.setSelected(true);
            } else if (mode.equals("serverBlue")) {
                RBserverBlue.setSelected(true);
            } else if (mode.equals("gnubg")) {
                RBgnubg.setSelected(true);
            } else {
                throw new RuntimeException("unsupported mode: " + mode);
            }
        }
        if (portArg != null) {
            port.setText(portArg);
        }
        if (serverArg != null) {
            server.setText(serverArg);
        }
        if (name1Arg != null) {
            name1.setText(name1Arg);
            locName.setText(name1Arg);
        }
        if (name2Arg != null) {
            name2.setText(name2Arg);
        }
        if(boardFileArg != null) {
            boardFile = new File(boardFileArg);
            fileNameLabel.setText(boardFile.getName());
            loadButton.setSelected(true);
        }

    }

    public void loadButtonChanged() {

        if(loadButton.isSelected()) {
            JFileChooser fc = new JFileChooser();
            fc.addChoosableFileFilter(boardFileFilter);
            fc.setAccessory(new BoardFileView(fc));
            int result = fc.showOpenDialog(this);
            if(result == fc.APPROVE_OPTION) {
                boardFile = fc.getSelectedFile();
                fileNameLabel.setText(fc.getSelectedFile().getName());
            } else {
                boardFile = null;
                fileNameLabel.setText("");
                loadButton.setSelected(false);
            }
        } else {
            boardFile = null;
            fileNameLabel.setText("");
        }

    }

    private FileFilter boardFileFilter = new FileFilter() {
        public boolean accept(File pathname) {
            return (pathname.getName().toLowerCase().endsWith(".board")
                    || pathname.isDirectory());
        }
        public String getDescription() { return msg.getString("boardFilter"); }
    };


}

