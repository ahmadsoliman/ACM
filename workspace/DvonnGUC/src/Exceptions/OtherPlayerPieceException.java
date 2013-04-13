package Exceptions;

@SuppressWarnings("serial")
public class OtherPlayerPieceException extends GeneralException{
	public OtherPlayerPieceException(){
		super("This tower is controlled by the other player!");
	}
}
