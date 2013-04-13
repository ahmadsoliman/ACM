package gameClasses;

import java.awt.Color;

import javax.swing.ImageIcon;
import javax.swing.JButton;

@SuppressWarnings("serial")
public class ringButton extends JButton{
	
	
	public ringButton(){
		setBorderPainted(false);
		setContentAreaFilled(false);
		setHideActionText(true);
		setRolloverEnabled(false);
	}
	
	public ringButton(ImageIcon img,ImageIcon selImg, char color){
		super(img);
		setSelectedIcon(selImg);
		setBorderPainted(false);
		setContentAreaFilled(false);
		setHideActionText(true);
		setRolloverEnabled(false);
		setHorizontalTextPosition(CENTER);
		setVerticalTextPosition(CENTER);
		
		if(color=='w')
			setForeground(Color.BLACK);
		else if(color=='b')
			setForeground(Color.WHITE);
		else
			setForeground(Color.GREEN);
	}
	
}
