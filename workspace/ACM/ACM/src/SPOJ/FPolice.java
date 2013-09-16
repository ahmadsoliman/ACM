package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class FPolice {
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader stdin = new BufferedReader(new InputStreamReader(
				System.in));
		int t = Integer.parseInt(stdin.readLine());
		StringBuffer strBfr = new StringBuffer();
		
		for (int k = 0; k < t; k++) {
			String[] str = stdin.readLine().split(" ");
			int N = Integer.parseInt(str[0]), T = Integer.parseInt(str[1]);
			if(N==0){
				strBfr.append(0);
				strBfr.append(" ");
				strBfr.append(0);
				strBfr.append("\n");
				continue;
			}
			int[][] time = new int[N][N];
			for (int i = 0; i < N; i++) {
				str = stdin.readLine().split(" ");
				for (int j = 0; j < N; j++) {
					time[i][j] = Integer.parseInt(str[j]);
				}
			}
			int[][] risk = new int[N][N];
			for (int i = 0; i < N; i++) {
				str = stdin.readLine().split(" ");
				for (int j = 0; j < N; j++) {
					risk[i][j] = Integer.parseInt(str[j]);
				}
			}
			int[] res = dijkstra1(risk, time, 0, T);
			if (res.length == 1)
				strBfr.append(-1);
			else
				strBfr.append(res[0] + " " + res[1]);
			if (k < t - 1)
				strBfr.append("\n");
		}
		System.out.println(strBfr);
	}

	public static int[] dijkstra1(int[][] risk, int[][] time, int start,
			int maxTime) {
		int[] minRisk = new int[risk.length], minTime = new int[risk.length];
		for (int i = 0; i < minRisk.length; i++) {
			minRisk[i] = Integer.MAX_VALUE;
		}
		boolean[] visited = new boolean[risk.length];
		PriorityQueue<Node> pq = new PriorityQueue<Node>();
		pq.add(new Node(0, start));

		while (!pq.isEmpty()) {
			int node = pq.peek().getNode();
			int cost = pq.peek().getCost();
			int time1 = pq.peek().getTime();
			pq.remove();
			if (!visited[node]) {
				visited[node] = true;

				if (cost < minRisk[node]) {
					minRisk[node] = cost;
					minTime[node] = time1;
				}

				for (int i = 0; i < risk[node].length; i++) {
					if (!visited[i] && minRisk[i] > cost) {
						Node x = new Node(cost + risk[node][i], i);
						x.setTime(time1 + time[node][i]);
						if (x.getTime() > maxTime)
							continue;
						pq.add(x);
						minRisk[node] = cost;
						minTime[node] = time1;
					}
				}
			}
		}
		if (!visited[risk.length - 1])
			return new int[] { -1 };

		return new int[] { minRisk[minRisk.length - 1],
				minTime[minTime.length - 1] };
	}

}

class Node implements Comparable<Object> {
	int cost;
	int node;
	int time;

	public int getTime() {
		return time;
	}

	public void setTime(int time) {
		this.time = time;
	}

	public int getCost() {
		return cost;
	}

	public void setCost(int cost) {
		this.cost = cost;
	}

	public int getNode() {
		return node;
	}

	public void setNode(int node) {
		this.node = node;
	}

	public Node(int cost, int node) {
		super();
		this.cost = cost;
		this.node = node;
	}

	public int compareTo(Object arg0) {
		Node n = (Node) arg0;
		if (n.getCost() == getCost())
			return 0;
		if (getCost() > n.getCost())
			return 1;
		else
			return -1;
	}
}
