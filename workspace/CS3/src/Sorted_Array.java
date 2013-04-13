
public class Sorted_Array {
	int[] array;
	int nItems;
	
	public Sorted_Array(){
		array = new int[100];
		nItems =0;
		
	}
	
	public void orderedInsert(int x){
		if(nItems==array.length) return;
		if(nItems==0){
			array[0]=x;
			nItems++;
			return;
		}
		int index = nItems;
		for(int i=0; i<nItems ; i++){
			if(x<array[i]){
				for(int j=nItems; j>=i ; j--){
					array[j+1] = array[j];
				}
				index = i;
				break;
			}
		}
		array[index] = x;
		nItems++;
	}
	
	public int binarySearchIter(int x){
		int l=0 , u=nItems-1;
		int index;
		while(true){
			index =(u+l)/2;
			if(array[index]==x){
				return index;
			}
			else if(l > u){
				return -1;			
			}
			else {
				if(array[index] < x)
					l = index +1;
				else
					u = index -1;
			}
		}
	}
	
	public int binarySearchRec(int x){
		if(nItems==0) return -1;
		return helper(x,0,nItems-1);
	}
	public int helper(int x, int i, int j){
		int index = (i+j)/2;
		if(i>j) return -1;
		if(array[index]==x) return index;
		if(array[index]<x) return helper(x,index+1 , j);
		return helper(x,i,index-1); 		
	}
	
	public void delete(int x){
		do{
			int index = binarySearchIter(x);
			if(index==-1) return;
			for(int i=index;i<nItems-1;i++){
				array[i] = array[i+1];
			}
			nItems--;
		}while(true);
	}
	public static void main(String[] args){
		Sorted_Array a1 = new Sorted_Array();
		a1.orderedInsert(2);a1.orderedInsert(4);a1.orderedInsert(6);
		a1.orderedInsert(3);a1.orderedInsert(8);a1.orderedInsert(6);
		
		a1.delete(3);
		for(int i=0; i<a1.nItems ; i++){
			System.out.println(a1.array[i]);
		}
		
		
		System.out.println();
		System.out.println(a1.binarySearchIter(6));
		System.out.println(a1.binarySearchIter(6));
		
	}
}
