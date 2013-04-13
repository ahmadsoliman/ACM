package eg.edu.guc.voting.facilities;

abstract public class LargeComplex extends VotingStation {
	private String SubType;

	public LargeComplex() {
		super();
		SubType = "";
	}

	public LargeComplex(String subtype) {
		SubType = subtype;

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
