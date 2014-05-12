package tablesExceptions;

public class IndexOutOfTableBoundsException extends TablesException {
	int index;

	public IndexOutOfTableBoundsException(int index) {
		super();
		this.index = index;
	}

	public String toString() {
		return "The index if the cell being changed: " + this.index
				+ ", is out of the table.";
	}
}
