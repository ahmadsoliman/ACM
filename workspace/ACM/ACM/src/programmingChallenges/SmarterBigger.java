package programmingChallenges;

import java.util.Arrays;

public class SmarterBigger{
	
	public static void main(String[] args) {
		longest(new int[]{6008,6000,500,1000,1100,6000,8000,6000,2000},
				new int[]{1300,2100,2000,4000,3000,2000,1400,1200,1900});
	}
	
	static final int MATCH = 0;
	static final int INSERT = 1;
	static final int DELETE = 2; 
	static int[][] m;
	static int[][] p;
	static Elefant[] E;
	
	public static void longest(int[] W, int[] S){
		if(W.length==0||W.length!=S.length) return;		

		//Data Start in W & S from index 1
		m = new int[W.length+1][W.length+1];
		p = new int[W.length+1][W.length+1];
		E = new Elefant[W.length];		
		
		for(int i=0; i<W.length; i++){
			E[i] = new Elefant(i,W[i],S[i]);												
		}

		Arrays.sort(E);
		Arrays.sort(S);
		int[] reversedS = reverse(S);
		
		int[] goal = substring_compare(E,reversedS);
		System.out.println(m[goal[0]][goal[1]]);			
			
		
		reconstruct_path(E, reversedS, goal[0], goal[1]);
	
	}
	
	public static int[] substring_compare(Elefant[] E, int[] W){
		int[] opt = new int[3];
		
		for(int i=1; i<E.length; i++){
			row_init(i);
			col_init(i);
		}

		for(int i=1; i<E.length; i++)
			for(int j=1; j<W.length; j++){
				opt[MATCH] = m[i-1][j-1] + match(E[i-1].getIq(),W[j-1]);
				opt[INSERT] = m[i][j-1] + indel(W[j-1]);
				opt[DELETE] = m[i-1][j] + indel(E[i-1].getIq());

				m[i][j] = opt[MATCH];
				p[i][j] = MATCH;
				for (int k=INSERT; k<=DELETE; k++)
					if (opt[k] < m[i][j]) {
						m[i][j] = opt[k];
						p[i][j] = k;
					}
			}
		
		int[] res = goal_cell(E,W);
		return res;
	}
	
	public static void row_init(int i){
		m[0][i] = 0;
		p[0][i] = -1;
	}
	public static void col_init(int i){
		m[i][0] = i;
		if(i==0)
			p[i][0] = -1;
		else
			p[i][0] = DELETE;
	}

	public static int[] goal_cell(Elefant[] E, int[] W){
		int i = E.length-1, j=0;
		for(int k=1; k<W.length; k++){
			if(m[i][k]<m[i][j]) j=k;
		}
		return new int[]{i,j};
	}

	public static int match(int a, int b){
		if (a == b) return(0);
		else return(1000);//max integer
	}
	
	public static int indel(int a){
		return 1;
	}	
	
	public static void reconstruct_path(Elefant[] E, int[] W, int i , int j){
		if(i<=0||j<=0) return;
		if(p[i][j]==-1) return;

		if (p[i][j] == MATCH) {
			reconstruct_path(E,W,i-1,j-1);
			match_out(E, W, i, j);
			return;
		}
		if (p[i][j] == INSERT) {
			reconstruct_path(E,W,i,j-1);
			insert_out(E,j);
			return;
		}
		if (p[i][j] == DELETE) {
			reconstruct_path(E,W,i-1,j);
			delete_out(W,i);
			return;
		}
	}

	public static void insert_out(Elefant[] E, int j){
		
	}
	public static void delete_out(int[] W, int i){
		
	}
	public static void match_out(Elefant[] E, int[] S,int i, int j){
		if (E[i-1].getIq()==S[j-1]) System.out.println(E[i-1].getIndex()+1);
	}

	public static int[] reverse(int[] x){
		int[] res = new int[x.length];
		int j=0;
		for(int i=x.length-1; i>=0; i--){
			res[j] = x[i];
			j++;
		}
		return res;
	}
}

