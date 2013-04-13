package eg.edu.guc.voting.exceptions;

@SuppressWarnings("serial")
public class MultipleVoteException extends VotingException {
	public MultipleVoteException() {
		super();
	}

	public String getMessage() {
		return "This person had voted before.";
	}
}
