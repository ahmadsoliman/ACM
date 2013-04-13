import static org.junit.Assert.assertEquals;

import java.util.ArrayList;
import java.util.Calendar;

import org.junit.Test;

import eg.edu.guc.voting.Election;
import eg.edu.guc.voting.exceptions.InvalidActionException;
import eg.edu.guc.voting.participants.Civilian;
import eg.edu.guc.voting.participants.Farmer;
import eg.edu.guc.voting.participants.Independent;
import eg.edu.guc.voting.participants.Party;
import eg.edu.guc.voting.participants.Person;
import eg.edu.guc.voting.participants.Votable;

public class ElectionTest {

	@Test(timeout = 1000)
	public void hasElectionConstuctor() {
		new Election("Parliment", new ArrayList<Person>());
	}

	@Test(timeout = 1000)
	public void initialPartiesCount() {
		Election e = new Election("Parliment", new ArrayList<Person>());
		assertEquals(0, e.countParties());
	}

	@Test(timeout = 1000)
	public void initialCandidatesCount() {
		Election e = new Election("Parliment", new ArrayList<Person>());
		assertEquals(0, e.countCandidates());
	}

	@Test(timeout = 1000)
	public void testAddingCandidate() {
		Election e = new Election("Parliment", new ArrayList<Person>());
		Calendar date = Calendar.getInstance();
		date.set(1988, 6, 2);
		Votable candidate = new Independent("3712545394888",
				"Sarai Gusikowski", date, "Mr");
		e.addVotable(candidate);
		assertEquals(1, e.countCandidates());
	}

	@Test(timeout = 1000)
	public void testAddingParty() {
		Election e = new Election("Parliment", new ArrayList<Person>());
		Votable party = new Party("test party");
		e.addVotable(party);
		assertEquals(1, e.countParties());
	}

	@Test(timeout = 1000)
	public void testAddingDuplicates() {
		Election e = new Election("Parliment", new ArrayList<Person>());
		Votable party = new Party("test party");
		e.addVotable(party);
		e.addVotable(party);
		assertEquals("Adding the same votable twice should not affect count",
				1, e.countParties());
	}

	@Test(timeout = 1000)
	public void testIntialVoteCount() {
		Election e = new Election("Parliment", new ArrayList<Person>());
		Votable party = new Party("test party");
		e.addVotable(party);
		Calendar date = Calendar.getInstance();
		date.set(1988, 6, 2);
		Votable candidate = new Independent("3712545394888",
				"Sarai Gusikowski", date, "Mr");
		e.addVotable(candidate);

		assertEquals(0, e.countVotes(party));
		assertEquals(0, e.countVotes(candidate));
	}

	@Test(timeout = 1000)
	public void testVoteCount() throws InvalidActionException {
		Calendar date = Calendar.getInstance();
		date.set(1988, 6, 2);
		ArrayList<Person> people = new ArrayList<Person>();
		Person voter = new Civilian("8054248738", "Brice Ryan", date, "Mrs");
		people.add(voter);
		Election e = new Election("Parliment", people);
		Votable party = new Party("test party");
		e.addVotable(party);
		Votable candidate = new Independent("3712545394888",
				"Sarai Gusikowski", date, "Mr");
		e.addVotable(candidate);

		e.vote("8054248738", "test party", "3712545394888");

		assertEquals(1, e.countVotes(party));
		assertEquals(1, e.countVotes(candidate));
	}

	@Test(timeout = 1000)
	public void testVoteCandidateOnly() throws InvalidActionException {
		Calendar date = Calendar.getInstance();
		date.set(1988, 6, 2);
		ArrayList<Person> people = new ArrayList<Person>();
		Person voter = new Civilian("8054248738", "Brice Ryan", date, "Mrs");
		people.add(voter);
		Election e = new Election("Parliment", people);
		Votable party = new Party("test party");
		e.addVotable(party);
		Votable candidate = new Independent("3712545394888",
				"Sarai Gusikowski", date, "Mr");
		e.addVotable(candidate);

		e.vote("8054248738", "", "3712545394888");

		assertEquals(0, e.countVotes(party));
		assertEquals(1, e.countVotes(candidate));
	}

	@Test(timeout = 1000)
	public void testPartyWinner() throws InvalidActionException {
		Calendar date = Calendar.getInstance();
		date.set(1988, 6, 2);
		ArrayList<Person> people = new ArrayList<Person>();
		Person voter = new Civilian("8054248738", "Brice Ryan", date, "Mrs");
		Person voter2 = new Civilian("30705657620659", "Carlee Tromp", date,
				"Mr");
		people.add(voter);
		people.add(voter2);
		Election e = new Election("Parliment", people);
		Votable party = new Party("test party");
		Votable party2 = new Party("test party 2");
		e.addVotable(party);
		e.addVotable(party2);
		Votable candidate = new Independent("3712545394888",
				"Sarai Gusikowski", date, "Mr");
		e.addVotable(candidate);

		e.vote("30705657620659", "test party", "3712545394888");
		e.vote("8054248738", "test party", "3712545394888");

		assertEquals(party, e.getPartyWinner());
	}

	@Test(timeout = 1000)
	public void testWinner() throws InvalidActionException {
		Calendar date = Calendar.getInstance();
		date.set(1988, 6, 2);
		ArrayList<Person> people = new ArrayList<Person>();
		Person voter = new Civilian("8054248738", "Brice Ryan", date, "Mrs");
		Person voter2 = new Civilian("30705657620659", "Carlee Tromp", date,
				"Mr");
		people.add(voter);
		people.add(voter2);
		Election e = new Election("Parliment", people);
		Votable party = new Party("test party");
		e.addVotable(party);
		Votable candidate = new Independent("3712545394888",
				"Sarai Gusikowski", date, "Mr");
		Votable candidate2 = new Farmer("826187510453622", "Jaycee Bartell",
				date, "Mrs");
		e.addVotable(candidate);
		e.addVotable(candidate2);

		e.vote("30705657620659", "test party", "3712545394888");
		e.vote("8054248738", "test party", "3712545394888");

		assertEquals(candidate, e.getWinner());
	}
}
