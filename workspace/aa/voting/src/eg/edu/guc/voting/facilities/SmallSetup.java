package eg.edu.guc.voting.facilities;

public abstract class SmallSetup extends VotingStation  {
	public SmallSetup()
	{
	}
	public SmallSetup(int capacity)
	{
		super(capacity);
	}
	public abstract int getCapacity();
	public String toString()
	{
		return "capacity =" + capacity + "location =" + location;
	}
}
