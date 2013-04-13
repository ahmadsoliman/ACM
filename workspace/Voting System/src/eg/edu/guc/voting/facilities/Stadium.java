package eg.edu.guc.voting.facilities;

public class Stadium extends LargeComplex {
	private String name;

	public Stadium() {
		name = "";
	}

	public Stadium(String n) {
		name = n;
	}

	public int getCapacity() {
		return 40;
	}

	public String toString() {
		return "Stadium " + name + " has a capacity of " + getCapacity();
	}

	protected String getName() {
		return name;
	}

	protected void setName(String name) {
		this.name = name;
	}
}
