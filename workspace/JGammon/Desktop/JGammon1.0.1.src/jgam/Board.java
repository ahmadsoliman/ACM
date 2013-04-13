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

import javax.swing.ImageIcon;
import javax.swing.JComponent;

/**
 *
 * Component to draw the backgammon board.
 *
 * It fetches the information from a Game-instance.
 *
 * Additionally it allows drag and drop via a BoardMouseListener.
 * Additionally it allows an Animation to be drawn via BoardAnimation
 *
 * @author Mattias Ulbrich
 */
public class Board extends JComponent {

    // the appl.
    private JGammon jGam;

    // dragging is done with this
    private BoardMouseListener mouseListener;

    // animated dragging
    private BoardAnimation boardAnimation;

    /*
     * some drawing variants
     */
    private boolean flipTopBottom = false;
    private boolean flipLeftRight = true;

    public Board(JGammon jGam) {
        this.jGam = jGam;
        mouseListener = new BoardMouseListener(this, jGam);
    }

    /**
     * calculate the size of this canvas. This is the dimension of the
     * background
     * @return Dimension of this canvas
     */
    private static Dimension calcSize() {
        return new Dimension(background.getIconWidth(),
                             background.getIconHeight());
    }

    public Dimension getPreferredSize() {
        return size;
    }

    /**
     * turn the board for 180°
     */
    public void toggleTurn() {
        toggleTopBottom();
        toggleLeftRight();
    }

    /**
     * mirror the board top to bottom
     */
    public void toggleTopBottom() {
        flipTopBottom = !flipTopBottom;
        repaint();
    }

    /**
     * mirror the board left to right
     */
    public void toggleLeftRight() {
        flipLeftRight = !flipLeftRight;
        repaint();
    }

    /**
     * paint the board.
     * Player 1 white
     * Player 2 blue
     * @param g Graphics
     */
    public void paint(Graphics g) {
        g.drawImage(background.getImage(), 0, 0, null, this);
        Game game = getGame();
        if (game == null) {
            return;
        }

        // direction 1:
        Player p = game.getPlayerWhite();
        for (int i = 1; i <= 24; i++) {
            paintJag(whiteChip, g, i, p.getJagWithDragging(i));
        }

        // the other
        p = game.getPlayerBlue();
        for (int i = 1; i <= 24; i++) {
            paintJag(blueChip, g, 25 - i, p.getJagWithDragging(i));
        }

        // the dice
        // player 1
        int d[] = game.getPlayerWhite().getShownDice();
        if (d != null) {
            for (int i = 0; i < d.length; i++) {
                int x = DICE_POINT.x + DICE_DIST * i;
                g.drawImage(whiteDice[d[i] - 1].getImage(), x,
                            DICE_POINT.y, this);
            }
        }

        // player 2
        d = game.getPlayerBlue().getShownDice();
        if (d != null) {
            for (int i = 0; i < d.length; i++) {
                int x = size.width - (DICE_POINT.x + DICE_DIST * i) - 49;
                g.drawImage(blueDice[d[i] - 1].getImage(), x,
                            DICE_POINT.y, this);
            }
        }

        // the outs
        paintOut(whiteChipThin, game.getPlayerWhite(), g);
        paintOut(blueChipThin, game.getPlayerBlue(), g);

        // the bar
        if(flipTopBottom) {
            paintJag(whiteChip, g, 0, game.getPlayerWhite().getJagWithDragging(25));
            paintJag(blueChip, g, 25, game.getPlayerBlue().getJagWithDragging(25));
        } else {
            paintJag(whiteChip, g, 25, game.getPlayerWhite().getJagWithDragging(25));
            paintJag(blueChip, g, 0, game.getPlayerBlue().getJagWithDragging(25));
        }

        // the doubleDice
        paintDoubleDice(g);

        // dragged objects
        mouseListener.drawDraged(g);

        // animation
        if (boardAnimation != null) {
            boardAnimation.paint(g);
        }
    }

    /**
     * @todo perhaps better make 6 pngs ...
     * @param g Graphics
     */
    private void paintDoubleDice(Graphics g) {
        Game game = getGame();
        int doubleValue = game.getDoubleValue();
        if (doubleValue != 1) {
            // get the corresponding icon
            ImageIcon theIcon = doubleDice[log2(doubleValue)-1];

            // prepare the number
            int xpos = (size.width - theIcon.getIconWidth()) / 2;
            int ypos;
            if (game.mayDouble(game.getPlayerWhite()) == flipTopBottom) {
                ypos = size.height - DOUBLE_OFFSET - theIcon.getIconHeight();
            } else {
                ypos = DOUBLE_OFFSET;
            }

            g.drawImage(theIcon.getImage(), xpos, ypos, this);

        }
    }

    /**
     * determine the log to the base of 2 of an integer.
     * The result is the largest integer such that
     * 2^result <= value
     * @param value int to determine the log of. must be >= 1
     * @return the largest int result with 2^result <= value
     */
    private static int log2(int value) {
        if(value <= 0)
            throw new IllegalArgumentException("log2 argument error: "+value);
        if(value == 1) return 0;
        return log2(value >> 1) + 1;
    }

    /**
     * paint the final output fields
     * @param image Image thin chips
     * @param player Player to draw
     * @param g Graphics to write to
     */
    private void paintOut(ImageIcon image, Player player, Graphics g) {

        Point start = getOutField(player);

        for (int i = 0; i < player.getOff(); i++) {
            g.drawImage(image.getImage(), start.x, start.y - (i+1) * CHIPTHICKNESS, this);
        }
    }

    /**
     * get the lower left corner of the outfield for a player
     * @param player Player
     * @return Point
     */
    public Point getOutField(Player player) {
        int ypos = 0;
        if (isPlayerOnTop(player)) {
            ypos = OUT_START.y + OUTHEIGHT;
        } else {
            ypos = size.height - OUT_START.y;
        }

        int xpos = 0;
        if (isLeftRightFlipped()) {
            xpos = size.width - OUT_START.x - CHIPDIAMETER;
        } else {
            xpos = OUT_START.x;
        }

        return new Point(xpos, ypos);
    }

    /**
     * transform a logical jag number to one on the screen.
     * this depends also
     * on the color.
     * Flipping plays into it as well
     * @param no int to be corrected
     */
    public int correctJag(int no) {
        if (no == 0 || no == 25) {
            return no;
        }

        if (flipTopBottom) {
            no = 25 - no;
        }
        if (flipLeftRight) {
            if (no <= 12) {
                no = 13 - no;
            } else {
                no = 37 - no;
            }
        }
        return no;
    }

    /**
     * paint a jag with chips from a certain color.
     * Jags are corrected internally!
     *
     * @param chip ImageIcon that holds the chip
     * @param jag number of the jag (1-24)
     * @param count number of chips to paint
     */
    public void paintJag(ImageIcon chip, Graphics g, int jag, int count) {
        for (int i = 0; i < count; i++) {
            paintChip(chip, g, jag, i);
        }
    }

    public void paintChip(ImageIcon chip, Graphics g, int jag, int number) {

        Point p = getPointForChip(jag, number);
        g.drawImage(chip.getImage(), p.x, p.y, null, this);

    }

    /**
     * get the point to draw the chip at for a specific position an a jag.
     * jag 1-24 are as seen from white. 0 is lower bar, 25 is upper bar.
     *
     * @param jag int
     * @param number int
     * @return Point
     */
    public Point getPointForChip(int jag, int number) {

        Point p;

        //  bar first!   25 is bar   0 is adjusted bar (25-25)
        if (jag == 25) {
            return new Point((size.width - JAGWIDTH) / 2,
                             (2 + number) * JAGWIDTH);
        }

        if (jag == 0) {
            return new Point((size.width - JAGWIDTH) / 2,
                             size.height - ((3 + number) * JAGWIDTH));
        }

        jag = correctJag(jag);

        int offset = (number % 9) * JAGWIDTH;
        if (number >= 5 && number <= 8) {
            offset = (number - 5) * JAGWIDTH + JAGWIDTH / 2;
        }

        if (jag <= 12) {
            p = (Point) BOARD_START.clone();
            p.translate(JAGWIDTH * (jag - 1), offset);
            // beyond the bar
            if (jag >= 7) {
                p.translate(BARWIDTH, 0);
            }
        } else {
            p = new Point(size.width - BOARD_START.x,
                          size.height - BOARD_START.y);
            p.translate( -JAGWIDTH * (jag - 12), -JAGWIDTH - offset);
            // beyond the bar
            if (jag >= 19) {
                p.translate( -BARWIDTH, 0);
            }
        }

        return p;
    }

    public Game getGame() {
        if (jGam != null) {
            return jGam.getGame();
        } else {
            return null;
        }
    }

    public void setAnimation(BoardAnimation animation) {
        this.boardAnimation = animation;
    }


    public boolean isLeftRightFlipped() {
        return flipLeftRight;
    }

    public boolean isTopBottomFlipped() {
        return flipTopBottom;
    }

    /**
     * return true if the player has his home in the upper half of the board.
     * this is the case if not vert-flipped and white or flipped and blue
     * @param player Player
     * @return boolean
     */
    public boolean isPlayerOnTop(Player player) {
        return player.isWhite() != isTopBottomFlipped();
    }

    /*
     * images
     */
    private static ImageIcon background = new ImageIcon(Board.class.getResource(
            "img/background.png"));
    static ImageIcon whiteChip = new ImageIcon(Board.class.getResource(
            "img/whiteChip.gif"));
    static ImageIcon blueChip = new ImageIcon(Board.class.getResource(
            "img/blueChip.gif"));
    static ImageIcon whiteChipThin = new ImageIcon(Board.class.getResource(
            "img/whiteChipThin.gif"));
    static ImageIcon blueChipThin = new ImageIcon(Board.class.getResource(
            "img/blueChipThin.gif"));
    private static ImageIcon doubleDice[] = new ImageIcon[6];
    private static ImageIcon[] blueDice = new ImageIcon[6];
    private static ImageIcon[] whiteDice = new ImageIcon[6];

    static {
        for (int i = 1; i <= 6; i++) {
            blueDice[i - 1] = new ImageIcon(Board.class.getResource(
                    "img/blue" + i + ".gif"));
            whiteDice[i - 1] = new ImageIcon(Board.class.getResource(
                    "img/white" + i + ".gif"));
            doubleDice[i-1] = new ImageIcon(Board.class.getResource(
                    "img/doubleDice"+(1<<i)+".png"));
        }
    }

    private static Font serifFont = new Font("Serif", Font.BOLD, 52);

    /*
     * widths
     */
    static final int JAGWIDTH = 48;
    static final int JAGHEIGHT = 270;
    static final int OUTHEIGHT = 280;
    // instead of chipdiameter often jagwidth is used being the same
    static final int CHIPDIAMETER = 48;
    static final int CHIPTHICKNESS = 15;
    static final int BARWIDTH = 97;
    static final int DICE_DIST = 80;
    static final int DOUBLE_OFFSET = 30;
    static final Dimension size = calcSize();

    /**
     * Points
     */
    // point where the first jag starts (upper left)
    static final Point BOARD_START = new Point(95, 24);
    // position to draw the first dice to
    static final Point DICE_POINT = new Point(150, 303);
    // the point at which the upper left out field begins
    static final Point OUT_START = new Point(24, 24);


}
