package eg.edu.guc.voting.facilities;

public class Stadium extends LargeComplex {
	private String name;
	
	public Stadium()
	{
		
	}
	public Stadium(String name)
	{
		super();
		this.name = name;
		this.capacity = 40;
	}
	
	public int getCapacity()
	{
		return capacity;
	}
	public String toString()
	{
		return "Stadium name :" + name + "Stadium max number =:" + getCapacity();
		
	}

}
