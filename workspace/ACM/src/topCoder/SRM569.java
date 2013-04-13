package topCoder;

public class SRM569 {
	
	public int countSupervisors(int[] students, int Y, int J){
		
		int count, minCount=Integer.MAX_VALUE;
		for (int i = 0; i < students.length ; i++) {
			count =0;
			for (int k = 0; k < students.length; k++) {
				if(i==k){
					count += Math.ceil(1.0*(((students[k]-Y)>0)?students[k]-Y:0)/J);
				}else{
					count += Math.ceil(1.0*students[k]/J);
				}
			}
			if(count<minCount)minCount=count;
		}
		
		return minCount;
	}
	
}
