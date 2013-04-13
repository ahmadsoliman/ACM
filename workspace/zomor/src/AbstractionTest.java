import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.lang.reflect.Modifier;

import org.junit.Test;

import eg.edu.guc.voting.facilities.Booth;
import eg.edu.guc.voting.facilities.LargeComplex;
import eg.edu.guc.voting.facilities.School;
import eg.edu.guc.voting.facilities.SmallSetup;
import eg.edu.guc.voting.facilities.Stadium;
import eg.edu.guc.voting.facilities.Tent;
import eg.edu.guc.voting.facilities.VotingStation;
import eg.edu.guc.voting.participants.Candidate;
import eg.edu.guc.voting.participants.Civilian;
import eg.edu.guc.voting.participants.Farmer;
import eg.edu.guc.voting.participants.Independent;
import eg.edu.guc.voting.participants.Officer;
import eg.edu.guc.voting.participants.Party;
import eg.edu.guc.voting.participants.Person;
import eg.edu.guc.voting.participants.Worker;

public class AbstractionTest {
	@Test(timeout = 1000)
	public void testPersonAbstraction() {
		assertTrue("Class Person MUST be declared as abstract",
				Modifier.isAbstract(Person.class.getModifiers()));
	}
	
	@Test(timeout = 1000)
	public void testOfficerAbstraction() {
		assertFalse("Class Officer MUST NOT be declared as abstract",
				Modifier.isAbstract(Officer.class.getModifiers()));
	}
	
	@Test(timeout = 1000)
	public void testOfCivilianAbstraction() {
		assertFalse("Class Civilian MUST NOT be declared as abstract",
				Modifier.isAbstract(Civilian.class.getModifiers()));
	}
	
	@Test(timeout = 1000)
	public void testOfVotingStationAbstraction() {
		assertTrue("Class VotingStation MUST be declared as abstract",
				Modifier.isAbstract(VotingStation.class.getModifiers()));
	}

	@Test(timeout = 1000)
	public void testOfLargeComplexAbstraction() {
		assertTrue("Class LargeComplex MUST be declared as abstract",
				Modifier.isAbstract(LargeComplex.class.getModifiers()));
	}
	
	@Test(timeout = 1000)
	public void testOfSchoolAbstraction() {
		assertFalse("Class School MUST NOT be declared as abstract",
				Modifier.isAbstract(School.class.getModifiers()));
	}
	
	@Test(timeout = 1000)
	public void testOfStadiumAbstraction() {
		assertFalse("Class Stadium MUST NOT be declared as abstract",
				Modifier.isAbstract(Stadium.class.getModifiers()));
	}
	
	@Test(timeout = 1000)
	public void testOfSmallSetupAbstraction() {
		assertTrue("Class SmallSetup MUST be declared as abstract",
				Modifier.isAbstract(SmallSetup.class.getModifiers()));
	}
	
	@Test(timeout = 1000)
	public void testOfBoothAbstraction() {
		assertFalse("Class Booth MUST NOT be declared as abstract",
				Modifier.isAbstract(Booth.class.getModifiers()));
	}
	
	@Test(timeout = 1000)
	public void testOfTentAbstraction() {
		assertFalse("Class Tent MUST NOT be declared as abstract",
				Modifier.isAbstract(Tent.class.getModifiers()));
	}
	
	@Test(timeout = 1000)
	public void testOfCandidateAbstraction() {
		assertTrue("Class Candidate MUST be declared as abstract",
				Modifier.isAbstract(Candidate.class.getModifiers()));
	}
	
	@Test(timeout = 1000)
	public void testOfIndependentAbstraction() {
		assertFalse("Class Independent MUST be declared as abstract",
				Modifier.isAbstract(Independent.class.getModifiers()));
	}
	
	@Test(timeout = 1000)
	public void testOfFarmerAbstraction() {
		assertFalse("Class Farmer MUST be declared as abstract",
				Modifier.isAbstract(Farmer.class.getModifiers()));
	}
	
	@Test(timeout = 1000)
	public void testOfWorkerAbstraction() {
		assertFalse("Class Worker MUST be declared as abstract",
				Modifier.isAbstract(Worker.class.getModifiers()));
	}
	

	
	@Test(timeout = 1000)
	public void testOfPartyAbstraction() {
		assertFalse("Class Party MUST be declared as abstract",
				Modifier.isAbstract(Party.class.getModifiers()));
	}
}
