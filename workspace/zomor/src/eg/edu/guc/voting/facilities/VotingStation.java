package eg.edu.guc.voting.facilities;

abstract public class VotingStation {

	protected int Capacity;
	private String address;
	private String Type;

	public VotingStation() {
		Capacity = 0;
		address = "";
		Type = "";
	}

	public VotingStation(int capacity, String add, String type) {
		Capacity = capacity;
		address = add;
		Type = type;
	}

	public int getCapacity() {
		return Capacity;

	}

	public void setCapacity(int Capacity) {
		Capacity = getCapacity();
	}

	public String toString() {
		return "Address : " + address + "Capacity : " + Capacity + "Type : "
				+ Type;
	}

	public String getAddress() {
		return address;
	}

	public void setAddress(String address) {
		address = getAddress();
	}

	public void setType(String Type) {
		Type = getType();
	}

	public String getType() {
		return Type;
	}

}
