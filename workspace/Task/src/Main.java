
public class Main {
	public static void main(String[] args){
		Animal[] a = new Animal[3];
		a[0] = new Shark();
		a[1] = new Cow();
		a[2] = new Cat();
		
		for(int i=0; i<a.length; i++)
			System.out.println(a[i]);
	}
}
