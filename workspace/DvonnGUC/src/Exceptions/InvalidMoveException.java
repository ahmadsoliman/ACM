package Exceptions;

@SuppressWarnings("serial")
public class InvalidMoveException extends GeneralException {
	public InvalidMoveException() {
		super("This move you are trying to take is invalid!");
	}
}
