import java.util.Calendar;

import org.junit.Before;
import org.junit.Test;

import eg.edu.guc.voting.participants.Civilian;
import eg.edu.guc.voting.participants.Officer;
import eg.edu.guc.voting.participants.Person;
import static org.junit.Assert.*;

public class PersonTest {

	private Calendar officerBirth, civilianBirth;

	@Before
	public void setup() {
		officerBirth = Calendar.getInstance();
		officerBirth.add(Calendar.YEAR, -41);
		civilianBirth = Calendar.getInstance();
		civilianBirth.add(Calendar.YEAR, -23);
	}

	@Test(timeout = 1000)
	public void hasOfficerConstructor() {
		new Officer("123456789", "officer name", officerBirth, "Major");
	}

	@Test(timeout = 1000)
	public void hasCivilianConstructor() {
		new Civilian("123456789", "name", civilianBirth, "Mr.");
	}

	@Test(timeout = 1000)
	public void testHierarchyOfPeople() {
		Officer officer = new Officer("123456789", "officer name",
				officerBirth, "Major");
		Civilian civilian = new Civilian("123456789", "name", civilianBirth,
				"Mr.");
		assertTrue("Officer must be a subclass of Person",
				officer instanceof Person);
		assertTrue("Civilian must be a subclass of Person",
				civilian instanceof Person);
	}

	@Test(timeout = 1000)
	public void testGetOfficerAge() {
		Officer officer = new Officer("123456789", "officer name",
				officerBirth, "Major");
		assertEquals(41, officer.getAge());
	}

	@Test(timeout = 1000)
	public void testGetCivilianAge() {
		Civilian civilian = new Civilian("123456789", "name", civilianBirth,
				"Mr.");
		assertEquals(23, civilian.getAge());
	}

	@Test(timeout = 1000)
	public void testVotingEligibilityOfficer() {
		Officer officer = new Officer("123456789", "officer name",
				officerBirth, "Major");
		assertFalse("All Officers are not allowed to vote",
				officer.isEligibleToVote());
	}

	@Test(timeout = 1000)
	public void testVotingEligibilityCivilian() {
		Civilian civilian = new Civilian("123456789", "name", civilianBirth,
				"Mr.");
		assertTrue("Civilians older than 18 are elligible",
				civilian.isEligibleToVote());
	}

	@Test(timeout = 1000)
	public void testVotingEligibilityYoungCivilian() {
		Civilian civilian = new Civilian("123456789", "name",
				Calendar.getInstance(), "");
		assertFalse("Civilians younger than 18 are NOT elligible",
				civilian.isEligibleToVote());
	}

	@Test(timeout = 1000)
	public void testOfficerToString() {
		Officer officer = new Officer("123456789", "officer name",
				officerBirth, "Major");
		String s = officer.toString().toLowerCase();
		assertTrue(s.startsWith("major"));
		assertTrue(s.contains("officer name"));
		assertTrue("String representation of office should contain the age",
				s.contains("41"));
	}

	@Test(timeout = 1000)
	public void testCivilianToString() {
		Civilian civilian = new Civilian("123456789", "name", civilianBirth,
				"Mr.");
		String s = civilian.toString().toLowerCase();
		assertTrue(s.startsWith("mr."));
		assertTrue(s.contains("name"));
		assertTrue("String representation of civilian should contain the age",
				s.contains("23"));
	}
}
