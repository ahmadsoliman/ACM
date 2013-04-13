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

import javax.swing.*;
import java.awt.*;

/**
 * Animation that is shown if the remote player drags a chip.
 *
 * It is one in a thread of its own.
 *
 * @author Mattias Ulbrich
 * @version 1.0
 */
public class BoardAnimation extends Thread {

    private Player player;
    private ImageIcon chip;
    private int fromJag;
    private int toJag;

    private double curX, curY;
    private double offsetX, offsetY;

    public static final int STEPLENGTH = Integer.getInteger(
            "jgam.animationstep", 25).intValue();

    private static final long SLEEPTIME = Integer.getInteger(
            "jgam.animationdelay", 35).intValue();

    public BoardAnimation(Player player, int from, int to) {
        this.player = player;
        this.chip = player.getChipIcon();

        fromJag = from;
        toJag = to;
    }

    synchronized public void animate(Board board) {
        try {
            board.setAnimation(this);
            int fromNo = player.getJag(fromJag) - 1;
            int toNo = player.getJag(toJag);

            Point fromPoint, toPoint;
            // from Bar
            if (fromJag == 25) {
                fromPoint = board.getPointForChip(board.isPlayerOnTop(player) ?
                                                  25 : 0, fromNo);
            } else {
                fromPoint = board.getPointForChip(player.adjustJag(fromJag),
                                                  fromNo);
            }

            // to off
            if (toJag == 0) {
                toPoint = board.getOutField(player);
                toPoint.translate(0,
                                  -Board.CHIPDIAMETER -
                                  player.getOff() * Board.CHIPTHICKNESS);
            } else {
                toPoint = board.getPointForChip(player.adjustJag(toJag), toNo);
            }

            curX = fromPoint.x;
            curY = fromPoint.y;
            double distance = toPoint.distance(fromPoint);
            offsetX = (toPoint.x - fromPoint.x) * STEPLENGTH / distance;
            offsetY = (toPoint.y - fromPoint.y) * STEPLENGTH / distance;

            int nosteps = (int) (distance / STEPLENGTH);

            player.setDragged(fromJag);
            for (int i = 0; i < nosteps; i++) {
                Thread.sleep(SLEEPTIME);
                curX += offsetX;
                curY += offsetY;
                board.repaint();
                wait(); // wait for the animation to be painted
            }
        } catch (InterruptedException ex) {
        } finally {
            board.setAnimation(null);
            player.setDragged( -1);
        }
    }

    synchronized public void paint(Graphics g) {
        g.drawImage(chip.getImage(), (int) curX, (int) curY, null);
        notify();
    }

}
