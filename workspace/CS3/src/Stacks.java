
public class Stacks {
	public static void main(String [] args){
		Stack x = new Stack(10);
		x.push(9);x.push(3);x.push(8);x.push(8);x.push(4);
		
		Stack y = decompose(x);
		x.printStack();
		y.printStack();
		
		System.out.println(check(x));
		x.printStack();
		
		removeNth(x, 2);
		x.printStack();
		
		System.out.println(postfix("2 3 4 + *"));
		
		StackObj s = new StackObj(10);
		s.push("Ahmad");		s.push("Omar");		s.push("Islam");
		StackObj n = new StackObj(10);
		n.push(new Integer(4));n.push(new Integer(2));n.push(new Integer(1));
		StackObj res = createDup(s,n);
		while(!res.isEmpty()) System.out.print(res.pop() + " ");
	}
	
	public static StackObj createDup(StackObj s, StackObj n){
		StackObj ntemp = new StackObj(n.size());
		StackObj stemp = new StackObj(s.size());
		int sum=0;
		while(!n.isEmpty()) {
			sum+=(Integer)n.top();
			ntemp.push(n.pop());
		}
		while(!ntemp.isEmpty()) n.push(ntemp.pop()); 
		StackObj res = new StackObj(sum);
		
		while(!s.isEmpty()){
			String s1 = (String)s.top(); stemp.push(s.pop());
			int n1 = (Integer)n.top();ntemp.push(n.pop());
			for(int i=0; i<n1; i++) res.push(s1);
		}
		while(!stemp.isEmpty()){
			s.push(stemp.pop());
			n.push(ntemp.pop());
		}
		return res;
	}
	
	public static int postfix(String s){
		s = s.replaceAll(" ","");
		Stack temp = new Stack(s.length());
		
		for(int i =0; i<s.length(); i++){
			
			char c = s.charAt(i);
			int cInt = c;
			if(cInt>47 && cInt<58) temp.push(Integer.parseInt(s.charAt(i)+""));
			else{
				int t1=temp.pop();
				int t2=temp.pop();
				temp.push(calc(t2,t1,c));
			}
		}
		return temp.pop();
	}
	
	public static int calc(int x,int y, char c){
		switch(c){
			case '+': return x+y;
			case '-': return x-y;
			case '*': return x*y;
			case '/': return x/y;
			case '%': return x%y;
			default : return 0;
		}
	}
	
	public static void removeNth(Stack s, int n){
		Stack temp = new Stack(s.size());
		int upN = s.size() - n;
		int i =0;
		while(!s.isEmpty()){
			if(i==upN) s.pop();
			else temp.push(s.pop());
			i++;
		}
		while(!temp.isEmpty()) s.push(temp.pop());
	}
	
	public static boolean check(Stack x){
		Stack temp = new Stack(x.size());
		int up = 0 , down=0;
		int size = x.size()/2;
		int i =0;
		
		while(!x.isEmpty()){
			int t = x.pop();
			temp.push(t);
			if(i<size)
				up+=t;
			if(i>size)
				down+=t;
			i++;
		}
		while(!temp.isEmpty()) x.push(temp.pop());
			
		return (up==down);
	}
	
	
	public static Stack decompose(Stack x){
		Stack y = new Stack(x.size());
		Stack ytemp = new Stack(x.size());
		Stack xtemp = new Stack(x.size());
		int i = 0;
		
		while(!x.isEmpty()){
			int t = x.pop();
			if(i%2 == 0) xtemp.push(t);
			else ytemp.push(t);
			i++;
		}
		while(!ytemp.isEmpty()){
			y.push(ytemp.pop());
		}
		while(!xtemp.isEmpty()){
			x.push(xtemp.pop());
		}
		return y;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
