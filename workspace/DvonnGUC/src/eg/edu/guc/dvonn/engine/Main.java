package eg.edu.guc.dvonn.engine;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader stdin = new BufferedReader(new InputStreamReader(
				System.in));

		int rows, columns;
		while (true) {
			System.out.println("Please Enter No of rows:");
			String s = stdin.readLine();
			try {
				rows = Integer.parseInt(s);
				break;
			} catch (Exception e) {
			}
		}
		while (true) {
			System.out.println("Please Enter No of columns:");
			String s = stdin.readLine();
			try {
				columns = Integer.parseInt(s);
				break;
			} catch (Exception e) {
			}
		}
		Board b = new Board(rows, columns);
		boolean random = false;
		while (true) {
			System.out
					.println("Do you want to start with a random board? (y/n)");
			String s = stdin.readLine();
			if (s.equals("y")) {
				b.fillRandom();
				random = true;
				break;
			} else if (s.equals("n")) {
				break;
			}
		}
		if (!random) {
			while (b.getCurrentPhase() == 0) {
				System.out.println(b);
				System.out.println(((b.getTurn() == Board.PLAYER1) ? "White"
						: "Black") + " Plays:");
				while (true) {
					System.out
							.println("Please Enter the Coordinates where to Put the Ring \"#row,#col\":");
					String s = stdin.readLine();
					try {
						String[] putCo = s.split(",");
						if (b.put(Integer.parseInt(putCo[0]),
								Integer.parseInt(putCo[1]))) {
							break;
						}
					} catch (Exception e) {
					}
				}
			}
		}

		while (!b.isGameOver()) {
			System.out.println(b);
			System.out.println(((b.getTurn() == Board.PLAYER1) ? "White"
					: "Black") + " Plays:");
			while (true) {
				System.out
						.println("Please Enter the Coordinates from and where to Move \"#row,#col,#row,#col\":");
				String s = stdin.readLine();
				try {
					String[] putCo = s.split(",");
					if (b.move(Integer.parseInt(putCo[0]),
							Integer.parseInt(putCo[1]),
							Integer.parseInt(putCo[2]),
							Integer.parseInt(putCo[3]))) {
						break;
					}
				} catch (Exception e) {
				}
			}
		}
		System.out.println(b);
		System.out.println(((b.getWinner() == Board.PLAYER1) ? "White"
				: "Black") + " Wins!");

	}
}
