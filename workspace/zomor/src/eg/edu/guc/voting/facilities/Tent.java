package eg.edu.guc.voting.facilities;

public class Tent extends SmallSetup {

	private String Name;
	private int Capacity;

	public Tent(String name) {
		Name = name;
		Capacity = 5;
	}

	public String getName() {
		return Name;
	}

	public void setName(String name) {
		Name = name;
	}

	public int getCapacity() {
		return Capacity;
	}

	public void setCapacity(int capacity) {
		Capacity = capacity;
	}

	public String toString() {
		return "Tent : " + Name + "Address : " + getAddress() + "Capacity : "
				+ getCapacity() + "Type : " + getType() + "Sub Type : "
				+ getSubType();
	}

}
