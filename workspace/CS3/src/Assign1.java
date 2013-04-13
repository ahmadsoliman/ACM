//Ahmad Adel Roshdy Soliman
//22-627 T-5
// a)

public class Assign1 {
	
	public static void main(String[] args){
		int[] a = {50,30,20,40};
		for(int k=0;k<a.length;k++) System.out.print(a[k] + " ");
		System.out.println();
		sort(a);
	}
	
	public static void sort(int[] a){
		int i=1;
		while(i<a.length){
			int j=i;
			while(j>0){
				if(a[j]<a[j-1]){
					int temp = a[j];
					a[j] = a[j-1];
					a[j-1] = temp;
					j--;
				}else break;
				
			}
			for(int k=0;k<a.length;k++) System.out.print(a[k] + " ");
			System.out.println();
			i++;
		}
	}
}
// b) Time Complexity: O(n^2)
// c)The invariant of the algorithm is that after each pass the first i elements
//	are partially sorted.