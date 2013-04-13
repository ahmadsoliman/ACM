package eg.edu.guc.dvonn.gui;

import java.awt.Color;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JButton;

import eg.edu.guc.dvonn.engine.Board;

@SuppressWarnings("serial")
public class RingButton extends JButton {

	public RingButton() {
		setBorderPainted(false);
		setContentAreaFilled(false);
		setHideActionText(true);
		setRolloverEnabled(false);
		try {
			setSelectedIcon(new ImageIcon(
					ImageIO.read(new File("freecell.png"))));
		} catch (IOException e) {
		}
	}

	public RingButton(ImageIcon img, ImageIcon selImg, int color) {
		super(img);
		setSelectedIcon(selImg);
		setBorderPainted(false);
		setContentAreaFilled(false);
		setHideActionText(true);
		setRolloverEnabled(false);
		setHorizontalTextPosition(CENTER);
		setVerticalTextPosition(CENTER);

		if (color == Board.PLAYER1) {
			setForeground(Color.BLACK);
		} else if (color == Board.PLAYER2) {
			setForeground(Color.WHITE);
		} else {
			setForeground(Color.GREEN);
		}
	}

}
