import javax.swing.*; 
import java.awt.*;
public class ThirdWindow extends JFrame {
    public ThirdWindow() {
      super();
      setSize(400,100); 
      getContentPane().setLayout(new BorderLayout());
      JLabel label1 = new JLabel("My name is");
      getContentPane().add(label1, BorderLayout.NORTH);
      JLabel label2 = new JLabel("Slim");
      getContentPane().add(label2, BorderLayout.CENTER);
      setTitle("Second Window");
      getContentPane().setBackground(Color.BLUE);
      WindowDestroyer myListener = new WindowDestroyer();
      addWindowListener(myListener); } 


    public static void main(String[] args)  { 
       ThirdWindow window = new ThirdWindow();
       window.setVisible(true); }

}