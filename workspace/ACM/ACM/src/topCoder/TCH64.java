package topCoder;

import java.awt.Point;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;

public class TCH64 {

	public static void main(String[] args) {
		System.out.println(Arrays.toString(assign(new int[]{0,0},new int[]{20,10})));
	}

	// 250
	public static int getFamily(String[] femaleGeneticTest,
			String[] maleGeneticTest, String[] personalityTest) {
		int maxFam = 0;
		int males = personalityTest.length, females = 0, children = 0;
		if (males == 0)
			return 0;
		females = personalityTest[0].length();
		if (females == 0)
			return 0;
		children = femaleGeneticTest[0].length();
		for (int i = 0; i < males; i++) {
			for (int j = 0; j < females; j++) {
				if (personalityTest[i].charAt(j) == 'Y') {
					int family = 2;
					for (int k = 0; k < children; k++) {
						if (maleGeneticTest[i].charAt(k) == 'Y'
								&& femaleGeneticTest[j].charAt(k) == 'Y')
							family++;
					}
					if (family > maxFam)
						maxFam = family;
				}
			}
		}
		return maxFam;
	}

	// 500
	public static int[] assign(int[] boxMinimum, int[] boxMaximum) {
		int n = 30, length = boxMinimum.length;
		int[] res = new int[length];
		int sumMin=0, sumMax=0;
		for (int i = 0; i < length; i++) {
			sumMin+=boxMinimum[i];
			sumMax+=boxMaximum[i];
		}
		if(sumMin>n||sumMax<n)return new int[]{};
		
		for (int i = 0; i < res.length; i++) {
			res[i]=boxMinimum[i];
			n-=boxMinimum[i];
		}
		
		for (int i = length - 1; i >= 0; i--) {
			if(n<=0)break;
			if (res[i]+n<=boxMaximum[i]) {
				res[i] += n;
				n = 0;
				break;
			} else {
				n -= (boxMaximum[i]-res[i]);
				res[i] = boxMaximum[i];
			}
		}
		if (n == 0)
			return res;
		return new int[] {};
	}

	// 1000
	public static int getMaxPopularity(String[] roads) {
		int n = roads.length;
		LinkedList<Integer>[] graph = new LinkedList[n];
		int[][] w = new int[n][n];
		for (int i = 0; i < n; i++) {
			graph[i] = new LinkedList<Integer>(); 
			for (int j = 0; j < n; j++) {
				if (i == j || roads[i].charAt(j) == '-') {
					continue;
				}
				int cost = Integer.parseInt(roads[i].charAt(j) + "");
				graph[i].add(j);
				w[i][j]=cost;
			}
		}

		int[] shortest = dijkstra(graph, w ,0);
		int max = 0;
		for (int i = 1; i < n; i++) {
			if (shortest[i] > max)
				max = shortest[i];
		}
		int sleepingTime = 0;
		for (int i = 1; i < n; i++) {
			sleepingTime += (max - shortest[i]);
		}
		return sleepingTime;
	}

	public static int[] dijkstra(LinkedList<Integer>[] adj, int[][] w,int start) {
		int[] shortest = new int[adj.length];
		for (int i = 0; i < shortest.length; i++) {
			shortest[i] = Integer.MAX_VALUE;
		}
		boolean[] visited = new boolean[adj.length];
		PriorityQueue<Node> pq = new PriorityQueue<Node>();
		pq.add(new Node(0, start));

		while (!pq.isEmpty()) {
			int node = pq.peek().getNode();
			int cost = pq.peek().getCost();
			pq.remove();
			if (!visited[node]) {
				visited[node] = true;
				shortest[node] = Math.min(shortest[node], cost);
				for (Integer v : adj[node]) {
					if (!visited[v.intValue()] && shortest[v] > cost) {
						pq.add(new Node(cost + +w[node][v], v.intValue()));
						shortest[node] = cost;
					}
				}
			}
		}
		return shortest;
	}
}

class Node implements Comparable<Object> {
	int cost;
	int node;

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

// public static int[] shortestPath(int start, int[][] graph){
// int n = graph.length;
// int[] shortest = new int[n];
// Arrays.fill(shortest, Integer.MAX_VALUE-10);
// boolean[] visited = new boolean[n];
//
// PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
// pq.add(start);
//
// while(!pq.isEmpty()){
// int cur = pq.remove();
// if(!visited[cur]){
// visited[cur] = true;
// for (int i = 0; i < n; i++) {
// if(graph[cur][i]==-1)continue;
// pq.add(i);
//
// }
// }
// }
// return shortest;
// }

