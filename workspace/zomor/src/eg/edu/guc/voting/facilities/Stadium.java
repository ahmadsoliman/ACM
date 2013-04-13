package eg.edu.guc.voting.facilities;

public class Stadium extends LargeComplex {

	private String Name;
	private int Capacity;

	public int getCapacity() {
		return Capacity;
	}

	public void setCapacity(int capacity) {
		Capacity = capacity;
	}

	public Stadium(String name) {
		Name = name;
		Capacity = 40;
	}

	public String toString() {
		return "Stadium : " + getName() + "Address : " + getAddress()
				+ "Capacity : " + getCapacity() + "Type : " + getType()
				+ "Sub Type : " + getSubType();
	}

	public String getName() {
		return Name;
	}

	public void setName(String name) {
		Name = name;
	}

}
