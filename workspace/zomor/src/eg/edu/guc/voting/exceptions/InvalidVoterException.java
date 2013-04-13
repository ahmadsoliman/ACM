package eg.edu.guc.voting.exceptions;

public class InvalidVoterException extends VotingException{
	
	public InvalidVoterException (){
		super("You are not Eligible to Vote.");
	}

	public InvalidVoterException(String m ){
		super(m);
	}
}
