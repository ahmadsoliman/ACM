package eg.edu.guc.voting.facilities;

public class Booth extends SmallSetup {
	private String address;

	public Booth() {
		super();
		address = "";
	}

	public Booth(String a) {
		super();
		address = a;
	}

	public int getCapacity() {
		return 1;
	}

	public String toString() {
		return "Booth at the a " + address + " has a capacity of "
				+ getCapacity();
	}

	protected String getAddress() {
		return address;
	}

	protected void setAddress(String address) {
		this.address = address;
	}
}
