package topCoder;

import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Set;

public class SRM584 {
	public static void main(String[] args) {

	}

	// 250
	public static int possibleHandles(String familyName, String givenName) {
		HashSet<String> set = new HashSet<>();
		for (int i = 1; i < familyName.length(); i++) {
			for (int j = 1; j < givenName.length(); j++) {
				set.add(familyName.substring(0, i) + givenName.substring(0, j));
			}
		}
		return set.size();
	}

	static boolean g[][], vis[];
	public static int bfs(int i, int j){
		LinkedList<Integer> que = new LinkedList<Integer>();
		que.add(i);
		int node,c=0, lev=1; boolean f=false;
		while(!que.isEmpty()){
			node = que.removeFirst();
			if(node==j){
				f=true;
				break;
			}
			lev--;
			if(lev==0)c++;
			if(vis[node]) continue;
			vis[node]=true;
			for (int k = 0; k < g.length; k++) {
				if(g[node][k]) {
					que.add(k);
					lev++;
				}
			}
		}
		return (f)?c:-1;
	}
	public static int maxDifference(String[] isFriend, int d) {
		int max=-1;
		g = new boolean[isFriend.length][isFriend.length];
		for (int i = 0; i < isFriend.length; i++) {
			for (int j = 0; j < isFriend.length; j++) {
				if(isFriend[i].charAt(j)=='Y') g[i][j]=true;
			}
		}
		for (int i = 0; i < isFriend.length; i++) {
			for (int j = i+1; j < isFriend.length; j++) {
				vis = new boolean[isFriend.length];
				max = Math.max(max, bfs(i, j));
			}
		}
		
		return (max==-1)?-1:max*d;
	}
}
