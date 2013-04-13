import java.util.Random;



public class BTrees {
	public static void main(String[] args){
		BTree t = new BTree();
		t.add(5);t.add(9);t.add(8);t.add(2);t.add(4);t.add(6);t.add(7);
		
//		BTree t2 = new BTree();
//		t2.add(5);t2.add(3);t2.add(7);t2.add(2);t2.add(4);t2.add(6);t2.add(8);t2.add(1);t2.add(0);
//		
		int[] x = new int[8];
		x[0] = 5; x[1] = 2; x[2] = 7; x[3] = 6; x[4] = 3; x[5] = 8; x[6] = 4; x[7] = 1;
		t = topology(x);
//		
//		t.displayTree();
//		t = doubleValues(t);
		t.displayTree();
		
		t.mirror();
		t.displayTree();
	}
	
	public static Comparable max(BTree t){
		if(t.root==null) return -1;
		return maxHelper(t.root,t.root.data);
	}
	public static Comparable maxHelper(Node n, Comparable max){
		if(n==null) return max;
		if(n.data.compareTo(max)>0) max = n.data;
		int x = (Integer)maxHelper(n.left, max);
		int y = (Integer)maxHelper(n.right, max);
		if(x>y) return x;
		else return y;
	}
	
	public static boolean equal(BTree t1, BTree t2){
		Node n1=t1.root , n2=t2.root ;
		return eqHelper(n1,n2);
	}
	public static boolean eqHelper(Node n1, Node n2){
		if(n1==null&&n2==null) return true;
		else if(n1==null||n2==null) return false;
		if(n1.data.compareTo(n2.data)!=0) return false;
		return (eqHelper(n1.left,n2.left)&&eqHelper(n1.right,n2.right)); 
	}
	
	
	public static BTree doubleValues(BTree t){
		BTree res = new BTree();
		helper(t.root, res);
		return res;
	}
	
	public static void helper(Node n, BTree t){
		if(n==null) return;
		t.add(2*(Integer)n.data);
		helper(n.left, t);
		helper(n.right, t);
	}
	
	
	
	
	
	
	
	
	
	public static BTree topology(int[] x){
		java.util.Arrays.sort(x);
		BTree res = new BTree();
		topHelper(x, 0, x.length-1, res);
		return res;
	}
	
	public static void topHelper(int[] x, int l, int h, BTree t){
		if(l>h) return;
		int m = (l+h+1)/2;
		t.add(x[m]);
		if(l!=h){
			topHelper(x,l,m-1,t);
			topHelper(x,m+1,h,t);
		}
	}
	
}
