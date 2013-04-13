package eg.edu.guc.voting;

import java.util.ArrayList;

import eg.edu.guc.voting.exceptions.InvalidVoterException;
import eg.edu.guc.voting.exceptions.MultipleVoteException;
import eg.edu.guc.voting.exceptions.VotableNotFoundException;
import eg.edu.guc.voting.participants.*;

public class Election {
	String title;
	ArrayList<Person> people;
	ArrayList<Boolean> voted;
	ArrayList<Party> parties;
	ArrayList<Candidate> candidates;
	

	public Election(String title, java.util.ArrayList<Person> people) {
		this.title = title;
		this.people = people;
		parties = new ArrayList<Party>();
		candidates = new ArrayList<Candidate>();
		voted = new ArrayList<Boolean>();
		for(int i =0; i<people.size(); i++){
			voted.add(new Boolean(false));
		}
	}

	public void addVotable(Votable votable) {
		if (votable instanceof Candidate) {
			if (!candidates.contains((Candidate) votable))
				candidates.add((Candidate) votable);
		} else if (votable instanceof Party)
			if (!parties.contains((Party) votable))
				parties.add((Party) votable);

	}

	public int countParties() {
		return parties.size();
	}

	public int countCandidates() {
		return candidates.size();
	}

	public void vote(String voterId, String partyName, String candidateId)
			throws MultipleVoteException, InvalidVoterException,
			VotableNotFoundException {

		for (int i = 0; i < people.size(); i++) {
			if (voterId.equals(people.get(i).getID())) {
				if(voted.get(i)) throw new MultipleVoteException();
				if (people.get(i).isEligibleToVote() == true) {
					
					if (!partyName.equals("")) {
						boolean f = false;
						for (int x = 0; x < parties.size(); x++) {
							if (partyName.equals(parties.get(x).getId()) == true) {
								parties.get(x).giveVote();
								f = true;
							}
						}
						if (!f) {
							throw new VotableNotFoundException();
						}
					}
					if (!candidateId.equals("")) {
						boolean f = false;
						for (int y = 0; y < candidates.size(); y++) {
							if (candidateId.equals(candidates.get(y).getID()) == true) {
								candidates.get(y).giveVote();
								f = true;
							}
						}
						if (!f) {
							throw new VotableNotFoundException();
						}
					}
				} else {
					throw new InvalidVoterException();
				}
				voted.set(i,new Boolean(true));
				break;
			}
		}
			
	}

	public Party getPartyWinner() {
		Party max = parties.get(0);
		for (int i = 0; i < parties.size(); i++) {
			if (parties.get(i).countVotes() > max.countVotes())
				max = parties.get(i);

		}
		return max;
	}

	public Candidate getWinner() {
		Candidate max = candidates.get(0);
		for (int i = 0; i < candidates.size(); i++) {
			if (candidates.get(i).countVotes() > max.countVotes())
				max = candidates.get(i);

		}
		return max;

	}

	public int countVotes(Votable votable) {
		return votable.countVotes();
	}

}
