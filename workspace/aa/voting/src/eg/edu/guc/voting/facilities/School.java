package eg.edu.guc.voting.facilities;

public class School extends LargeComplex {
	private String name;
	private int numberRooms;
	public School()
	{
		
	}
	public School(String name, int numberRooms)
	{
		super();
		this.name = name;
		this.numberRooms = numberRooms;
	}
	public int getCapacity()
	{
		int max = numberRooms * 6;
		return max;
	}
	public String toString()
	{
		return "School Name is : " + name + "number of rooms" + numberRooms + "maxCapacity :" 
		+ getCapacity();
		
	}

}
