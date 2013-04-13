package eg.edu.guc.voting.facilities;

public abstract class LargeComplex extends VotingStation {
	public LargeComplex()
	{
	}
	public LargeComplex(int capacity)
	{
		super(capacity);
	}
	public abstract int getCapacity();
	public String toString()
	{
		return "capacity =" + capacity + "location =" + getLocation();
	}
		
}
	


