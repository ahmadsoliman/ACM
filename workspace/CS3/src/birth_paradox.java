import java.util.Random ;

public class birth_paradox {
	public static void main(String [] args){
		Random generator = new Random();
		double lim = 100000.0;
		for(int i=5; i <= 100; i+=5){
			int count =0;
			int[] BDs = new int[i];
			for(int k=0; k<lim; k++){
				for(int j=0; j<i; j++){
					BDs[j] = generator.nextInt(365);				
				}
				if(check(BDs)) count++;
			}
			
			double prob = count/lim;
			System.out.println("The probability is: " + prob + " when n is equal to " + i);
		}
	}
	
	public static boolean check(int[] a){
		for(int i=0; i<a.length; i++){
			for(int j=0; j<a.length; j++){
				if(a[i]==a[j] && i!=j){
					return true;
				}
			}
		}
		return false;
	}
}
