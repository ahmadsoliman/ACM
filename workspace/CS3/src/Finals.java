
public class Finals {
	public static void main(String[] args){
//		System.out.println(isBalanced("( a (+) x )")?"Balanced":"Not Balanced");
		
//		Stack s = new Stack(5);
//		s.push(3);s.push(1);s.push(5);s.push(2);s.push(4);
//		stack(s);
//		while(!s.isEmpty()) System.out.print(s.pop()+ " ");
		
		DoublyLinkedList dll = new DoublyLinkedList();
		dll.insertLast(1);dll.insertLast(3);dll.insertLast(2);dll.insertLast(5);
		DoublyLinkedList dll2 = dll.weirdDiff();
		dll.displayForward();
		dll2.displayForward();

		}
	
	public static boolean isBalanced(String s){
		String[] chars = s.split("");
		StackObj sTemp = new StackObj(chars.length);
		
		for(int i=1; i<chars.length;i++){
			char c = chars[i].charAt(0);
//			if(c==' '||Character.isLetter(c)||Character.isDigit(c)) continue;
			if(c=='(') sTemp.push(c);
			if(c==')'){
				if(sTemp.isEmpty()) return false;
				else sTemp.pop();
			}
		}
		return sTemp.isEmpty();
	}

	public static void stack(Stack s){
		Stack tmp1 = new Stack(s.size());
		Stack tmp2 = new Stack(s.size());
		tmp1.push(s.pop());
		
		while(!s.isEmpty()){
			int x = s.pop();
			while(!tmp1.isEmpty() && x<tmp1.top()) tmp2.push(tmp1.pop());
			tmp1.push(x);
			while(!tmp2.isEmpty()) tmp1.push(tmp2.pop());
		}
		while(!tmp1.isEmpty()) s.push(tmp1.pop());
	}
}
