class Link
{
	public Comparable data;
	public Link next;
	public Link previous;
	
	public void displayLink(){
		System.out.print(data.toString() + " ");
	}
	
	 
	
	public Link(Comparable i)   
    {
    	data = i;          
    } 
	 
	
	public String toString() 
    {
    	return (data+"  ");
    }
}

class DoublyLinkedList
{
	private Link first; // reference to first link on list
	private Link last; // reference to first link on list
	
	public DoublyLinkedList()
	{
		first = null;
		last = null;
	}
	public boolean isEmpty()
	{
		return (first == null);
	}	
	public void insertFirst(Comparable d)
	{
		Link newLink = new Link(d);
		if( isEmpty() ) 
			last = newLink;
		else
			first.previous = newLink; 
		newLink.next = first;
		first = newLink; 
	}
	public void insertLast(Comparable d)
	{
		Link newLink = new Link(d);
		if( isEmpty() ) 
			first = newLink; 
		else
		{
			last.next = newLink;
			newLink.previous = last; 
		}
		last = newLink;
	}
	public Comparable deleteFirst() 
	{ 
		Link temp = first;
		if(first.next == null)
			last = null; 
		else
			first.next.previous = null; 
		first = first.next;
		return temp.data;
	}
	public Comparable deleteLast()
	{ 
		Link temp = last;
		if(first.next == null)
		first = null; 
		else
		last.previous.next = null; 
		last = last.previous; 
		return temp.data;
	}
	public void displayForward()
	{
		Link current = first; 
		while(current != null) 
		{
		current.displayLink();
		current = current.next; 
		}
		System.out.println();
	}
	public void displayBackward()
	{
		Link current = last; 
		while(current != null)
		{
			//current.displayLink(); 
			current = current.previous; 
		}
		System.out.println();
	}
	
	public boolean insertAfter(Comparable k, Comparable dd){
		Link cur = first;
		boolean found = false;
		while(cur!=null){
			if(cur.data.compareTo(k)==0){
				found = true;
				break;
			}
			cur = cur.next;
		}
		if(!found) return false;
		Link temp = new Link(dd);
		temp.next = cur.next;
		temp.previous = cur;
		cur.next = temp;
		temp.next.previous = temp;
		
		return true;
	}
	public boolean insertBefore(Comparable k, Comparable dd){
		Link cur = first;
		boolean found = false;
		while(cur!=null){
			if(cur.data.compareTo(k)==0){
				found = true;
				break;
			}
			cur = cur.next;
		}
		if(!found) return false;
		cur = cur.previous;
		Link temp = new Link(dd);
		temp.next = cur.next;
		temp.previous = cur;
		cur.next = temp;
		temp.next.previous = temp;
		
		return true;
	}
	public Comparable deleteKey(Comparable k){
		Link cur = first;
		boolean found = false;
		while(cur!=null){
			if(cur.data.compareTo(k)==0){
				found = true;
				break;
			}
			cur = cur.next;
		}
		if(!found) return -1;
		Comparable temp = cur.data;
		cur.previous.next = cur.next;
		cur.next.previous = cur.previous;
		
		return temp;
	}
	public void insertToSorted(Comparable x){
		if(first.data.compareTo(x)>0){
			Link temp = new Link(x);
			first.previous = temp;
			temp.next = first;
			first = temp;
			return;
		}
		if(last.data.compareTo(x)<0){
			Link temp = new Link(x);
			last.next = temp;
			temp.previous = last;
			last = temp;
			return;
		}
		Link cur = first.next;
		while(cur!=null){
			if(cur.data.compareTo(x)>=0){
				break;
			}
			cur = cur.next;
		}
		cur = cur.previous;
		Link temp = new Link(x);
		temp.next = cur.next;
		temp.previous = cur;
		cur.next = temp;
		temp.next.previous = temp;
	}
	public void insertionSort(){
		DoublyLinkedList temp = new DoublyLinkedList();
		Link cur = first;
		while(cur!=null){
			temp.insertToSorted(cur.data);
			cur = cur.next;
		}
		Link curT = temp.first;
		first = curT;
		last = curT;
		curT = curT.next;
		while(curT!=null){
			last.next = curT;
			curT.previous = last ;
			last = curT;
			curT = curT.next;
		}
	}
	public void reverse(){
		DoublyLinkedList temp = this;
		Link curT = temp.last.previous;
		first = new Link(temp.last.data);
		Link cur = first;
		last = first;
		while(curT!=null){
			Link t = new Link(curT.data);
			cur.next = t;
			t.previous = cur;
			last = cur;
			cur = cur.next;
			curT = curT.previous;
		}
		
	}
	public void reverseRec(){
		Link temp = first;
		first = last;
		revHelper(first, first.previous);
		last = temp;
	}
	public void revHelper(Link cur,Link prev){
		if(prev==null) return;
		Link temp1 = cur.previous;
		Link temp2 = prev.previous;
		
		cur.next = prev;
		if(cur==first)	cur.previous = null;
		
		if(temp2==null)	prev.next = null;
		revHelper(temp1,temp2);
	}
	
	public DoublyLinkedList weirdDiff(){
		DoublyLinkedList res = new DoublyLinkedList();
		Link cur = first;
		Link curRes=null;
		
		while(cur!=null){
			Link curRight = cur.next;
			Link curLeft = cur.previous;
			int sumRight=0,sumLeft=0;
			while(curRight!=null){
				sumRight+=((Integer)curRight.data).intValue();
				curRight = curRight.next;
			}
			while(curLeft!=null){
				sumLeft+=((Integer)curLeft.data).intValue();
				curLeft = curLeft.previous;
			}
			if(curRes==null)	curRes = res.first = res.last = new Link(sumRight-sumLeft);
			else{
				curRes.next = new Link(sumRight-sumLeft);
				Link prev = curRes;
				curRes = curRes.next;
				curRes.previous = prev;
				res.last = curRes;
			}
			cur=cur.next;
		}
		
		return res;
	}
	
	
	
	
	
	
}