package programmingChallenges;

public class Elefant implements Comparable<Elefant>{
	private int index;
	private int weight;
	private int iq;
	public Elefant(int i, int w, int q){
		index=i;
		weight=w;
		iq=q;
	}
	public int getIndex() {
		return index;
	}
	public void setIndex(int index) {
		this.index = index;
	}
	public int getWeight() {
		return weight;
	}
	public void setWeight(int weight) {
		this.weight = weight;
	}
	public int getIq() {
		return iq;
	}
	public void setIq(int iq) {
		this.iq = iq;
	}
	public int compareTo(Elefant e){
		if(weight==e.getWeight()) return 0;
		if(weight>e.getWeight()) return 1;
		return -1;
	}
}