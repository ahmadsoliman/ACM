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

import java.text.MessageFormat;
import java.util.ResourceBundle;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

/**
 * This subclass of Player is used for player at this local terminal.
 *
 * It reacts to local UI-input such as moves and button pressing
 * (ROLL; DOUBLE; GIVEUP)
 *
 * @author Mattias Ulbrich
 */
public class LocalPlayer extends Player {

    /** used for commication betw. threads */
    private Object lastMessage;

    private ResourceBundle msg = ResourceBundle.getBundle("jgam.msg.Player");
    private MessageFormat msgFormat = new MessageFormat("");

    /** if this is true
     * moves with the mouse may be done
     */
    private boolean allowMoves;

    public LocalPlayer(String name) {
        super(name);
    }


    /**
     * the other player offers something. This player may accept or not.
     * Neither true nor false do imply finishing the game!
     *
     * For the local player the offer is done via a dialog box
     *
     * @param offer the offer as index number DOUBLE, GIVE_UP_*
     * @return true if the offer is accepted.
     */
    public boolean acceptsOffer(int offer) {

        JFrame frame = getGame().getJGam().getFrame();
        if (offer == DOUBLE) {
            msgFormat.applyPattern(msg.getString("confirmDouble"));
            String M = msgFormat.format(new Object[] {
                                        getOtherPlayer().getName(),
                                        new Integer(2 *
                    getGame().getDoubleValue())});

            return JOptionPane.showConfirmDialog(frame, M,
                                                 msg.getString("confirm"),
                                                 JOptionPane.YES_NO_OPTION,
                                                 JOptionPane.QUESTION_MESSAGE,
                                                 getChipIcon()) ==
                    JOptionPane.YES_OPTION;
        } else {
            msgFormat.applyPattern(msg.getString("confirmGiveup"));
            String M = msgFormat.format(new Object[] {
                                        getOtherPlayer().getName(),
                                        getLevelName(offer)});

            return JOptionPane.showConfirmDialog(frame, M,
                                                 msg.getString("confirm"),
                                                 JOptionPane.YES_NO_OPTION,
                                                 JOptionPane.QUESTION_MESSAGE,
                                                 getChipIcon()) ==
                    JOptionPane.YES_OPTION;
        }
    }

    /**
     * given an offer extract the name of it from the constant.
     * get the localized one!
     * @param offer int GIVE_UP_*
     * @return String describing the offer
     */
    private String getLevelName(int offer) {
        switch(offer) {
        case ORDINARY: return msg.getString("ordinary");
        case GAMMON: return msg.getString("gammon");
        case BACKGAMMON: return msg.getString("backgammon");
        }
        throw new IllegalArgumentException(Integer.toString(offer));
    }

    /**
     * get the next Move.
     *
     * UI waiting
     * wait till i am waked up and then go for it ...
     *
     * @return Move
     * @todo Implement this jgam.Player method
     */
    synchronized public Move move() throws InterruptedException, UndoException {
        while (true) {
            allowMoves = true;
            wait();
            allowMoves = false;
            if (lastMessage instanceof Move) {
                Move m = (Move) lastMessage;
                return m;
            }
            if (lastMessage.equals("undo")) {
                throw new UndoException(true);
            }
        }
    }

    /**
     * a message is passed from the awtthread.
     *
     * store it and wake up a possibly waiting thread.
     *
     * @param msg Message-Object
     * @todo Implement this jgam.Player method
     */
    synchronized public void handle(Object msg) {
        lastMessage = msg;
        notify();
    }


    /**
     *
     * @return true if so
     * @todo Implement this jgam.Player method
     */
    public boolean isRemote() {
        return false;
    }

    private String[] giveups = {getLevelName(ORDINARY), getLevelName(GAMMON), getLevelName(BACKGAMMON)};
    /**
     * if this player wants to doube or give up before his/her/move.
     *
     * wait for an action!
     *
     * @param rollOnly if this is true, only ROLL is allowed
     * @return one of ROLL, DOUBLE, GIVE_UP_*
     * @todo Implement this jgam.Player method
     */
    synchronized public int nextStep(boolean rollOnly) throws
            InterruptedException, UndoException {

        int ret = -1;
        getGame().getJGam().getFrame().enableButtons(rollOnly);

        while (ret == -1) {
            wait();
            if (lastMessage.equals("roll")) {
                ret = ROLL;
            } else if (lastMessage.equals("double")) {
                if (getGame().mayDouble(this)) {
                    ret = DOUBLE;
                } else {
                    JOptionPane.showMessageDialog(getGame().getJGam().getFrame(),
                                                  msg.getString(
                            "doublenotallowed"));
                }
            } else if (lastMessage.equals("giveup")) {
                String answer = (String)
                                JOptionPane.showInputDialog(getGame().getJGam().
                        getFrame(),
                        msg.getString("proposeGiveup"),
                        msg.getString("choose"),
                        JOptionPane.PLAIN_MESSAGE,
                        getChipIcon(), giveups, giveups[0]);
                if (answer != null) {
                    if (answer.equals(getLevelName(ORDINARY))) {
                        ret = GIVE_UP;
                    } else if (answer.equals(getLevelName(GAMMON))) {
                        ret = GIVE_UP_GAMMON;
                    } else if (answer.equals(getLevelName(BACKGAMMON))) {
                        ret = GIVE_UP_BACKGAMMON;
                    }
                }
            } else if (lastMessage.equals("remoteUndo") && getGame().getUndoPlayer() == getOtherPlayer()) {
                throw new UndoException(true);
            } else if (lastMessage.equals("undo") && !getGame().getUndoPlayer().isRemote()) {
                // local vs. local has no remoteUndo!
                throw new UndoException(true);
            }
        }

        getGame().getJGam().getFrame().disableButtons();
        return ret;

    }


    /**
     * are UI-moves to be made right now?
     * @return true if yes
     */
    synchronized public boolean isWaitingForUIMove() {
        return allowMoves;
    }

    /** nothing to be done when aborting */
    public void abort() {}

    public void informAccept(boolean answer) {}

    public void informMove(SingleMove move) {}

    public void informRoll() {}

    public void animateMove(Move m) {}


}
