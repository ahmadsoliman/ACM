package eg.edu.guc.voting.participants;

import java.util.Calendar;

public abstract class Person {
	private String name;
	private int age;
	private Calendar birthDate;
	private String gender;
	private String socialID;

	public String getName() {
		return name;
	}

	public void setName(String n) {
		name = n;
	}

	public String getGender() {
		return gender;
	}

	public void setGender(String g) {
		gender = g;
	}

	public String getSocialID() {
		return socialID;
	}

	public void setSocialID(String id) {
		socialID = id;
	}

	public Calendar getBirthDate() {
		return birthDate;
	}

	public void setBirthDate(Calendar bd) {
		birthDate = bd;
	}

	public void setAge(int a) {
		age = a;
	}

	public int getAge() {
		return age;
	}

	public Person() {
		name = "";
		birthDate = Calendar.getInstance();
		calcAge();
		socialID = "";
	}

	public Person(String n, Calendar bD, String id) {
		name = n;
		birthDate = bD;
		calcAge();
		socialID = id;
	}

	public Person(String n, Calendar bD, String g, String id) {
		name = n;
		birthDate = bD;
		calcAge();
		gender = g;
		socialID = id;
	}

	private void calcAge() {
		Calendar rightNow = Calendar.getInstance();
		int diffDays = rightNow.get(Calendar.DAY_OF_MONTH)
				- birthDate.get(Calendar.DAY_OF_MONTH);
		int diffMonths = rightNow.get(Calendar.MONTH)
				- birthDate.get(Calendar.MONTH);
		age = rightNow.get(Calendar.YEAR) - birthDate.get(Calendar.YEAR);
		
		if (diffMonths < 0) {
			age--;
		} else if (diffMonths == 0 && diffDays < 0) {
			age--;
		}
	}

	public abstract boolean isEligibleToVote();

	public abstract String toString();

}
