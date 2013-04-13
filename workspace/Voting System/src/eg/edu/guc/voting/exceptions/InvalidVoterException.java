package eg.edu.guc.voting.exceptions;

@SuppressWarnings("serial")
public class InvalidVoterException extends VotingException {
	public InvalidVoterException() {
		super();
	}

	public String getMessage() {
		return "This person is not eligible to vote.";
	}
}
