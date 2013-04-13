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

import java.awt.Graphics;
import java.awt.Point;
import java.awt.event.*;

import javax.swing.ImageIcon;
import java.awt.*;
import java.util.List;
import jgam.util.*;
import java.util.*;

/**
 * This is used in Board to react to mouse events, such as drag and drop and
 * double click.
 *
 * During Board.paint() this paint method is also called.
 *
 * @author Mattias Ulbrich
 */
public class BoardMouseListener implements MouseListener, MouseMotionListener {

    private Board board;
    private JGammon jgam;

    // if dragging around, what chip at what position
    private ImageIcon icon;
    private Point position;

    // store the possible goals, they are painted in green
    private List possibleMoves;

    // where dragging began
    private int startJag;

    // the position of the jags in the board and their sizes
    static Rectangle[] jags = new Rectangle[25];
    static Dimension outwindow = new Dimension(Board.JAGWIDTH, Board.OUTHEIGHT);
    static Dimension jagwindow = new Dimension(Board.JAGWIDTH, Board.JAGHEIGHT);


    public BoardMouseListener(Board b, JGammon g) {
        board = b;
        jgam = g;
        b.addMouseListener(this);
        b.addMouseMotionListener(this);
    }

    public void mouseDragged(MouseEvent e) {
        position = e.getPoint();
        board.repaint();
    }

    public void mouseMoved(MouseEvent e) {
    }

    /**
     * make the move if there is only one possible goal
     * @param e MouseEvent
     */
    public void mouseClicked(MouseEvent e) {

        System.out.println("klicks " + e.getClickCount() + " button " +
                           e.getButton());
        if (e.getClickCount() != 2) {
            return;
        }

        position = e.getPoint();
        int jag = calcWhiteJag(e.getPoint());
        Player player = null;
        if (jgam.getGame() != null) {
            player = jgam.getGame().getCurrentPlayer();
        }
        if (player == null || !player.isWaitingForUIMove() || jag == -1) {
            return;
        }

        player.setDragged( -1);

        jag = player.adjustJag(jag);
        possibleMoves = player.getPossibleMovesFrom(jag);

        if(possibleMoves.size() < 1)
            return;

        if(possibleMoves.size() == 1) {
            jgam.getGame().handle(possibleMoves.get(0));
            return;
        }

        // check that it is clear what is meant
        // first possibility: only a single length left (doublet or only one dice left)
        if (player.getRemainingHops().distinctValues().length() == 1) {
            // the first is the one with one hop
            jgam.getGame().handle(possibleMoves.get(0));
            return;
        }

        // 2nd poss: all moves have the same goal
        int to = ((Move) possibleMoves.get(0)).to();
        for (Iterator iter = possibleMoves.iterator(); iter.hasNext(); ) {
            Move item = (Move) iter.next();
            if (item.to() != to) {
                return;
            }
        }

        jgam.getGame().handle(possibleMoves.get(0));

    }

    public void mouseEntered(MouseEvent e) {
    }

    public void mouseExited(MouseEvent e) {
    }

    /**
     * dragging begins
     * @param e MouseEvent
     */
    public void mousePressed(MouseEvent e) {
        position = e.getPoint();

        Player player = null;
        if (jgam.getGame() != null) {
            player = jgam.getGame().getCurrentPlayer();
        }
        if (player == null || !player.isWaitingForUIMove()) {
            return;
        }

        startJag = calcWhiteJag(e.getPoint());

        if (startJag == -1) {
            return;
        }

        startJag = player.adjustJag(startJag);

        if (player.getJag(startJag) <= 0) {
            startJag = -1;
            return;
        }

        player.setDragged(startJag);

        icon = player.getChipIcon();

        possibleMoves = player.getPossibleMovesFrom(startJag);
        /* debug output
                 Collections.sort(possibleMoves);
         for (Iterator iter = possibleMoves.iterator(); iter.hasNext(); ) {
         System.out.println("Possible move from "+startJag+": "+iter.next());
                 }*/

        board.repaint();
    }

    /**
     * dragging ends
     * @param e MouseEvent
     */
    public void mouseReleased(MouseEvent e) {
        icon = null;
        position = e.getPoint();
        Player player = null;
        if (jgam.getGame() != null) {
            player = jgam.getGame().getCurrentPlayer();
        }
        if (player == null || !player.isWaitingForUIMove() || startJag == -1) {
            return;
        }

        int endJag = calcWhiteJag(e.getPoint());
        player.setDragged( -1);

        if (endJag == -1) {
            board.repaint();
            return;
        }

        // choose the shortest move from startTag to endTag
        Collections.sort(possibleMoves);
        if (possibleMoves != null) {
            endJag = player.adjustJag(endJag);
            for (Iterator iter = possibleMoves.iterator(); iter.hasNext(); ) {
                Move move = (Move) iter.next();
                if (move.to() == endJag) {
                    jgam.getGame().handle(move);
                    break;
                }
            }
        }

        board.repaint();
    }

    /**
     * draw the the dragged chip and the green possible goals
     * @param g Graphics to draw to
     */
    public void drawDraged(Graphics g) {

        /*
                 for (int i = 0; i < jags.length; i++) {
         g.drawRect(jags[i].x, jags[i].y, jags[i].width, jags[i].height);
                 }
                 g.setColor(Color.red);
                 Rectangle r = getOutField();
                 g.drawRect(r.x,r.y,r.width,r.height);*/
        if (icon != null) {

            for (Iterator iter = possibleMoves.iterator(); iter.hasNext(); ) {
                Move m = (Move) iter.next();
                int jag = m.player().adjustJag(m.to());

                if (jag == 0) {
                    paintGreenOut(jgam.getGame().getCurrentPlayer(), g);
                } else {
                    Player p = jgam.getGame().getCurrentPlayer();
                    board.paintChip(greenRing, g, jag,
                                    p.getJagWithDragging(p.adjustJag(jag)));
                }
            }

            g.drawImage(icon.getImage(), position.x - board.JAGWIDTH / 2,
                        position.y - board.JAGWIDTH / 2, null);
        }
    }

    public void paintGreenOut(Player player, Graphics g) {
        int ypos = 0;
        if (board.isPlayerOnTop(player)) {
            ypos = board.OUT_START.y;
        } else {
            ypos = board.size.height - board.OUT_START.y - board.JAGWIDTH;
        }

        int xpos = 0;
        if (board.isLeftRightFlipped()) {
            xpos = board.size.width - board.OUT_START.x - board.JAGWIDTH;
        } else {
            xpos = board.OUT_START.x;
        }

        g.drawImage(greenRing.getImage(), xpos, ypos, null);

    }

    /**
     * calculate the native jag number of a point. Native jags are
     * 0 1 2 3 .. 11
     * 12 ... 23
     * @param point Point within the board
     * @return int 0-23 a native jag number
     */
    private int calcJag(Point point) {
        for (int i = 0; i < jags.length; i++) {
            if (jags[i].contains(point)) {
                return i;
            }
        }
        return -1;
    }

    /**
     * calculate the jag  number of a point. This is the correct number
     * for the white player. the blue is then 25-X.
     * these are
     * 1 2 ... 12
     * 24 23 ... 13
     * @param point Point
     * @return int 1-24
     */
    private int calcWhiteJag(Point point) {
        int nat = calcJag(point);
        if (nat == -1) {
            if (getOutField().contains(point)) {
                return 0; // out
            }
            return -1;
        }

        // other direction downstairs!
        if (nat >= 12 && nat <= 23) {
            nat = 35 - nat;
        }
        return board.correctJag(nat + 1);
    }

    private Rectangle getOutField() {
        Point p = (Point) board.OUT_START.clone();
        if (board.isLeftRightFlipped()) {
            p.x = board.size.width - p.x - board.JAGWIDTH;
        }
        if (!board.isPlayerOnTop(jgam.getGame().getCurrentPlayer())) {
            p.y = board.size.height - p.y - board.OUTHEIGHT;
        }

        return new Rectangle(p, outwindow);
    }


    // calculate the rectangles of the jags.
    static {
        int y2 = Board.size.height - Board.BOARD_START.y - jagwindow.height;
        // here begin the lower rectangles
        for (int i = 0; i < 24; i++) {
            jags[i] = new Rectangle(Board.BOARD_START, jagwindow);
            jags[i].translate((i % 12) * Board.JAGWIDTH, 0);
            if (i % 12 >= 6) { // beyond the bar
                jags[i].translate(Board.BARWIDTH, 0);
            }
            if (i >= 12) { // lower half
                jags[i].y = y2;
            }
        }

        // the bar
        jags[24] = new Rectangle((Board.size.width - Board.BARWIDTH) / 2,
                                 Board.BOARD_START.y,
                                 Board.BARWIDTH,
                                 Board.size.height - 2 * Board.BOARD_START.y);

    }

    private static ImageIcon greenRing = new ImageIcon(BoardMouseListener.class.
            getResource("img/greenRing.gif"));
}
