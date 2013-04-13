
public class LinkedLists {
	public static void main(String [] args){
		LinkedList l1 = new LinkedList();
		LinkedList l2 = new LinkedList();
//		l1.insertLast(1);l1.insertLast(2);l1.insertLast(3);l1.insertLast(3);
//		l1.insertLast(5);l1.insertLast(7);l1.insertLast(7);l1.insertLast(15);
		
		for(int i=1; i<5; i++){
			l1.insertLast(i);
		}
		for(int i=1; i<5; i++){
			l2.insertFirst(i);
		}
		
//		LinkedList merged = l1.merge(l2);
		
//		l1.reverse();
//		l1 = reverse(l1);
//		l1 = removeDuplicates(l1);
//		l1 = cut(l1);
//		frontBackSplit(l1);
//		alternatingSplit(l1);
		
		
		
		System.out.println(l1.difference(l2));
	}
	
	public static int max(LinkedList l){
		if(l.isEmpty()) return -1;
		int max = ((Integer)l.removeFirst()).intValue();
		while(!l.isEmpty()) {
			int current =((Integer)l.removeFirst()).intValue();;
			if(current>max) max = current ;
		}
		return max;
		
	}
	
	public static void alternatingSplit(LinkedList l){
		LinkedList temp1 = new LinkedList();
		for(int i=0; i<countItr(l); i++){
			Comparable o = l.removeFirst();
			temp1.insertLast(o);
			l.insertLast(o);
		}
		
		LinkedList sublist1 = new LinkedList();
		LinkedList sublist2 = new LinkedList();
		int half = countItr(l)/2;
		
		while(!temp1.isEmpty()) {
			sublist1.insertLast(temp1.removeFirst());
			if(!temp1.isEmpty())sublist2.insertLast(temp1.removeFirst());
		}
		
		System.out.println("sublist1:\n" + sublist1.toString() + "sublist2: ");
		System.out.println(sublist2.toString());
		
	}
	
	public static void frontBackSplit(LinkedList l){
		LinkedList temp1 = new LinkedList();
		for(int i=0; i<countItr(l); i++){
			Comparable o = l.removeFirst();
			temp1.insertLast(o);
			l.insertLast(o);
		}
		
		LinkedList front = new LinkedList();
		LinkedList back = new LinkedList();
		int half = countItr(l)/2;
		
		for(int i=0; i<half; i++) back.insertFirst(temp1.removeLast());
		while(!temp1.isEmpty()) front.insertLast(temp1.removeFirst());
		
		System.out.println("Front:\n" + front.toString() + "Back: ");
		System.out.println(back.toString());
		
	}
	
	public static LinkedList cut(LinkedList l){
		LinkedList temp = new LinkedList();
		LinkedList temp2 = new LinkedList();
		if(l.isEmpty()) return temp;
		while(!l.isEmpty()){
			Comparable o = l.removeFirst();
			temp.insertLast(o);
			temp2.insertLast(o);
		}
		int half = countItr(temp)/2;
		for(int i=0; i<half ; i++)		temp.insertLast(temp2.removeLast());
		temp = reverse(temp);
		while(!temp2.isEmpty())		 temp.insertLast(temp2.removeFirst());
		return temp;
	}
	
	public static int countRec(LinkedList l){
		if(l.isEmpty()) return 0;
		l.removeLast();
		return 1 + countRec(l);
	}
	public static int countItr(LinkedList l){
		LinkedList temp1 = new LinkedList();
		LinkedList temp2 = new LinkedList();
		while(!l.isEmpty()){
			Comparable o = l.removeFirst();
			temp1.insertLast(o);
			temp2.insertLast(o);
		}
		while(!temp2.isEmpty()) l.insertLast(temp2.removeFirst());
		if(temp1.isEmpty()) return 0;
		int count=0;
		while(!temp1.isEmpty()){
			temp1.removeLast();
			count++;
		}
		return count;
	}
	
	public static LinkedList removeDuplicates(LinkedList l){
		LinkedList temp = new LinkedList();
		int last = ((Integer)l.removeFirst()).intValue();
		temp.insertLast(last);
    	while(!l.isEmpty()){
    		int current = ((Integer)l.removeFirst()).intValue();
    		if(current!=last){
    			temp.insertLast(current);
    			last = current;
    		}
    	}
		return temp;
	}
	
	public static LinkedList reverse(LinkedList l){
		LinkedList temp = new LinkedList();
    	while(!l.isEmpty()){
    		temp.insertLast(l.removeLast());
    	}
		return temp;
	}
	
	
}
