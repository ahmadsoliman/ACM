package eg.edu.guc.voting;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Calendar;

import eg.edu.guc.voting.exceptions.*;
import eg.edu.guc.voting.participants.*;

public class Organizer {
	static Election[] elections;
	private int[] elegibleVoters;

	private Calendar makeDate(String s) {
		String[] dateNums = s.split("/");
		Calendar date = Calendar.getInstance();
		date.set(Calendar.DAY_OF_MONTH, Integer.parseInt(dateNums[1]));
		date.set(Calendar.MONTH, Integer.parseInt(dateNums[0]));
		date.set(Calendar.YEAR, Integer.parseInt(dateNums[2]));
		return date;
	}

	private Person makePerson(String line) {
		String[] data = line.split(",");
		Calendar date = makeDate(data[3]);
		Person p = null;
		if (data[0].equals("Officer")) {
			p = new Officer(data[1], data[2], date, data[4]);
		} else if (data[0].equals("Civilian")) {
			p = new Civilian(data[1], data[2], date, data[4]);
		}
		return p;
	}

	private Candidate makeCandidate(String line) {
		String[] data = line.split(",");
		Calendar date = makeDate(data[3]);
		Candidate c = null;
		if (data[0].equals("Farmer")) {
			c = new Farmer(data[1], data[2], date, data[4]);
		} else if (data[0].equals("Independent")) {
			c = new Independent(data[1], data[2], date, data[4]);
		} else if (data[0].equals("Worker")) {
			c = new Worker(data[1], data[2], date, data[4]);
		}
		return c;
	}

	public Organizer(Reader reader) throws IOException {
		BufferedReader fileIn = new BufferedReader(reader);
		int n = Integer.parseInt(fileIn.readLine());
		elections = new Election[n];
		elegibleVoters = new int[n];

		for (int i = 0; i < n; i++) {
			ArrayList<Person> people = new ArrayList<Person>();
			String line = fileIn.readLine();
			elegibleVoters[i] = 0;
			while (!line.equals("")) {
				Person p = makePerson(line);
				if (p != null) {
					people.add(p);
					if (p.isEligibleToVote()) {
						elegibleVoters[i]++;
					}
				}
				line = fileIn.readLine();
			}

			elections[i] = new Election("Election Number " + i, people);
			line = fileIn.readLine();
			while (!line.equals("")) {
				Candidate c = makeCandidate(line);
				elections[i].addVotable(c);
				line = fileIn.readLine();
			}

			int numParties = Integer.parseInt(fileIn.readLine());

			for (int j = 0; j < numParties; j++) {
				Party p = new Party(fileIn.readLine());
				int numMembers = Integer.parseInt(fileIn.readLine());
				for (int k = 0; k < numMembers; k++) {
					line = fileIn.readLine();
					String[] data = line.split(",");
					Calendar date = makeDate(data[2]);
					Candidate c = new Farmer(data[0], data[1], date, data[3]);
					p.addMember(c);
				}
				elections[i].addVotable(p);
			}
			fileIn.readLine();

			while (!line.contains("#")) {
				line = fileIn.readLine();
				String[] data = line.split(",");
				try {
					elections[i].vote(data[0], data[1], data[2]);
				} catch (Exception e) {

				}
			}
		}

	}

	public String toString() {
		String s = "";
		for (int i = 0; i < elections.length; i++) {
			s += (i + 1) + ")" + "Election has " + elegibleVoters[i]
					+ " voters, " + elections[i].countCandidates()
					+ " candidates, and " + elections[i].countParties()
					+ " parties.\n";
		}
		return s;
	}

	public static void main(String[] args) throws IOException {
		String input = "Please enter the election number you would "
				+ "like to show its results or 0 to exit:\n" + "-->>>";
		Organizer o = new Organizer(new FileReader(new File("data.txt")));
		System.out.print("Hello, and welcome to the GUC Voting Simulation.\n"
				+ "Today’s elections are:\n" + "----------------------\n");
		System.out.print(o.toString());
		System.out.print(input);
		int num;
		String inp;
		BufferedReader stdin = new BufferedReader(new InputStreamReader(
				System.in));
		do {
			try {
				inp = stdin.readLine();
				num = Integer.parseInt(inp);
				if (num < 0 || num > elections.length) {
					System.out.println("Enter a valid input!");
					continue;
				}
				break;
			} catch (Exception e) {
				System.out.println("Enter a valid input!");
			}

		} while (true);
		while (num != 0) {
			num = Integer.parseInt(inp) - 1;
			int count = 1;
			System.out.print("The voting results are:\n" + "For Candidates:\n");
			for (int i = 0; i < elections[num].votables.size(); i++) {
				if (elections[num].votables.get(i) instanceof Candidate) {
					System.out.print(count
							+ ") Candidate "
							+ count
							+ " "
							+ ((Candidate) elections[num].votables.get(i))
									.getName()
							+ " got "
							+ elections[num].countVotes(elections[num].votables
									.get(i)) + " votes.\n");
					count++;
				}
			}
			Candidate won = elections[num].getWinner();
			if (won != null) {
				System.out
						.println("\nThe winning Candidate is " + won.getName()
								+ " with the ID " + won.getId() + ".\n");
			}
			count = 1;
			System.out.print("For Parties:\n");
			for (int i = 0; i < elections[num].votables.size(); i++) {
				if (elections[num].votables.get(i) instanceof Party) {
					System.out.print(count
							+ ") Party "
							+ count
							+ " "
							+ elections[num].votables.get(i).getId()
							+ " got "
							+ elections[num].countVotes(elections[num].votables
									.get(i)) + " votes.\n");
					count++;
				}
			}
			if (won != null) {
				System.out.println("\nThe winning Party is "
						+ elections[num].getPartyWinner().getId() + ".\n");
			}
			System.out.print(input);
			do {
				try {
					inp = stdin.readLine();
					num = Integer.parseInt(inp);
					if (num < 0 || num > elections.length) {
						System.out.println("Enter a valid input!");
						continue;
					}
					break;
				} catch (Exception e) {
					System.out.println("Enter a valid input!");
				}
			} while (true);
		}
		System.out.println("Thanks for your participation!");
	}

}
