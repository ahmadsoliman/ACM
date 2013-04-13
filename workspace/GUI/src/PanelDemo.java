import javax.swing.*; 
import java.awt.*;
import java.awt.event.*;
public class PanelDemo extends JFrame implements ActionListener
{

    public static void main(String[] args) 
    { PanelDemo buttonGUI = new PanelDemo();
	buttonGUI.setVisible(true);
    }

        	
    public PanelDemo()
{
    super();
    setSize(400,100); 
    WindowDestroyer myListener = new WindowDestroyer();
    addWindowListener(myListener);
    Container contentPane = getContentPane();
    contentPane.setBackground(Color.BLUE);
    contentPane.setLayout(new BorderLayout());
    
    JPanel buttonPanel = new JPanel();
    buttonPanel.setBackground(Color.WHITE);

    buttonPanel.setLayout(new FlowLayout());
    
    JButton button1 = new JButton("Red");
    button1.setBackground(Color.RED);
    button1.addActionListener(this);
    buttonPanel.add(button1);
    JButton button2 = new JButton("MAGENTA");
    button2.setActionCommand("Magenta"); 
    button2.setBackground(Color.MAGENTA);
    button2.addActionListener(this);
    buttonPanel.add(button2);

    contentPane.add(buttonPanel, BorderLayout.SOUTH);

    setTitle("Second Window");
   
    
}

    public void actionPerformed(ActionEvent e)
    {   
	if (e.getActionCommand().equals("Red"))
            getContentPane().setBackground(Color.RED);
        else if (e.getActionCommand().equals("Magenta"))
            getContentPane().setBackground(Color.MAGENTA);
    }

}
