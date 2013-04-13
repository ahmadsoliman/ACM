package eg.edu.guc.voting.participants;

import java.util.Calendar;

public class Officer extends Person {
	private String id; 
	private String fullname;
	
	private String rank;
	
	
	
	public Officer(String id, String fullname , Calendar birthDate , String rank) {
		Calendar rightNow = Calendar.getInstance();
		this.age = rightNow.get(Calendar.YEAR) - birthDate.get(Calendar.YEAR);
		this.rank = rank;
		this.fullname = fullname;
		this.id = id;
		
	}
	public boolean isEligibleToVote() {
	return false;
	}
	public String toString() {
		return  rank + "id :" + id + "age :" + age + "full name :" + fullname;
		
		
		
	}

}
