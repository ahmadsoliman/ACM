
public class Sorting_PA2 {
	public static void main(String[] args){
		int[] a1 = {9,8,6,5,4,7,2,3,1,0};
		int[] res = shakerSort(a1);
		for(int i=0;i<res.length;i++){
			System.out.print(res[i] + " ");
		}
	}
	
	public static int[] oddEven(int[] a){
		
		
		return a;
	}
	
	public static int[] shakerSort(int[] a){
		for(int i=0; i<a.length/2; i++){
			
			for(int j=0; j<a.length-1; j++){
				if(a[j]>a[j+1]){
					int temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
				if(a[a.length-1-j]<a[a.length-2-j]){
					int temp = a[a.length-1-j];
					a[a.length-1-j] = a[a.length-2-j];
					a[a.length-2-j] = temp;
				}
			}
			
		}
		
		return a;
	}
	
	public static int[] swap(int[] a){
		for(int i=0; i<Math.ceil(a.length/2.0); i++){
			for(int j=0; j<a.length-1; j+=2){
				if(a[j]>a[j+1]){
					int temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
			}
			for(int j=1; j<a.length-1; j+=2){
				if(a[j]>a[j+1]){
					int temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
			}
		}
		
		return a;
	}
	
	
	public static int[] selection(int[] a){
		if(a.length<=1) return a;
		
		for(int i=0;i<a.length/2;i++){
			int max=a[i],min=a[i],imax=i,imin=i;
			
			for(int j=i;j<a.length-i;j++){
				if(a[j]<min){
					min = a[j];
					imin=j;
				}
				if(a[j]>max){
					max = a[j];
					imax=j;
				}
			}
			
			if(a[i]==max) imax=imin;
			if(imin!=i){
				int temp = a[i];
				a[i] = min;
				a[imin] = temp;
			}
			if(imax!=a.length-1-i){
				int temp = a[a.length-1-i];
				a[a.length-1-i] = max;
				a[imax] = temp;
			}
		}
		
		return a;
	}
	
	
}
