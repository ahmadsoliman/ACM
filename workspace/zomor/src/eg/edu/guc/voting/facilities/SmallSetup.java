package eg.edu.guc.voting.facilities;

abstract public class SmallSetup extends VotingStation {
	private String SubType;

	public SmallSetup(String subtype) {
		SubType = subtype;
	}

	public SmallSetup() {
		super();
		SubType = "";

	}

	public String toString() {
		return "Address : " + getAddress() + "Capacity : " + getCapacity()
				+ "Type : " + getType() + "Sub Type : " + getSubType();
	}

	public void setSubType(String SubType) {
		SubType = getSubType();
	}

	public String getSubType() {
		return SubType;
	}

}
