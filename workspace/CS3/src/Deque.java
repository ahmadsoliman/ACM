
public class Deque {
	private int maxsize;
	private int front;
	private int rear;
	private int nItems;
	private Object [] elements;
	
	public Deque(int s) 
	{
		maxsize = s;
		front = 1;
		rear = -1;
		nItems = 0;
		elements = new Object[maxsize];
	}
	
	public void insertFirst(Object x)
	{
		if(front == 0)
			front = maxsize;
		if(rear==-1) rear =0;
		elements[--front] = x;
		nItems++;
	}
	public void insertLast(Object x)
	{
		if(rear == maxsize - 1)
			rear = -1;
		if(front == 1) front =0;
		
		elements[++rear] = x;
		nItems++;
	}
	
	public Object removeFirst()
	{
		Object result = elements[front];
		front++;
		
		if(front == maxsize)
			front = 0;
			
		nItems--;
		return result;
	}
	public Object removeLast()
	{
		Object result = elements[rear];
		rear--;
		if(rear==-1) rear = maxsize -1; 
		
		nItems--;
		return result;
	}
	
	public Object peekFront()
	{
		return elements[front];
	}
	public Object peekRear()
	{
		return elements[rear];
	}
	
	
	public boolean isEmpty()
	{
		return (nItems == 0);
	}
	
	public boolean isFull()
	{
		return (nItems == maxsize);
	}
	
	public int size()
	{
		return nItems;
	}
}
