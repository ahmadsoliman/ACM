package eg.edu.guc.voting.participants;
import java.util.Calendar;
public class Civilian extends Person {
	private String id;
	private String fullName;
	private String title;
	public Civilian(String id , String fullName , Calendar birthDate , String title) {
		Calendar rightNow = Calendar.getInstance();
		this.age = rightNow.get(Calendar.YEAR) - birthDate.get(Calendar.YEAR);
		this.title = title;
		this.id = id;
		this.fullName = fullName;
		this.age = rightNow.get(Calendar.YEAR) - birthDate.get(Calendar.YEAR);
		
		
		
		
	}
	public boolean isEligibleToVote() {
		if (this.age >= 18)
		{
			return true;
		}
		
		else
		{
			return false;
		}
		
		
	}
	public String toString()
	{
		return title + "name :" + fullName + "age:" + age + "id:" + id + isEligibleToVote();  
	}
	

}
