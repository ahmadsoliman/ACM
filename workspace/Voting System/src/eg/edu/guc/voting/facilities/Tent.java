package eg.edu.guc.voting.facilities;

public class Tent extends SmallSetup {
	private String address;

	public Tent() {
		super();
		address = "";
	}

	public Tent(String a) {
		super();
		address = a;
	}

	public int getCapacity() {
		return 5;
	}

	public String toString() {
		return "Tent at the a " + address + " has a capacity of "
				+ getCapacity();
	}

	protected String getAddress() {
		return address;
	}

	protected void setAddress(String address) {
		this.address = address;
	}
}
