import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertEquals;

import java.util.Calendar;

import org.junit.Before;
import org.junit.Test;

import eg.edu.guc.voting.participants.Civilian;
import eg.edu.guc.voting.participants.Party;

public class PartyTest {
	
	private Civilian c1, c2;
	
	@Before
	public void setup() {
		Calendar birthDate = Calendar.getInstance();
		birthDate.add(Calendar.YEAR, -23);
		c1 = new Civilian("123456789", "name", birthDate, "Mr.");
		c2 = new Civilian("1234", "name2", birthDate, "Mrs.");
	}
	
	@Test(timeout = 1000)
	public void hasPartyConstructor() {
		new Party("TestingParty");
	}
	
	@Test(timeout = 1000)
	public void testCountMembers() {
		Party p1 = new Party("TestingParty");
		assertEquals("Initially a party should have 0 memebers",
				0, p1.countMembers());
		p1.addMember(c1);
		assertEquals("Adding a memeber should affect memeber count by 1",
				1, p1.countMembers());
		p1.addMember(c1);
		assertEquals("Adding the same member again should not affect the number of party memebers",
				1, p1.countMembers());
	}
	
	@Test(timeout = 1000)
	public void testIsMemeber() { 
		Party p1 = new Party("TestingParty");
		assertFalse("The party has no memebers yet",
				p1.isMember(c1));
		p1.addMember(c1);
		assertTrue(c1 + " should be a memeber of the party", 
				p1.isMember(c1));
		assertFalse(c2 + " should NOT be a memeber of the party", 
				p1.isMember(c2));
	}
	
	@Test(timeout = 1000)
	public void testToString() {
		Party p1 = new Party("TestingParty");
		String s  =  p1.toString().toLowerCase();
		assertTrue("should have party name", s.contains("testingparty"));
		assertTrue("should have number of party members", s.contains("0"));
	}
	
	@Test(timeout = 1000)
	public void testEquality() {
		Party p1 = new Party("TestingParty");
		assertTrue(p1.equals(p1));
		
		Party p2 = new Party("TestingParty2");
		assertFalse("Parties with different number of members should be NOT equal",
				p1.equals(p2));
		
		Party p3 = new Party("TestingParty");
		p3.addMember(c1);
		assertFalse("Parties with different number of members should be NOT equal", 
				p1.equals(p3));
		
		Party p4 = new Party("TestingParty");
		assertTrue(p4.equals(p4));
	}
}
