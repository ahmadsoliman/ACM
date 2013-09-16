package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class OFORTUNE {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine()), initialAmount, years, numberOfOperations, opCharge, maxFund, curFund, interest, curInterest;
		String[] details;
		boolean compound;
		double interestRate;
		
		for (int i = 0; i < t; i++) {
			initialAmount = Integer.parseInt(br.readLine());
			years = Integer.parseInt(br.readLine());
			numberOfOperations = Integer.parseInt(br.readLine());
			
			maxFund = 0;
			
			for (int j = 0; j < numberOfOperations; j++) {
				details = br.readLine().split(" ");
				compound = details[0].equals("1");
				interestRate = Double.parseDouble(details[1]);
				opCharge = Integer.parseInt(details[2]);
				
				interest = 0;
				curFund = initialAmount;
				for (int j2 = 0; j2 < years; j2++) {
					curInterest = (int)(curFund*interestRate);
					if(compound)
						curFund+=curInterest;
					else
						interest+=curInterest;
					curFund-=opCharge;
				}
				if(!compound)
					curFund+=interest;
				if(curFund>maxFund)
					maxFund=curFund;
			}
			System.out.println(maxFund);
		}
	}
}
