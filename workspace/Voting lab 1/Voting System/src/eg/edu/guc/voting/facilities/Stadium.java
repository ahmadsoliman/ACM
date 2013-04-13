package eg.edu.guc.voting.facilities;

public class Stadium extends LargeComplex {
	protected String Name;
	public Stadium() {
		super();
	}
	public Stadium(String name) {
		super();
		Name = name;
	}
	public Stadium(int c,String name) {
		super(c);
		Name = name;
	}
	public int getCapacity() {
		return 40;
	}
	public String toString() {
		return "Stadium " + Name + " has a capacity of "
			+ getCapacity();
	}
}
