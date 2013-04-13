//Ahmad Adel Roshdy Soliman
//22-627 T-5
// a)

public class Assign1_Modified {
	
	public static void main(String[] args){
		int[] a = {9,8,7,6,5,4,3,2,1,0};
		for(int k=0;k<a.length;k++) System.out.print(a[k] + " ");
		System.out.println();
		sort(a);
	}
	
	public static void sort(int[] a){
		int i =1;
		int tempI =i;
		int l =0;
		while(i<a.length){
			if(i>0 && a[i]<a[i-1]){
				int temp = a[i];
				a[i] = a[i-1];
				a[i-1] = temp;
				i--;
			}
			else{
				i = ++tempI;
				for(int k=0;k<a.length;k++) System.out.print(a[k] + " ");
				System.out.println();
			}
			l++;
		}
		System.out.println( l );
	}
	
}
//b) Time Complexity: O(n^2)
//c)The invariant of the algorithm is that after each pass the first i elements
//  are in their correct position.
