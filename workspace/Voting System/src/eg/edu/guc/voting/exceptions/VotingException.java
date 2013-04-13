package eg.edu.guc.voting.exceptions;

@SuppressWarnings("serial")
public class VotingException extends InvalidActionException {
	public VotingException() {
		super();
	}

	public VotingException(String err) {
		super(err);
	}

}
