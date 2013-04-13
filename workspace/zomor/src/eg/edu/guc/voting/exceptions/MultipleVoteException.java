package eg.edu.guc.voting.exceptions;

import java.io.ObjectInputStream.GetField;

import eg.edu.guc.voting.participants.Person;

public class MultipleVoteException extends VotingException{
	
	public MultipleVoteException (){
		super ("You Have Voted Before.");
	}
	
	public MultipleVoteException(String m){
		super(m);
	}

}
