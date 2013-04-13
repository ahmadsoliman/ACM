package eg.edu.guc.voting.participants;

import java.util.Calendar;;

public class Person {
	protected String name;
	protected int age;
	protected Calendar birthDate;
	protected String gender;
	protected String socialID;
	public Person(){
		name = "";
		birthDate = Calendar.getInstance();
		calcAge();
		socialID = "";
	}
	public Person(String n, Calendar bD, String id){
		name = n;
		birthDate = bD;
		calcAge();
		socialID = id;
	}
	
	public Person(String n, Calendar bD, String g, String id){
		name = n;
		birthDate = bD;
		calcAge();
		gender = g;
		socialID = id;
	}
	public void calcAge() {
		Calendar rightNow = Calendar.getInstance();
		int diffDays = rightNow.get(Calendar.DAY_OF_MONTH)
			- birthDate.get(Calendar.DAY_OF_MONTH);
		int diffMonths = rightNow.get(Calendar.MONTH)
			- birthDate.get(Calendar.MONTH);
		age = rightNow.get(Calendar.YEAR)
			- birthDate.get(Calendar.YEAR);
		if (diffMonths < 0) {
			age--;
		} else if (diffMonths == 0 && diffDays < 0) {
			age--;
		}
	}
	public int getAge() {
		return age;
	}
	public boolean isEligibleToVote() {
		return false;
	}
	public String toString() {
		return name + " is a " + gender + " " + age
			+ " years old. And Social ID is: " + socialID;
	}
}
