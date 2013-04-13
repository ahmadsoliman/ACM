package Archive;

public class Node implements Comparable<Object>{
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
		Node n = (Node)arg0;
		if(n.getCost()==getCost()) 	return 0;
		if(getCost()>n.getCost()) return 1;
		else return -1;
	}
	
}
