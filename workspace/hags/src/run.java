import java.io.IOException;

public class run {
	public static void main(String[] args) {
//		A o1 = new A();
//		A o2 = new B();
		B o3 = new B();
//		
//		C c = new C();
		
		
		try{
			bad();
		}
		catch(NullPointerException io){
			
		}
		
		
//		System.out.println(o1.s + "" + "a"); // ---1
//		System.out.println(o1.getx()); // ---1
//		System.out.println(o1.y); // ---2
////		System.out.println(o1.getz()); // ---Does not compile
//		System.out.println(o2.x); // ---1
//		System.out.println(o2.getx()); // ---3
//		System.out.println(o2.y); // ---4
////		System.out.println(o2.getz()); // ---Does not compile
//		System.out.println(o3.x); // ---3
//		System.out.println(o3.getx()); // ---3
//		System.out.println(o3.y); // ---4
//		System.out.println(o3.getz()); // ---5
	}
	
	static void bad(){
		try{
			
		}catch(Exception e){
			
		}
	}
}
