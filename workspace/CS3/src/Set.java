import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;


public class Set<E> {
	private ArrayList<E> myArray;
	
	public Set(){
		myArray = new ArrayList<E>();
	}
	
	public Set(E[] input){
		myArray = new ArrayList<E>(input.length);
		for (int i = 0; i < input.length; i++) {
			if(!myArray.contains(input[i])) myArray.add(input[i]);
		}
	}
	
	public void add(E item){
		if(!myArray.contains(item))
			myArray.add(item);
	}
	
	public boolean belongsTo(E item){
		return myArray.contains(item);
	}
	
	public boolean subset(Set<E> s){
		for (E item : s.myArray) {
			if(!this.myArray.contains(item)) return false;
		}
		return true;
	}
	
	public Set<E> intersection(Set<E> s){
		Set<E> res = new Set<E>();
		for (E item : s.myArray) {
			if(s.myArray.contains(item))
				res.add(item);
		}
		return res;
	}
	
	public Set<E> union(Set<E> s){
		Set<E> res = new Set<E>();
		for (E item : myArray) {
			res.add(item);
		}
		for (E item : s.myArray) {
			res.add(item);
		}
		return res;
	}
	
	public Set<E> difference(Set<E> s){
		Set<E> res = new Set<E>();
		for (E item : myArray) {
			if(!s.myArray.contains(item))
				res.add(item);
		}
		return res;
	}
	
	public String toString() {
		StringBuffer str = new StringBuffer();
		for (E item : myArray) {
			str.append(item.toString());
			str.append(",");
		}
		str.deleteCharAt(str.length()-1);
		return str.toString();
	}
	
	public static void main(String[] args) {
		Set<Integer> s = new Set<Integer>(new Integer[]{1,2,4,3,5,6,7,8,11});
		Set<Integer> s1 = new Set<Integer>(new Integer[]{2,4,6,8,10});
		
		System.out.println(s);
		System.out.println(s1.difference(s));
	}
}
