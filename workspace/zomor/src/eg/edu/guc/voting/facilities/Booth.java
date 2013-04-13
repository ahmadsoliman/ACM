package eg.edu.guc.voting.facilities;

public class Booth extends SmallSetup {

	private String Name;
	private int Capacity;

	public Booth(String name) {
		Name = name;
		Capacity = 1;
	}

	public int getCapacity() {
		return Capacity;
	}

	public void setCapacity(int capacity) {
		Capacity = capacity;
	}

	public void setCapacity() {
		setCapacity(1);

	}

	public String toString() {
		return "Booth : " + getName() + "Address : " + getAddress()
				+ "Capacity : " + getCapacity() + "Type : " + getType()
				+ "Sub Type : " + getSubType();
	}

	public void setName(String name) {
		Name = getName();
	}

	public String getName() {
		return Name;
	}

}
