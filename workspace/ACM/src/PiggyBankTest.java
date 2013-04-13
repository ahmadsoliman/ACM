import static org.junit.Assert.assertTrue;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.junit.runners.Parameterized.Parameters;

@RunWith(Parameterized.class)
public class PiggyBankTest {
	private int[] changeIntervals;
	private int q;
	private int m;
	private int correctOutput;
	private String testCaseIn;
	
	public PiggyBankTest(int[] changeIntervals, int q, int m, int correctOutput, String testCaseIn)
	{
		this.changeIntervals= changeIntervals;
		this.q= q;
		this.m= m;
		this.correctOutput= correctOutput;
		this.testCaseIn= testCaseIn;
	}

	@Parameters
	public static Collection<Object[]> generateData()
	{
		ArrayList<Object[]> testCases= new ArrayList<Object[]>();
		try{
			 FileInputStream fstreamIn1 = new FileInputStream("in.txt");
			 FileInputStream fstreamIn2 = new FileInputStream("out.txt");
			 
			 DataInputStream in = new DataInputStream(fstreamIn1);
			 DataInputStream out = new DataInputStream(fstreamIn2);
			  
			 BufferedReader brIn = new BufferedReader(new InputStreamReader(in));
			 BufferedReader brOut = new BufferedReader(new InputStreamReader(out));

			 String testCaseIn;
			 String testCaseOut;
			 while ((testCaseIn = brIn.readLine()) != null)   {
				 testCaseOut= brOut.readLine();
				 
				 Object[] inParsed= parseInput(testCaseIn);
				 int [] changeIntervals= (int[])inParsed[0];
				 int q= (Integer)inParsed[1];
				 int m= (Integer)inParsed[2];
				 int correctOutput= Integer.parseInt(testCaseOut);
				 testCases.add(new Object[] {changeIntervals, q, m, correctOutput, testCaseIn});
			 }
		}
		catch (Exception e) {
			e.printStackTrace();
		}
		return testCases;
	}

	@Test
	public void checkTestCase()
	{
		PiggyBank c= new PiggyBank();
		String result= c.getMaxAmount(changeIntervals, q, m);
		int maxResult= Integer.parseInt(result.split(",")[0]);
		assertTrue("Case "+testCaseIn+": maximum saving should be "+ correctOutput + " not "+maxResult, maxResult==correctOutput);
		
		if(correctOutput!=-1)
		{
			//backtrack: sequence of operations
			String backtrack= result.split(",")[1];

			//check backtrack contains only the characters '+' and '-'
			String remaining= (backtrack.replace("+", "")).replace("-", "");
			assertTrue("Backtracking contains invalid characters", remaining.length()==0);
			
			//check backtrack is correct
			int value=q;
			for(int i=0; i<backtrack.length(); i++)
			{
				value = (backtrack.charAt(i)=='+') ? value+changeIntervals[i] : value-changeIntervals[i];
			}
			assertTrue("Case "+testCaseIn+": backtracking is incorrect",value==correctOutput);
		}
	}
	
	private static Object[] parseInput(String in)
	{
		Object[] out= new Object[3];

		in=in.replace(" ", "");
		in=in.replace("{", "");
		in=in.replace("}", "");
		String[] temp= in.split(",");
		int[] changeIntervals= new int [temp.length-2];
		for(int i=0; i<changeIntervals.length; i++)
			changeIntervals[i]=Integer.parseInt(temp[i]);
		out[0]= changeIntervals;
		out[1]= Integer.parseInt(temp[temp.length-2]);	//q
		out[2]= Integer.parseInt(temp[temp.length-1]);	//m
		
		return out;
	}
}
