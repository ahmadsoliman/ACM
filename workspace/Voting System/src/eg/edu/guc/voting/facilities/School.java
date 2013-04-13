package eg.edu.guc.voting.facilities;

public class School extends LargeComplex {
	private String name;
	private int numberRooms;

	public School() {
		name = "";
		numberRooms = 0;
	}

	public School(String n, int num) {
		name = n;
		numberRooms = num;
	}

	public int getCapacity() {
		return numberRooms * 6;
	}

	public String toString() {
		return "School " + name + " has " + numberRooms
				+ " rooms. And has a capacity of " + getCapacity();
	}

	protected String getName() {
		return name;
	}

	protected void setName(String name) {
		this.name = name;
	}

	protected int getNumberRooms() {
		return numberRooms;
	}

	protected void setNumberRooms(int numberRooms) {
		this.numberRooms = numberRooms;
	}
}
