package tasks;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;

@SuppressWarnings("serial")
public class Task extends JFrame implements ActionListener {
	JButton btn1, btn2;
	boolean toggled;

	public static void main(String[] args) throws IOException {
		new Task();
	}

	public Task() throws IOException {
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLayout(null);
		setTitle("Task");
		setBounds(300, 100, 500, 500);

		btn1 = new JButton("Toggle ON");
		btn1.setBounds(50, 50, 100, 50);
		btn1.setActionCommand("toggle");
		btn1.addActionListener(this);
		add(btn1);
		
		BufferedImage img = ImageIO.read(new File("black.png"));
		btn2 = new JButton("Exit",new ImageIcon(img));
		btn2.setBackground(Color.BLACK );
		btn2.setForeground(Color.WHITE);
		btn2.setHorizontalTextPosition(JButton.CENTER);
		btn2.setVerticalTextPosition(JButton.CENTER);
		btn2.setBounds(200, 50, 100, 50);
		btn2.setActionCommand("exit");
		btn2.addActionListener(this);
		add(btn2);

		setVisible(true);
	}

	public void actionPerformed(ActionEvent e) {
		String s = e.getActionCommand();
		if (s.equals("toggle")) {
			toggle();
		} else if (s.equals("exit")) {
			exit();
		}
	}

	public void exit() {
		System.exit(0);
	}

	public void toggle() {
		if (toggled) {
			btn1.setText("Toggle ON");
			toggled = false;
		} else {
			btn1.setText("Toggle OFF");
			toggled = true;
		}
	}
}
