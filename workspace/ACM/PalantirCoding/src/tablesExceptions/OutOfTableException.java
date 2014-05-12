package tablesExceptions;

public class OutOfTableException extends TablesException {
	int point;

	public OutOfTableException(int point) {
		super();
		this.point = point;
	}

	public String toString() {
		return "The point being queried: " + this.point
				+ ", is out of the table.";
	}

}
