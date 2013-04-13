package eg.edu.guc.voting.exceptions;

@SuppressWarnings("serial")
public class VotableNotFoundException extends VotingException {
	public VotableNotFoundException() {
		super();
	}

	public String getMessage() {
		return "The entity ,the vote is given to, is not present.";
	}
}
