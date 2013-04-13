package eg.edu.guc.voting;

import eg.edu.guc.voting.exceptions.InvalidVoterException;
import eg.edu.guc.voting.exceptions.MultipleVoteException;
import eg.edu.guc.voting.exceptions.VotableNotFoundException;
import eg.edu.guc.voting.participants.Person;
import eg.edu.guc.voting.participants.Candidate;
import eg.edu.guc.voting.participants.Votable;
import eg.edu.guc.voting.participants.Party;
import java.util.ArrayList;


public class Election {
	String title;
	ArrayList<Person> people;
	ArrayList<Boolean> voted;
	ArrayList<Votable> votables;

	public Election(String t, ArrayList<Person> p) {
		title = t;
		people = p;
		votables = new ArrayList<Votable>();
		voted = new ArrayList<Boolean>();
	}

	private boolean isVotable(Votable votable) {
		if (votables.size() == 0) {
			return false;
		}
		return votables.contains(votable);
	}

	public void addVotable(Votable votable) {
		if (!isVotable(votable)) {
			votables.add(votable);
			voted.add(false);
		}
	}

	public int countParties() {
		if (votables.size() == 0) {
			return 0;
		}
		int count = 0;
		for (int i = 0; i < votables.size(); i++) {
			if (votables.get(i) instanceof Party) {
				count++;
			}
		}
		return count;
	}

	public int countCandidates() {
		if (votables.size() == 0) {
			return 0;
		}
		int count = 0;
		for (int i = 0; i < votables.size(); i++) {
			if (votables.get(i) instanceof Candidate) {
				count++;
			}
		}
		return count;
	}

	public void vote(String voterId, String partyName, String candidateId)
			throws VotableNotFoundException, InvalidVoterException,
			MultipleVoteException {
		if (votables.size() == 0) {
			throw new VotableNotFoundException();
		}
		Person voter = null;
		Votable party = null, candidate = null;
		for (int i = 0; i < people.size(); i++) {
			if (people.get(i).getSocialID().equals(voterId)) {
				voter = people.get(i);
				if (voted.get(i)) {
					throw new MultipleVoteException();
				} else {
					voted.set(i, true);
				}
				break;
			}
		}
		if (voter == null || !voter.isEligibleToVote()) {
			throw new InvalidVoterException();
		}

		for (int i = 0; i < votables.size(); i++) {
			if (votables.get(i).getId().equals(partyName)) {
				party = votables.get(i);
			}
			if (votables.get(i).getId().equals(candidateId)) {
				candidate = votables.get(i);
			}
		}
		if (partyName != "") {
			if (party != null) {
				party.giveVote();
			} else {
				throw new VotableNotFoundException();
			}
		}
		if (candidateId != "") {
			if (candidate != null) {
				candidate.giveVote();
			} else {
				throw new VotableNotFoundException();
			}
		}
	}

	public int countVotes(Votable votable) {
		return votable.countVotes();
	}

	public Party getPartyWinner() {
		Votable party = null;
		int maxVotes = 0;
		for (int i = 0; i < votables.size(); i++) {
			if (votables.get(i) instanceof Party) {

				if (votables.get(i).countVotes() > maxVotes) {
					maxVotes = votables.get(i).countVotes();
					party = votables.get(i);
				}
			}
		}
		return (Party) party;
	}

	public Candidate getWinner() {
		Votable candidate = null;
		int maxVotes = 0;
		for (int i = 0; i < votables.size(); i++) {
			if (votables.get(i) instanceof Candidate) {
				if (votables.get(i).countVotes() > maxVotes) {
					maxVotes = votables.get(i).countVotes();
					candidate = votables.get(i);
				}
			}
		}
		return (Candidate) candidate;
	}
}
