
public class Queues {
	public static void main(String [] args){
		QueueObj Q = new QueueObj(10);
		Q.enqueue(new Integer(1));Q.enqueue(new Integer(2));
		Q.enqueue(new Integer(3));Q.enqueue(new Integer(4));Q.enqueue(new Integer(5));
		
		//mirror(Q);
		//for(int i=0; i<8; i++) System.out.print(Q.dequeue());
		
		System.out.println(evaluate("+ * 5 6 * 2 4"));
		
		
	}
	
	
	public static int evaluate(String s){
		String[] a = s.split(" ");
		QueueObj q = new QueueObj(a.length);
		for(int i=0; i<a.length;i++) q.enqueue(a[i]);
		
		while(true){
			String t1 = (String)q.dequeue();
			char c = t1.charAt(0);
			int cInt = (int)c;
			if(q.isEmpty()) return Integer.parseInt(t1);
			if(cInt>47 && cInt<58) q.enqueue(t1);
			else{
				String t2 = (String)q.peek();
				char c2 = t2.charAt(0);
				if(c2>47 && c2<58) {
					q.dequeue();
					String t3 = (String)q.peek();
					char c3 = t3.charAt(0);
					if(c3>47 && c3<58) {
						q.dequeue();
						q.enqueue(calc(Integer.parseInt(t2),Integer.parseInt(t3),c)+"");
					}
					else{
						q.enqueue(t1);
						q.enqueue(t2);
					}
				}
				else{
					q.enqueue(t1);
				}
			}
		}
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
	
	public static boolean palindrome(String s){
		s = s.toLowerCase();
		StackObj stack = new StackObj(s.length()/2);
		QueueObj queue = new QueueObj(s.length()/2);
		
		for(int i=0; i<s.length(); i++){
			if(i<s.length()/2) stack.push(s.charAt(i)+"");
			else if(s.length()%2!=0 && i==s.length()/2); 
			else queue.enqueue(s.charAt(i)+"");
		}
		while(!stack.isEmpty()){
			if(!((String)stack.pop()).equals((String)queue.dequeue())) return false;
		}
		return true;
	}
	
	
	public static boolean anagram(String s1, String s2){
		if(s1.length()!=s2.length()) return false;
		QueueObj q1 = new QueueObj(s1.length());
		QueueObj q2 = new QueueObj(s2.length());
		for(int i=0; i<s1.length(); i++) q1.enqueue(s1.charAt(i)+"");
		for(int i=0; i<s2.length(); i++) q2.enqueue(s2.charAt(i)+"");
		
		while(!q1.isEmpty()){
			String sTemp = (String)q1.dequeue();
			if(sTemp.equals((String)q2.peek()))		q2.dequeue();
			else q1.enqueue(sTemp); 
		}
		return (q1.isEmpty() && q2.isEmpty());
	}
	
	public static void mirror(QueueObj q){
		QueueObj qTemp = new QueueObj(q.size());
		QueueObj res = new QueueObj(q.size()*2);
		for(int i=0; i<q.size(); i++){
			qTemp.enqueue(q.peek());
			q.enqueue(q.dequeue());
		}
		while(!q.isEmpty()){
			for(int i=0; i<q.size()-1; i++){
				q.enqueue(q.dequeue());
			}
			res.enqueue(q.dequeue());
		}
		while(!qTemp.isEmpty()){
			res.enqueue(qTemp.dequeue());
		}
		while(!res.isEmpty()) System.out.print(res.dequeue());
		System.out.println();
	}
	
	public static void shiftZeros(QueueObj q){
		int count =0;int size =q.size(); 
		for(int i=0; i<size; i++){
				int item = ((Integer)q.dequeue()).intValue();
				if(item==0) count++;
				else q.enqueue(new Integer(item));
		}
		for(int i=0; i<count; i++){
			q.enqueue(0);
		}
	}
	
}
