import javax.swing.*; 
import java.awt.event.*;
public class FirstSwingDemo 
{
    	public static void main(String[] args) 
{
        	JFrame myWindow = new JFrame();
        	myWindow.setSize(400,100); 
                JLabel myLabel = new JLabel("My first window");
                myWindow.getContentPane().add(myLabel);
                myLabel.setAlignmentX(100);
                myLabel.setAlignmentY(100);
                
                WindowDestroyer myListener = new WindowDestroyer();
                myWindow.addWindowListener(myListener);
                myWindow.setVisible(true);
}

}
