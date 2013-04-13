package topCoder;

import java.util.LinkedList;
import java.util.PriorityQueue;

public class SRM556 {
	
	public static void main(String[] args) {
		System.out.println( maxLength("thisisansrmbeforetopcoderopenfinals"));
	}
	
	//250
	public static  int maxLength(String letters){ 
		return recur(letters).length();
	}
	public static String recur(String str){
		if(str==null||str.equals("")) return ""; 
		if(notRepeated(str)) return str;
		
		String left = recur(str.substring(1,str.length()));
		String right = recur(str.substring(0, str.length()-1));
		if (left.length()>right.length()) {
			return left;
		}
		return right;
	}
	public static boolean notRepeated(String str){
		for (int i = 0; i < str.length()-1; i++) {
			if (str.indexOf(str.charAt(i),i+1)!=-1) {
				return false;
			}
		}
		return true;
	}
	
	
	
	//500
	public static  int maxProfit(int[] cityValues, String[] roads){
		LinkedList<Integer>[] adj = new LinkedList[roads.length];
		for (int i = 0; i < roads.length; i++) {
			adj[i] = new LinkedList<Integer>();
			for (int j = 0; j < roads[0].length(); j++) {
				if(roads[i].charAt(j)=='Y') adj[i].addLast(new Integer(j));
			}
		}
		int[] highest = dijkstra(adj, 0, cityValues);

		int max = 0;
		for (int i = 0; i < highest.length; i++) {
			max = Math.max(max, highest[i]);
		}
		
		return max;
	}
	
	public static int[] dijkstra(LinkedList<Integer>[] adj, int start, int[] cityValues){
		int[] shortest = new int[adj.length];
		for(int i=0; i<shortest.length; i++){
			shortest[i] = 0;
		}
		boolean[] visited = new boolean[adj.length];
		PriorityQueue<Node1> pq = new PriorityQueue<Node1>();
		pq.add(new Node1(cityValues[start],start));
	
		while(!pq.isEmpty()){
			int node = pq.peek().getNode();
			int cost = pq.peek().getCost();
			pq.remove();
			if(!visited[node]){
				visited[node] = true;
				shortest[node] = Math.max(shortest[node],cost);
				for(Integer v : adj[node]){
					if(!visited[v.intValue()] && shortest[v]<cost){//optimized
						String one = Integer.toBinaryString(cost);
						String two = Integer.toBinaryString(cityValues[v]);
						int len = Math.max(one.length(), two.length());
						StringBuffer str = new StringBuffer();
						for (int i = 0; i < len; i++) {
							int i1=1,i2=1;
							if (i>=one.length()||one.charAt(i)=='0') i1=0;
							if (i>=two.length()||two.charAt(i)=='0') i2=0;
							str.append((i1+i2)%2);
						}
						pq.add(new Node1(cost+Integer.parseInt(str.toString(),2), v.intValue()));
						shortest[node] = cost;//optimized
					}
				}
			}
		}		
		return shortest;
	}
}
class Node1 implements Comparable<Object>{
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
	public Node1(int cost, int node) {
		super();
		this.cost = cost;
		this.node = node;
	}
	
	public int compareTo(Object arg0) {
		Node1 n = (Node1)arg0;
		if(n.getCost()==getCost()) 	return 0;
		if(getCost()>n.getCost()) return 1;
		else return -1;
	}
	
}
