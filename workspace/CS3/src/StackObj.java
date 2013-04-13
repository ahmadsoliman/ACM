class StackObj
{
  private Object[] theStack;
  private int maxSize;	
  private int top;

  public StackObj(int s)
  {
    maxSize = s;
    theStack = new Object[maxSize];
    top = -1;
  }	
  public void push(Object elem)
  {
  	top++;
    theStack[top] = elem;
  }
  public Object pop()
  {
  	Object result = theStack[top];
  	top--;
    return result;
  }
  public Object top()
  {
    return theStack[top];
  }
  public boolean isFull()
  {
    return (top == (maxSize-1) );
  }
  public boolean isEmpty()
  {
    return (top == -1);
  }
  public int size() 
  {
    return (top+1);
  }
}