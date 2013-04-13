import java.awt.*;
import java.util.Random;

import javax.swing.*;


public class test extends JFrame {
	

	public static void main(String [] args){
		int[][] tri;
		 tri = new int[10][];  // allocate array of rows
		 
		 Random rand = new Random();
		 for (int r=0; r<1000; r++) {
			 System.out.println(rand.nextInt(10));

		 }
		 
		 // print the triangular array (same as above really)
//		 for (int r=0; r<tri.length; r++) {
//		     for (int c=0; c<tri[r].length; c++) {
//		         System.out.print(" " + tri[r][c]);
//		     }
//		  }
		
		
		//new test("LOL!!");
	
	}
	
	public test (String txt){
		JLabel jlbl1 = new JLabel(txt);
		
		this.getContentPane().add(jlbl1, BorderLayout.CENTER);
		
		
		
		this.setTitle("TEST");
		this.setSize(500,500);
		this.setLocation(150,150);
		setVisible(true);
	}

}
