package eg.edu.guc.voting.facilities;

public class Tent extends SmallSetup {
	protected String address;
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
		return "Tent at the address " + address + " has a capacity of "
			+ getCapacity();
	}
}
