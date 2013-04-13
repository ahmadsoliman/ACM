
public class QueueStacks {
	private int maxsize;
	private int nItems;
	private StackObj elements;
	
	public QueueStacks(int s) 
	{
		maxsize = s;
		nItems = 0;
		elements = new StackObj(maxsize);
	}
	
	public void enqueue(Object x)
	{
		StackObj temp = new StackObj(nItems);
		while(!elements.isEmpty())		temp.push(elements.pop());
		elements.push(x);
		while(!temp.isEmpty())		elements.push(temp.pop());
		nItems++;
	}
	
	public Object dequeue()
	{
		nItems--;
		return elements.pop();
	}
	
	public Object peek()
	{
		return elements.top();
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
