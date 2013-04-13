package eg.edu.guc.voting;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Calendar;

import eg.edu.guc.voting.exceptions.InvalidVoterException;
import eg.edu.guc.voting.exceptions.MultipleVoteException;
import eg.edu.guc.voting.exceptions.VotableNotFoundException;
import eg.edu.guc.voting.participants.Candidate;
import eg.edu.guc.voting.participants.Civilian;
import eg.edu.guc.voting.participants.Farmer;
import eg.edu.guc.voting.participants.Independent;
import eg.edu.guc.voting.participants.Officer;
import eg.edu.guc.voting.participants.Party;
import eg.edu.guc.voting.participants.Person;
import eg.edu.guc.voting.participants.Worker;

public class Organizer {
	Election[] elections;

	public Organizer(java.io.Reader reader) throws IOException,
			MultipleVoteException, InvalidVoterException {
		BufferedReader br = new BufferedReader(reader);
		String input = br.readLine();
		int numElec = Integer.parseInt(input);

		elections = new Election[numElec];

		for (int i = 0; i < elections.length; i++) {

			ArrayList<Person> people = new ArrayList<Person>();
			input = br.readLine();
			while (!input.equals("")) {
				String[] dataValues = input.split(",");
				String[] dates = dataValues[3].split("/");
				Calendar date = Calendar.getInstance();
				date.set(Calendar.MONTH, Integer.parseInt(dates[0]));
				date.set(Calendar.DAY_OF_MONTH, Integer.parseInt(dates[1]));
				date.set(Calendar.YEAR, Integer.parseInt(dates[2]));

				if (dataValues[0].equals("Officer")) {
					Officer O = new Officer(dataValues[1], dataValues[2], date,
							dataValues[4]);
					people.add(O);
				} else if (dataValues[0].equals("Civilian")) {
					Civilian C = new Civilian(dataValues[1], dataValues[2],
							date, dataValues[4]);
					people.add(C);
				}

				input = br.readLine();
			}
			Election A = new Election("Name", people);
			elections[i] = A;

			input = br.readLine();

			while (!input.equals("")) {
				String[] dataValues = input.split(",");
				String[] dates = dataValues[3].split("/");
				Calendar date = Calendar.getInstance();
				date.set(Calendar.MONTH, Integer.parseInt(dates[0]));
				date.set(Calendar.DAY_OF_MONTH, Integer.parseInt(dates[1]));
				date.set(Calendar.YEAR, Integer.parseInt(dates[2]));

				if (dataValues[0].equals("Independent")) {
					Independent I = new Independent(dataValues[1],
							dataValues[2], date, dataValues[4]);
					elections[i].addVotable(I);
				} else if (dataValues[0].equals("Worker")) {
					Worker W = new Worker(dataValues[1], dataValues[2], date,
							dataValues[4]);
					elections[i].addVotable(W);
				} else if (dataValues[0].equals("Farmer")) {
					Farmer F = new Farmer(dataValues[1], dataValues[2], date,
							dataValues[4]);
					elections[i].addVotable(F);
				}

				input = br.readLine();

			}

			while (!input.equals("")) {
				int n = Integer.parseInt(input);
				for (int k = 0; k < n; k++) {
					input = br.readLine();
					Party party = new Party(input);

					input = br.readLine();
					int numMembers = Integer.parseInt(input);
					for (int z = 0; z < numMembers; z++) {
						input = br.readLine();
						String[] dataValues = input.split(",");
						String[] dates = dataValues[2].split("/");
						Calendar date = Calendar.getInstance();
						date.set(Calendar.MONTH, Integer.parseInt(dates[0]));
						date.set(Calendar.DAY_OF_MONTH,
								Integer.parseInt(dates[1]));
						date.set(Calendar.YEAR, Integer.parseInt(dates[2]));
						Civilian y = new Civilian(dataValues[0], dataValues[1],
								date, dataValues[3]);
						party.addMember(y);
					}
					elections[i].addVotable(party);
				}
				input = br.readLine();
			}

			input = br.readLine();
			if (input.equals(""))
				input = br.readLine();

			while (!input.contains("#")) {
				String[] dataValues = input.split(",");
				try {
					elections[i].vote(dataValues[0], dataValues[1],
							dataValues[2]);
				} catch (Exception e) {

				}
				input = br.readLine();
			}

		}

	}

	public String toString() {
		String s = "";
		int count = 1;
		for (int i = 0; i < elections.length; i++) {
			int voters = 0;
			for (int j = 0; j < elections[i].people.size(); j++) {
				if (elections[i].people.get(j).isEligibleToVote())
					voters++;
			}
			s = s + count + ")" + "Election has " + voters + " voters , "
					+ elections[i].countParties() + " parties\n , and "
					+ elections[i].countCandidates() + " candidates";
			count++;
		}
		return s;
	}

}
