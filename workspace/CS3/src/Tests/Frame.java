package Tests;

import java.awt.Color;
import java.awt.Container;
import java.awt.EventQueue;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JButton;
 
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
 
@SuppressWarnings("unused")
public class Frame extends JFrame {
 
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
 
	/**
	 * Launch the application
	 * @param args
	 */
	
	public static void main(String args[]) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Frame frame = new Frame();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
 
	/**
	 * Create the frame
	 */
	public Frame() {
		super("Memory Game");
		getContentPane().setLayout(new GridLayout(1, 0));
		setBounds(100, 100, 403, 331);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 
		final JPanel panel = new JPanel();
		panel.setLayout(null);
		getContentPane().add(panel);
 
		final JLabel label = new JLabel("Memory Game, Version 1.0");
		label.setBounds(91, 140, 247, 16);
		panel.add(label);
 
		final JPanel panel_1 = new JPanel();
		panel_1.setBackground(Color.BLUE);
		panel_1.setBounds(0, 0, 395, 120);
		panel.add(panel_1);
 
		final JLabel memoryGameVersionLabel = new JLabel();
		memoryGameVersionLabel.setText("By (my name goes here)");
		memoryGameVersionLabel.setBounds(91, 198, 247, 16);
		panel.add(memoryGameVersionLabel);
 
		final JLabel memoryGameVersionLabel_1 = new JLabel();
		memoryGameVersionLabel_1.setText("(my school goes here) Project #");
		memoryGameVersionLabel_1.setBounds(91, 176, 247, 16);
		panel.add(memoryGameVersionLabel_1);
 
		final JLabel memoryGameVersionLabel_2 = new JLabel();
		memoryGameVersionLabel_2.setText("Screw Copyright. Use this program at will.");
		memoryGameVersionLabel_2.setBounds(91, 238, 247, 16);
		panel.add(memoryGameVersionLabel_2);
 
		final JLabel memoryGameVersionLabel_3 = new JLabel();
		memoryGameVersionLabel_3.setText("Open Source, The Future is Open");
		memoryGameVersionLabel_3.setBounds(91, 257, 247, 16);
		panel.add(memoryGameVersionLabel_3);
		//
	}
 
}
         