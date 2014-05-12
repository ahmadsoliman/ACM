package tablesExceptions;

public class NonPositiveHeightException extends TablesException {
	int value;

	public NonPositiveHeightException(int value) {
		super();
		this.value = value;
	}

	public String toString() {
		return "The height: " + this.value
				+ " is not a positive value.";
	}
}
