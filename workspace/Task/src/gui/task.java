package gui;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;


import javax.swing.JButton;
import javax.swing.JFrame;
@SuppressWarnings("serial")
public class task extends JFrame implements ActionListener{
	public static void main(String[] args){
		new task();
	}
	JButton NextBtn;
	ArrayList<JButton> buttons;
	public task(){
		buttons = new ArrayList<JButton>();
		
		setLayout(null);
		setBounds(100,50,500,200);
		
		NextBtn = new JButton("NextBtn");
		NextBtn.setBounds(0,50,100,50);
		NextBtn.addActionListener(this);
		NextBtn.setActionCommand("nextCmd");
		add(NextBtn);
		JButton tmp = new JButton("1");
		tmp.setBounds(100,50,50,50);
		buttons.add(tmp);
		add(tmp);
		tmp = new JButton("2");
		tmp.setBounds(150,50,50,50);
		buttons.add(tmp);
		add(tmp);
		setVisible(true);
	}

	public void actionPerformed(ActionEvent e) {
		String action = e.getActionCommand();
		if(action.equals("nextCmd")){
			String last = buttons.get(buttons.size()-1).getText();
			String before = buttons.get(buttons.size()-2).getText();
			JButton tmp = new JButton((Integer.parseInt(last)+Integer.parseInt(before))+"");
			buttons.add(tmp);
			tmp.setBounds(50+50*buttons.size(),50,50,50);
			add(tmp);
			repaint();
			validate();
		}
	}
}
