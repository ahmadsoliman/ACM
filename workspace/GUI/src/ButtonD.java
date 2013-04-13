import javax.swing.*; 
import java.awt.*;
public class ButtonD extends JFrame 
{

    public static void main(String[] args) 
    { ButtonD buttonGUI = new ButtonD();
	buttonGUI.setVisible(true);
    }

        	
    public ButtonD()
{
    super();
    setSize(400,100); 
    getContentPane().setLayout(new FlowLayout());
    JButton button1 = new JButton("Red");
    getContentPane().add(button1);
    JButton button2 = new JButton("Black");
    getContentPane().add(button2);
    setTitle("Second Window");
    getContentPane().setBackground(Color.BLUE);
    WindowDestroyer myListener = new WindowDestroyer();
    addWindowListener(myListener);
}

   

}
