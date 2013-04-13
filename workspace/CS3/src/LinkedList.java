public class LinkedList {
    private Link head;	// reference to the head of the list

    // constructor
    public LinkedList () {
		head = null;
    }

    public boolean isEmpty () {
		return (head == null);
    }

    public void insertFirst (Comparable o) {
		Link newLink = new Link (o);
		newLink.next = head;
		head = newLink;
    }

    public Comparable removeFirst () {
		Link temp = head;
		head = head.next;
		return temp.data;
    }

    public void insertLast (Comparable o) {

        Link newLink = new Link (o);
        Link current = head;


        if(current != null)
        {
                while(current.next != null)
                        current = current.next;

                current.next = newLink;

        }
        else
                head = newLink;
}

    public Comparable removeLast (){
        Link current = head;
        Link prev        = current;

        if (head == null)
        {
                return null;
        }
        else if (head.next == null)
        {
                Comparable item = head.data;
                head = null;
                return item;
        }

        else
        {
                while(current.next != null)
                {
                        prev    = current;
                        current = current.next;
                }

                prev.next    = null;
                Comparable item = current.data;
                current     = null;

                return item;
        }

    }
    
    public void reverse(){
    	LinkedList temp = new LinkedList();
    	while(head != null){
    		temp.insertLast(this.removeLast());
    	}
    	this.head = temp.head;
    }
    
    public LinkedList merge(LinkedList l){
    	LinkedList res = new LinkedList();
    	res.head = new Link(this.head.data) ;
    	Link curR = res.head;
    	
    	Link curT = this.head.next;
    	Link curL = l.head;
    	while(curT!=null){
    		Link temp = new Link(curT.data); 
    		curR.next = temp;
    		curR = curR.next;
    		curT = curT.next;
    	}
    	while(curL!=null){
    		Link temp = new Link(curL.data); 
    		curR.next = temp;
    		curR = curR.next;
    		curL = curL.next;
    	}
    	return res;
    }
    
    public boolean equal(LinkedList l){
    	Link curT = this.head;
    	Link curL = l.head;
    	int countT =0;
    	int countL = 0;
    	while(curT!=null){
    		boolean found = false;
    		countL = 0;
    		while(curL!=null){
    			if(curT.data.compareTo(curL.data) == 0) found = true;
    			curL = curL.next;
    			countL++;
    		}
    		countT++;
    		if(!found) return false;
    		curL = l.head;
    		curT = curT.next;
    	}
    	if(countT != countL) return false;
    	return true;
    }
    
    public LinkedList intersection(LinkedList l){
    	LinkedList res = new LinkedList();
    	Link curR = res.head;
    	Link curT = this.head;
    	Link curL = l.head;
    	
    	while(curT!=null){
    		while(curL!=null){
    			if(curT.data.compareTo(curL.data) == 0){
    				Link temp = new Link(curT.data); 
    	    		if(res.head==null) {
    	    			res.head = temp;
    	    			curR = res.head;
    	    		}else	{
    	    			curR.next = temp;
    	    			curR = curR.next;
    	    		}
    	    		break;
    			}
    			curL = curL.next;
    			
    		}
    		curL = l.head;
    		curT = curT.next;
    	}
    	return res;
    }	
    
    
    public LinkedList union(LinkedList l){
    	LinkedList res = new LinkedList();
    	Link curR = res.head;
    	Link curT = this.head;
    	Link curL = l.head;
    	
    	while(curL!=null){
    		Link temp = new Link(curL.data); 
    		if(res.head==null) {
    			res.head = temp;
    			curR = res.head;
    		}else	{
    			curR.next = temp;
    			curR = curR.next;
    		}
    		curL = curL.next;
    	}
    	curL = l.head;
    	while(curT!=null){
    		boolean found = false;
    		while(curL!=null){
    			if(curT.data.compareTo(curL.data) == 0){
    				found = true;
    	    		break;
    			}
    			curL = curL.next;
    		}
    		if(!found){
    			Link temp = new Link(curT.data); 
	    		if(res.head==null) {
	    			res.head = temp;
	    			curR = res.head;
	    		}else	{
	    			curR.next = temp;
	    			curR = curR.next;
	    		}
    		}
    		curL = l.head;
    		curT = curT.next;
    	}
    	
    	
    	return res;
    }
    
    public LinkedList difference(LinkedList l){
    	LinkedList res = new LinkedList();
    	Link curR = res.head;
    	Link curT = this.head;
    	Link curL = l.head;
    	
    	while(curT!=null && curL!=null){
    		Link temp = new Link((Integer)curT.data-(Integer)curL.data);
    		if(curR==null){
    			res.head = temp;
    			curR = res.head;
    		}else {
    			curR.next = temp;
    			curR = curR.next;
    		}
    		curT = curT.next;
    		curL = curL.next;
    	}
    	
    	return res;
    }
    
    public String toString () {
		String result = new String ();
		Link current = head;
		while (current != null) {
	    	result += "item: " + current + "\n";
	    	current = current.next;
		}
		return result;
    }

}

