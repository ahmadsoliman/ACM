package programmingChallenges;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Set;

import Archive.Node;

public class Dijkstra {
	
	public static void main(String[] args) {
		LinkedList<Integer>[] adj = new LinkedList[5];
		for(int i=0; i<adj.length; i++){
			adj[i] = new LinkedList<Integer>();
		}
		adj[0].add(1);
		adj[0].add(2);
		adj[1].add(0);
		adj[1].add(2);
		adj[1].add(3);
		adj[2].add(1);
		adj[2].add(0);
		adj[2].add(3);
		adj[2].add(4);
		adj[3].add(1);
		adj[3].add(2);
		adj[3].add(4);
		adj[4].add(2);
		adj[4].add(3);
	
		int minSum = Integer.MAX_VALUE;
		int minI = 0;
		for(int i=0; i<adj.length; i++){
			int[] cur = dijkstra(adj,i);
			int sum = 0;
			for(int j=0; j<cur.length; j++){
				sum+=cur[j];
			}
			if(sum<minSum) {
				minSum = sum;
				minI = i;
			}
		}
		
		System.out.println("i: " + minI + " & sum = " + minSum);
		
	}
	
	public static int[] dijkstra(LinkedList<Integer>[] adj, int start){
		int[] shortest = new int[adj.length];
		for(int i=0; i<shortest.length; i++){
			shortest[i] = Integer.MAX_VALUE;
		}
		boolean[] visited = new boolean[adj.length];
		PriorityQueue<Node> pq = new PriorityQueue<Node>();
		pq.add(new Node(0,start));
	
		while(!pq.isEmpty()){
			int node = pq.peek().getNode();
			int cost = pq.peek().getCost();
			pq.remove();
			if(!visited[node]){
				visited[node] = true;
				shortest[node] = Math.min(shortest[node],cost);
				for(Integer v : adj[node]){
					if(!visited[v.intValue()] && shortest[v]>cost){//optimized
						pq.add(new Node(cost+1, v.intValue()));//+1 -> +w[node][v]
						shortest[node] = cost;//optimized
					}
				}
			}
		}		
		return shortest;
	}
	
/*floyd .. shortest path between i&j if only v1 till vk from the the graph are included
 * d(k+1,i,j) = min(d(k,i,j),d(k,i,k+1)+d(k,k+1,j) 
 * delta(u,v) <= delta(u,x) + delta(x,v)
 * 
 * for(k: 1 to n)
 * 		for(i: 1 to n)
 * 			for(j: 1 to n)
 * 				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
 * 
 * 
 * */
	
	
}
