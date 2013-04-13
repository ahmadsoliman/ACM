package eg.edu.guc.voting.participants;

public class Person {
	protected int age;
	private boolean eligible;
	private String information;
	public Person() 
	{
		
	}
	public Person(int a , boolean e , String i)
	{
		this.age = a;
		this.eligible = e;
		this.information = i;
	}
	public int getAge() {
		return age;
	}
	public boolean isEligibleToVote()
	{
		return eligible;
	}
	public String toString()
	{
		return "name :" + information + "age :" + age + "EligibleToVote" + eligible;
		
	}
	
	

}
