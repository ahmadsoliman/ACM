package eg.edu.guc.voting.facilities;

public class School extends LargeComplex {
	protected String name;
	protected int numberRooms;
	public School() {
		super();
		name = "";
	}
	public School(String n, int num) {
		super();
		name = n;
		numberRooms = num;
	}
	public School(int c,String n, int num) {
		super(c);
		name = n;
		numberRooms = num;
	}
	public int getCapacity() {
		return 6 * numberRooms;
	}
	public String toString() {
		return "School " + name + " has " + numberRooms
			+ " rooms. And has a capacity of " + getCapacity();
	}
}
