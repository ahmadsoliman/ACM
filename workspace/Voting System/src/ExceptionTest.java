import static org.junit.Assert.fail;
import java.util.ArrayList;
import java.util.Calendar;

import org.junit.Test;
import static org.junit.Assert.assertTrue;
import eg.edu.guc.voting.Election;
import eg.edu.guc.voting.exceptions.InvalidActionException;
import eg.edu.guc.voting.exceptions.InvalidVoterException;
import eg.edu.guc.voting.exceptions.MultipleVoteException;
import eg.edu.guc.voting.exceptions.VotableNotFoundException;
import eg.edu.guc.voting.exceptions.VotingException;
import eg.edu.guc.voting.participants.Civilian;
import eg.edu.guc.voting.participants.Independent;
import eg.edu.guc.voting.participants.Officer;
import eg.edu.guc.voting.participants.Party;
import eg.edu.guc.voting.participants.Person;
import eg.edu.guc.voting.participants.Votable;

public class ExceptionTest {
	@Test(timeout = 1000)
	public void hasInvalidActionExceptionConstrutor() {
		new InvalidActionException();
	}

	@Test(timeout = 1000)
	public void hasVotingExceptionConstrutor() {
		new VotingException();
	}

	@Test(timeout = 1000)
	public void hasVotableNotFoundExceptionConstrutor() {
		new VotableNotFoundException();
	}

	@Test(timeout = 1000)
	public void hasInvalidVoterExceptionConstrutor() {
		new InvalidVoterException();
	}

	@Test(timeout = 1000)
	public void hasMultipleVoteExceptionConstrutor() {
		new MultipleVoteException();
	}

	@Test(timeout = 1000)
	public void testHierarchy() {
		assertTrue(new VotingException() instanceof InvalidActionException);
		assertTrue(new VotableNotFoundException() instanceof VotingException);
		assertTrue(new InvalidVoterException() instanceof VotingException);
		assertTrue(new MultipleVoteException() instanceof VotingException);
	}

	@Test(timeout = 1000)
	public void testThrowningVotableNotFoundException() {
		Calendar date = Calendar.getInstance();
		date.set(1988, 6, 2);
		ArrayList<Person> people = new ArrayList<Person>();
		Person voter = new Civilian("8054248738", "Brice Ryan", date, "Mrs");
		people.add(voter);
		Election election = new Election("Parliment", people);
		try {
			election.vote("8054248738", "test party", "3712545394888");
			fail("VotableNotFoundException must be thrown");
		} catch (Exception e) {
			if (!(e instanceof VotableNotFoundException)) {
				fail("thrown exception must be of type VotableNotFoundException");
			}
		}
	}

	@Test(timeout = 1000)
	public void testThrowingMultipleVoteException() throws InvalidActionException {
		Calendar date = Calendar.getInstance();
		date.set(1988, 6, 2);
		ArrayList<Person> people = new ArrayList<Person>();
		Person voter = new Civilian("8054248738", "Brice Ryan", date, "Mrs");
		people.add(voter);
		Election election = new Election("Parliment", people);
		Votable party = new Party("test party");
		election.addVotable(party);
		Votable candidate = new Independent("3712545394888",
				"Sarai Gusikowski", date, "Mr");
		election.addVotable(candidate);
		election.vote("8054248738", "test party", "3712545394888");
		try {
			election.vote("8054248738", "test party", "3712545394888");
			fail("MultipleVoteException must be thrown");
		} catch (Exception e) {
			if (!(e instanceof MultipleVoteException)) {
				fail("thrown exception must be of type MultipleVoteException");
			}
		}
	}

	@Test(timeout = 1000)
	public void testThrowningInvalidVoterException() {
		Calendar date = Calendar.getInstance();
		date.set(1988, 6, 2);
		ArrayList<Person> people = new ArrayList<Person>();
		Person voter = new Officer("16020615198", "Macie Maggio", date, "Captain");
		people.add(voter);
		Election election = new Election("Parliment", people);
		Votable party = new Party("test party");
		election.addVotable(party);
		Votable candidate = new Independent("3712545394888",
				"Sarai Gusikowski", date, "Mr");
		election.addVotable(candidate);
		try {
			election.vote("16020615198", "test party", "3712545394888");
			fail("InvalidVoterException must be thrown");
		} catch (Exception e) {
			if (!(e instanceof InvalidVoterException)) {
				fail("thrown exception must be of type InvalidVoterException");
			}
		}
	}
}
