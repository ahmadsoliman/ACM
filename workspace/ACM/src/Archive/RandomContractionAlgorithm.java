package Archive;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;

public class RandomContractionAlgorithm {
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		BufferedReader stdin = new BufferedReader(new FileReader(new File(
				"kargerMinCut.txt")));
		ArrayList<Integer>[] adj = new ArrayList[200];
		ArrayList<Integer> remaining = new ArrayList<Integer>();
		for (int i = 0; i < adj.length; i++) {
			String[] str = stdin.readLine().split("\t");
			adj[i] = new ArrayList<Integer>();
			remaining.add(new Integer(i));
			for (int k = 1; k < str.length; k++) {
				adj[i].add(Integer.parseInt(str[k])-1);
			}
		}
		int N = adj.length * adj.length * (int) Math.ceil(Math.log1p(adj.length-1));
		int min = Integer.MAX_VALUE;
		Random r = new Random();
		for (int i = 0; i < N; i++) {
			while(remaining.size()>2) {
				int ran = r.nextInt(remaining.size());
				int start = remaining.get(ran);
				if (adj[start].size() == 0) {
					remaining.remove(ran);
					continue;
				}
				int end = adj[start].get(r.nextInt(adj[start].size()));
				remaining.remove(new Integer(end));
				
				while (adj[start].remove(new Integer(end)));
				while (adj[end].remove(new Integer(start)));

				while (!adj[end].isEmpty()) {
					int node = adj[end].get(0);
					adj[start].add(node);
					adj[node].add(start);
					adj[node].remove(new Integer(end));
					adj[end].remove(0);
				}
			}
			for (int j = 0; j < adj.length; j++) {
				if (adj[j].size() != 0 && adj[j].size() < min) {
					min = adj[j].size();
				}
			}
		}
		System.out.println(min);
	}

}
