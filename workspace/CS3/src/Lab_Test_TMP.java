
import java.util.*;
public class Lab_Test_TMP {

    public static void main(String[] args) {
    	Scanner k=new Scanner(System.in);
    	System.out.println("Enter the number");
    	int n=k.nextInt();
    	int r=0;
    	while (n>0){

    		r=n%10;
    		if (r%2==0){
    			n=n/10;
    			r=n%10;
           if (r%2==1){
    			n=n/10;
                r=n%10;
    	    if (r%2==1){
    		    n=n/10;
                r=n%10;
    		if (r%2==0){
                System.out.println("True");
    		}

    		}
    	    }

    		}


    		if (r%2==1){
    			n=n/10;
    			r=n%10;
    		if (r%2==0){
    			n=n/10;
    			r=n%10;
    		if (r%2==0){
    			n=n/10;
    			r=n%10;
    		if (r%2==1){
    			System.out.println("True");
    		}
    		else {
    			System.out.println("False");
    		}
    		}
    		}
    		}


    		n=n/10;



    	}
    	}
}


