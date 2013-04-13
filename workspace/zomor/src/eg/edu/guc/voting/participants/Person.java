package eg.edu.guc.voting.participants;

import java.util.Calendar;

abstract public class Person {

	private String Name;
	private Calendar BirthDate;
	private String ID;
	private int Age;

	public Person() {
		Name = "";
		BirthDate = Calendar.getInstance();
		ID = "";
		Age = 0;

	}

	public Person(String name, Calendar birthday, String id) {
		Name = name;
		BirthDate = birthday;
		ID = id;
		Age = getAge();

	}

	public int getAge() {
		Calendar now = Calendar.getInstance();
		int year = now.get(Calendar.YEAR) - BirthDate.get(Calendar.YEAR);
		int month = now.get(Calendar.MONTH) - BirthDate.get(Calendar.MONTH);
		int day = now.get(Calendar.DAY_OF_MONTH)
				- BirthDate.get(Calendar.DAY_OF_MONTH);

		if (month > 0)
			return year;
		else if (month == 0) {
			if (day < 0)
				year = year - 1;
		}
		return year;

	}

	public boolean isEligibleToVote() {
		return false;
	}

	public String toString() {
		return "Name : " + getName() + "Birthday :" + getBirthDate() + "ID :"
				+ getID();
	}

	public String getName() {
		return Name;
	}

	public void setName(String name) {
		Name = name;
	}

	public Calendar getBirthDate() {
		return BirthDate;
	}

	public void setBirthDate(Calendar birthDate) {
		BirthDate = birthDate;
	}

	public String getID() {
		return ID;
	}

	public void setID(String iD) {
		ID = iD;
	}

	public void setAge(int age) {
		Age = age;
	}

}
