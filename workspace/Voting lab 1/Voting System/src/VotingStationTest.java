import org.junit.Test;

import eg.edu.guc.voting.facilities.Booth;
import eg.edu.guc.voting.facilities.LargeComplex;
import eg.edu.guc.voting.facilities.School;
import eg.edu.guc.voting.facilities.SmallSetup;
import eg.edu.guc.voting.facilities.Stadium;
import eg.edu.guc.voting.facilities.Tent;
import eg.edu.guc.voting.facilities.VotingStation;
import static org.junit.Assert.*;

public class VotingStationTest {

	@Test(timeout = 1000)
	public void hasSchoolConstructor() {
		new School("School Name", 20);
	}

	@Test(timeout = 1000)
	public void hasStadiumConstructor() {
		new Stadium("Stadium Name");
	}

	@Test(timeout = 1000)
	public void hasBoothConstructor() {
		new Booth("Booth Address");
	}

	@Test(timeout = 1000)
	public void hasTentConstructor() {
		new Tent("Tent Address");
	}

	@Test(timeout = 1000)
	public void testHierarchyOfStations() {
		School school = new School("School Name", 20);
		assertTrue("School must be subclass of VotingStation",
				school instanceof VotingStation);
		assertTrue("School must be subclass of LargeComplex",
				school instanceof LargeComplex);

		Stadium stadium = new Stadium("Stadium Name");
		assertTrue("Stadium must be subclass of VotingStation",
				stadium instanceof VotingStation);
		assertTrue("Stadium must be subclass of LargeComplex",
				stadium instanceof LargeComplex);

		Tent tent = new Tent("Tent Address");
		assertTrue("Tent must be subclass of VotingStation",
				tent instanceof VotingStation);
		assertTrue("Tent must be subclass of LargeComplex",
				tent instanceof SmallSetup);

		Booth booth = new Booth("Booth Address");
		assertTrue("Booth must be subclass of VotingStation",
				booth instanceof VotingStation);
		assertTrue("Booth must be subclass of LargeComplex",
				booth instanceof SmallSetup);
	}

	@Test(timeout = 1000)
	public void testSchoolCapcity() {
		assertEquals(120, new School("School Name", 20).getCapacity());
	}

	@Test(timeout = 1000)
	public void testStadiumCapcity() {
		assertEquals(40, new Stadium("Stadium Name").getCapacity());
	}

	@Test(timeout = 1000)
	public void testTentCapcity() {
		assertEquals(5, new Tent("Tent Address").getCapacity());
	}

	@Test(timeout = 1000)
	public void testBoothCapcity() {
		assertEquals(1, new Booth("Booth Address").getCapacity());
	}

	@Test(timeout = 1000)
	public void testSchoolToString() {
		School school = new School("School Name", 20);
		String s = school.toString().toLowerCase();
		assertTrue(s.startsWith("school"));
		assertTrue(s.contains("school name"));
	}

	@Test(timeout = 1000)
	public void testStadiumToString() {
		Stadium stadium = new Stadium("Stadium Name");
		String s = stadium.toString().toLowerCase();
		assertTrue(s.startsWith("stadium"));
		assertTrue(s.contains("stadium name"));
	}

	@Test(timeout = 1000)
	public void testTentToString() {
		Tent tent = new Tent("Tent Address");
		String s = tent.toString().toLowerCase();
		assertTrue(s.startsWith("tent"));
		assertTrue(s.contains("tent address"));
	}

	@Test(timeout = 1000)
	public void testBoothToString() {
		Booth booth = new Booth("Booth Address");
		String s = booth.toString().toLowerCase();
		assertTrue(s.startsWith("booth"));
		assertTrue(s.contains("booth address"));
	}
}
