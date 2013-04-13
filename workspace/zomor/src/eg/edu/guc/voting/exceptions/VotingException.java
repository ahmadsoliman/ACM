package eg.edu.guc.voting.exceptions;

public class VotingException extends InvalidActionException {
	
	
	public VotingException(){
		
	}
	
	public VotingException(String m){
		super(m);
	}

}
