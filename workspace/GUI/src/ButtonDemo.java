import javax.swing.*; 
import java.awt.*;
import java.awt.event.*;
public class ButtonDemo extends JFrame implements ActionListener
{

    public static void main(String[] args) 
    { ButtonDemo buttonGUI = new ButtonDemo();
	buttonGUI.setVisible(true);
    }

        	
    public ButtonDemo()
{
    super();
    setSize(400,100); 
    getContentPane().setLayout(new FlowLayout());
    JButton button1 = new JButton("Red");
    button1.addActionListener(this);
    getContentPane().add(button1);
    JButton button2 = new JButton("Black");
    button2.addActionListener(this);
    getContentPane().add(button2);
    setTitle("Second Window");
    getContentPane().setBackground(Color.YELLOW);
    WindowDestroyer myListener = new WindowDestroyer();
    addWindowListener(myListener);
}

    public void actionPerformed(ActionEvent e)
    { 
	if (e.getActionCommand().equals("Red"))
            getContentPane().setBackground(Color.MAGENTA);
        else if (e.getActionCommand().equals("Black"))
            getContentPane().setBackground(Color.BLACK);
    }

}
