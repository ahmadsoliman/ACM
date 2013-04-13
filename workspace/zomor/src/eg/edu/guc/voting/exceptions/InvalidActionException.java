package eg.edu.guc.voting.exceptions;

public class InvalidActionException extends Exception {
	String error;
	public InvalidActionException(){
		
	}
	
	public InvalidActionException(String c){
		error= c;
	}

}
