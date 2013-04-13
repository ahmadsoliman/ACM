public class Node
{
	public Comparable data;
	public Node right;
	public Node left;
	
	public Node(Comparable data)
	{
		this(data,null,null);	
	}
	
	public Node(Comparable data, Node left, Node right)
	{
		this.data = data;
		this.left = left;
		this.right = right;
	}
}

