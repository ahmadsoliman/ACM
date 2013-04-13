package topCoder;

public class SRM568 {
	public static void main(String[] args) {
		
	}
	
	public static int find(int lower, int upper){
		int countMax=0, curCount, curLower;
		for (int i = lower; i < upper; i++) {
			curCount=0;
			curLower=i;
			while(curLower<upper){
				curLower=curLower*10+1;
				if(curLower<=upper)
					curCount++;
			}
			if(curCount>countMax)
				countMax=curCount;
		}
		return countMax+1;
	}
	
	public static int minOperations(int[] red, int[] green, int[] blue){
		int min=0,boxesCount=red.length;
		
		if(boxesCount<3){
			int countR=0, countG=0, countB=0;
			for (int i = 0; i < boxesCount; i++) {
				countR+=red[i];
				countG+=green[i];
				countB+=blue[i];
			}
			if(boxesCount==2 && countR>0 && countG>0 && countB>0){
				return -1;
			}
			if(boxesCount==1 && ((countR>0 && countG>0) || (countR>0 && countB>0) || (countB>0 && countG>0))){
				return -1;
			}
			if(boxesCount==0 && (countR>0 || countG>0 || countB>0)){
				return -1;
			}
		}
		
		int redMax=maxArray(red), greenMax=maxArray(green), blueMax=maxArray(blue) , totalR=0, totalG=0, totalB=0;
		for (int i = 0; i < boxesCount; i++) {
			totalR+=red[i];
			totalG+=green[i];
			totalB+=blue[i];
		}
		
		if(redMax==greenMax&&redMax==blueMax){
			if(1.0*red[redMax]/totalR > 1.0*green[greenMax]/totalG){
				if(1.0*red[redMax]/totalR > 1.0*blue[blueMax]/totalG){//red
					int greenMin=minArray(green, -1), blueMin=minArray(blue, -1);
					if(greenMin==blueMin){
						if(1.0*green[greenMax]/totalG > 1.0*blue[blueMax]/totalB){//green
							blueMin=minArray(blue, greenMin);
						}else{
							greenMin=minArray(green, blueMin);
						}
					}
					for (int i = 0; i < boxesCount; i++) {
						if(i!=redMax)min+=red[i];
						if(i!=greenMin)min+=green[i];
						if(i!=blueMin)min+=blue[i];
					}
				}else{//blue
					int greenMin=minArray(green, -1), redMin=minArray(red, -1);
					if(greenMin==redMin){
						if(1.0*green[greenMax]/totalG > 1.0*red[redMax]/totalR){//green
							redMin=minArray(blue, greenMin);
						}else{
							greenMin=minArray(green, redMin);
						}
					}
					for (int i = 0; i < boxesCount; i++) {
						if(i!=redMin)min+=red[i];
						if(i!=greenMin)min+=green[i];
						if(i!=blueMax)min+=blue[i];
					}
				}
			}else{
				if(1.0*green[greenMax]/totalG > 1.0*blue[blueMax]/totalB){//green
					int redMin=minArray(green, -1), blueMin=minArray(blue, -1);
					if(redMin==blueMin){
						if(1.0*red[redMax]/totalR > 1.0*blue[blueMax]/totalB){//green
							blueMin=minArray(blue, redMin);
						}else{
							redMin=minArray(green, blueMin);
						}
					}
					for (int i = 0; i < boxesCount; i++) {
						if(i!=redMin)min+=red[i];
						if(i!=greenMax)min+=green[i];
						if(i!=blueMin)min+=blue[i];
					}
				}else{//blue
					int greenMin=minArray(green, -1), redMin=minArray(red, -1);
					if(greenMin==redMin){
						if(1.0*green[greenMax]/totalG > 1.0*red[redMax]/totalR){//green
							redMin=minArray(blue, greenMin);
						}else{
							greenMin=minArray(green, redMin);
						}
					}
					for (int i = 0; i < boxesCount; i++) {
						if(i!=redMin)min+=red[i];
						if(i!=greenMin)min+=green[i];
						if(i!=blueMax)min+=blue[i];
					}
				}
			}
		}else if(redMax==greenMax){
			if(1.0*red[redMax]/totalR > 1.0*green[greenMax]/totalG){
				int greenMin = minArray(green, blueMax);
				for (int i = 0; i < boxesCount; i++) {
					if(i!=redMax)min+=red[i];
					if(i!=greenMin)min+=green[i];
					if(i!=blueMax)min+=blue[i];
				}
			}else{
				int redMin = minArray(red, blueMax);
				for (int i = 0; i < boxesCount; i++) {
					if(i!=redMin)min+=red[i];
					if(i!=greenMax)min+=green[i];
					if(i!=blueMax)min+=blue[i];
				}
			}
		}else if(redMax==blueMax){
			if(1.0*red[redMax]/totalR > 1.0*blue[blueMax]/totalB){
				int blueMin = minArray(blue, greenMax);
				for (int i = 0; i < boxesCount; i++) {
					if(i!=redMax)min+=red[i];
					if(i!=greenMax)min+=green[i];
					if(i!=blueMin)min+=blue[i];
				}
			}else{
				int redMin = minArray(red, greenMax);
				for (int i = 0; i < boxesCount; i++) {
					if(i!=redMin)min+=red[i];
					if(i!=greenMax)min+=green[i];
					if(i!=blueMax)min+=blue[i];
				}
			}
		}else if(greenMax==blueMax){
			if(1.0*blue[blueMax]/totalB > 1.0*green[greenMax]/totalG){
				int greenMin = minArray(green, redMax);
				for (int i = 0; i < boxesCount; i++) {
					if(i!=redMax)min+=red[i];
					if(i!=greenMin)min+=green[i];
					if(i!=blueMax)min+=blue[i];
				}
			}else{
				int blueMin = minArray(blue, redMax);
				for (int i = 0; i < boxesCount; i++) {
					if(i!=redMax)min+=red[i];
					if(i!=greenMax)min+=green[i];
					if(i!=blueMin)min+=blue[i];
				}
			}
		}else{
			for (int i = 0; i < boxesCount; i++) {
				if(i!=redMax)
					min+=red[i];
			}
			for (int i = 0; i < boxesCount; i++) {
				if(i!=greenMax)
					min+=green[i];
			}
			for (int i = 0; i < boxesCount; i++) {
				if(i!=blueMax)
					min+=blue[i];
			}
		}
				
		return min;		
	}
	public static int maxArray(int[] arr){
		int max=0, maxI=0;
		for (int i = 0; i < arr.length; i++) {
			if(arr[i]>max){
				max=arr[i];
				maxI=i;
			}
		}
		return maxI;
	}
	public static int minArray(int[] arr, int notI){
		int min=Integer.MAX_VALUE, minI=0;
		for (int i = 0; i < arr.length; i++) {
			if(arr[i]<min&&i!=notI){
				min=arr[i];
				minI=i;
			}
		}
		return minI;
	}
}
