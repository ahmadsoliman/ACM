package eg.edu.guc.voting.exceptions;

@SuppressWarnings("serial")
public class InvalidActionException extends Exception {
	public InvalidActionException() {
		super();
	}

	public InvalidActionException(String err) {
		super(err);
	}
}
