package eg.edu.guc.voting.facilities;

public class Booth extends SmallSetup {
	private String address;
	public Booth()
	{
		
	}
	public Booth(String address)
	{
		super();
		this.address = address;
		this.capacity = 1;
	}
	public int getCapacity()
	{
		return capacity;
	}
	public String toString()
	{
		return "Booth capacity =" + getCapacity() + " Booth address = " + address;
		
	}
	

}
