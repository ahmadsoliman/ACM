package eg.edu.guc.voting.facilities;

public class Tent extends SmallSetup {
	private String address;
	public Tent()
	{
		
	}
	public Tent(String address)
	{
		super();
		this.address = address;
		this.capacity = 5;
	}
	public int getCapacity()
	{
		return capacity;
	}
	public String toString()
	{
		return "Tent capacity =" + getCapacity()   + " Tent address = " + address;
		
	}
	

}
