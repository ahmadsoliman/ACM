package topCoder;

public class SRM444 {
	// 250
	public static int maxScore(String[] grid) {
		int maxScore = 0;
		boolean[][] board = new boolean[2][grid[0].length()];
		for (int i = 0; i < grid[0].length(); i++) {
			if(!board[0][i]&&grid[0].charAt(i)=='1'){
				board[0][i] = true;
				maxScore+=1;
				if(i<grid[0].length()-1&&grid[0].charAt(i+1)=='1'&&grid[1].charAt(i)=='1'&&grid[1].charAt(i+1)=='1'){
					board[0][i+1] = true;
					board[1][i] = true;
					board[1][i+1] = true;
					maxScore+=15;
				}
			}
			if(grid[1].charAt(i)=='1'&&!board[1][i]){
				board[1][i] = true;
				maxScore+=1;
			}
		}
		
		for (int i = 0; i < grid[0].length(); i++) {
			if(!board[0][i]){
				maxScore+=1;
				if(i<grid[0].length()-1&&!board[0][i+1]&&!board[1][i]&&!board[1][i+1]){
					board[0][i+1] = true;
					board[1][i] = true;
					board[1][i+1] = true;
					maxScore+=15;
				}
			}
			if(!board[1][i]){
				board[1][i] = true;
				maxScore+=1;
			}
		}
		return maxScore;
	}
}
