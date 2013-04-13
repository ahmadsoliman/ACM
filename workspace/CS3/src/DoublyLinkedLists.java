
public class DoublyLinkedLists {
	public static void main(String[] args){
		DoublyLinkedList l = new DoublyLinkedList();
		for(int i=4; i<15; i++)	l.insertLast(i);
//		l.deleteKey(4);
//		l.insertToSorted(4);
		l.reverseRec();
		l.displayForward();
	}
}
