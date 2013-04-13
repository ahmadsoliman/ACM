package eg.edu.guc.dvonn.engine;

import java.awt.Point;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;

public class Ring {
	private char color;
	private int player;
	private Point pos;

	public BufferedImage img, selectedImg;
	public static BufferedImage dvonn;

	public Ring() {
		color = 'n';
		player = -1;
	}

	public Ring(char c, int pl, String pathImg, String pathSelImg) {
		color = c;
		player = pl;
		try {
			img = ImageIO.read(new File(pathImg));
			if (c != 'r') {
				selectedImg = ImageIO.read(new File(pathSelImg));
			}
			if (dvonn == null) {
				dvonn = ImageIO.read(new File("red.png"));
			}
		} catch (IOException e) {
			System.out.println("Error:" + e.getMessage());
		}
	}

	public char getColor() {
		return color;
	}

	public String getColorName() {
		switch (color) {
		case 'r':
			return "Red";
		case 'w':
			return "White";
		case 'b':
			return "Black";
		default:
			return "Ring Color Error";
		}
	}

	public int getPlayer() {
		return player;
	}

	public void setPos(Point p) {
		pos = p;
	}

	public Point getPos() {
		return pos;
	}

}
