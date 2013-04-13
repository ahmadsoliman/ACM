import java.util.Scanner;


public class CS1_Lab_Test {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println(" Enter your Number: ");
		int n = sc.nextInt();							//1
		
		boolean flag=true; 								//1
		if((n%10)%2==0){								//1
			while(n>0){									
				if((n%10)%2==1){
					flag=false;
					break;
				}
				n/=10;
				if(n>0){
					if((n%10)%2==0){
						flag=false;
						break;
					}
				}
				n/=10;
				if(n>0){
					if((n%10)%2==0){
						flag=false;
						break;
					}
				}
				n/=10;
			}
		}else{
			while(n>0){
				if((n%10)%2==0){
					flag=false;
					break;
				}
				n/=10;
				if(n>0){
					if((n%10)%2==1){
						flag=false;
						break;
					}
				}
				n/=10;
				if(n>0){
					if((n%10)%2==1){
						flag=false;
						break;
					}
				}
				n/=10;
			}
		}
		if(flag)
			System.out.println("True");
		else
			System.out.println("False");
		
	}
}
