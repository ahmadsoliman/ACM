//Ahmad Adel Roshdy Soliman	22-0627 T-5
//Assignment 2 CS-301


public class Assign2 {
	
	public static String encode(String s, int[] key1, int[] key2){
		String noSpaces = s.replaceAll(" ","");
		int max = noSpaces.length();
		QueueObj qKey1 = key1(key1,max);
		QueueObj qKey2 = key2(key2,max);
				
		//Encoding
		
		String res = "";
		char c ;
		for(int i=0; i<s.length(); i++){
			c = s.charAt(i);
			if(c!=' '){
				int charInt = (int)c;
				int offset = ((Integer)qKey1.dequeue()).intValue() + ((Integer)qKey2.dequeue()).intValue();
				if(charInt<91 && charInt>64){
					charInt += offset;
					if(charInt>90) charInt-=26;
				}else{
					charInt += offset;
					if(charInt>122) charInt-=26;
				}
				c = (char)charInt ;
			}
			res+=c;
		}
			
		return res;
	}
	
	public static String decode(String s, int[] key1, int[] key2){
		String noSpaces = s.replaceAll(" ","");
		int max = noSpaces.length();
		QueueObj qKey1 = key1(key1,max);
		QueueObj qKey2 = key2(key2,max);

			
		//Decoding

		String res = "";
		char c ;
		for(int i=0; i<s.length(); i++){
			c = s.charAt(i);
			if(c!=' '){
				int charInt = (int)c;
				int offset = ((Integer)qKey1.dequeue()).intValue() + ((Integer)qKey2.dequeue()).intValue();
				if(charInt<91 && charInt>64){
					charInt -= offset;
					if(charInt<65) charInt+=26;
				}else{
					charInt -= offset;
					if(charInt<97) charInt+=26;
				}
				c = (char)charInt ;
			}
			res+=c;
		}
			
		return res;
		
		
	}
	
	public static QueueObj key1(int[] key1,int max){
		QueueObj qKey1 = new QueueObj(max);
		QueueObj qTemp1 = new QueueObj(max);		
		
		for(int i=0; i<key1.length; i++){
			if(qKey1.isFull()) break;
			qKey1.enqueue(key1[i]);
			qTemp1.enqueue(key1[i]);
		}
		while(!qKey1.isFull()){
			qKey1.enqueue(qTemp1.peek());
			qTemp1.enqueue(qTemp1.dequeue());
		}
		
		return qKey1;
	}
	
	public static QueueObj key2(int[] key2,int max){
		QueueObj qKey2 = new QueueObj(max);
		QueueObj qTemp1 = new QueueObj(max);
		QueueObj qTemp2 = new QueueObj(max);
		StackObj sTemp = new StackObj(max);
		
		for(int i=0; i<key2.length; i++){
			if(qKey2.isFull()) break;
			qTemp1.enqueue(key2[i]);
			sTemp.push(key2[i]);	
		}
		while(!sTemp.isEmpty()) qTemp2.enqueue(sTemp.pop());
		while(!qKey2.isFull()){
			for(int i=0; i<key2.length; i++){
				if(qKey2.isFull()) break;
				qKey2.enqueue(qTemp1.peek());
				qTemp1.enqueue(qTemp1.dequeue());
			}
			for(int i=0; i<key2.length; i++){
				if(qKey2.isFull()) break;
				qKey2.enqueue(qTemp2.peek());
				qTemp2.enqueue(qTemp2.dequeue());
			}
		}
		
		return qKey2;
	}
	
	public static void main (String [] args){
		int[] key1 = {1,4,3};
		int[] key2 = {3,2,4};
		System.out.println(encode("Encrypt", key1 ,key2));
		System.out.println(decode("Itjwevx" , key1 , key2));
	}
}
