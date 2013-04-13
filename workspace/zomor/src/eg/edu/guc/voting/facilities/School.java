package eg.edu.guc.voting.facilities;

public class School extends LargeComplex {
	private String Name;
	private int Rooms;
	private int Capacity;

	public int getCapacity() {
		return Capacity;
	}

	public void setCapacity(int capacity) {
		Capacity = capacity;
	}

	public School(String name, int numberRooms) {
		Name = name;
		Rooms = numberRooms;
		Capacity = 6 * Rooms;
	}

	public School() {
		super();
		Name = "";
		Rooms = 0;
		Capacity = 0;
	}

	public void setCapacity() {
		setCapacity(6 * this.getRooms());
	}

	public String toString() {
		return "School : " + Name + "Address : " + getAddress() + "Capacity : "
				+ getCapacity() + "Type : " + getType() + "Sub Type : "
				+ getSubType();
	}

	public String getName() {
		return Name;
	}

	public void setName(String name) {
		Name = name;
	}

	public int getRooms() {
		return Rooms;
	}

	public void setRooms(int rooms) {
		Rooms = rooms;
	}

}
