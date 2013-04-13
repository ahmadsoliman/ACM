public class Stack {

	int[] a;
	int top;

	public Stack(int maxSize) {
		a = new int[maxSize];
		top = -1;
	}

	public void push(int value) {
		++top;
		a[top] = value;
	}

	public int pop() {
		int temp = a[top];
		top--;
		return temp;
	}

	public int top() {
		return a[top];
	}

	public boolean isEmpty() {
		return (top == -1);
	}

	public boolean isFull() {
		return (top == a.length - 1);
	}

	public int size() {
		return top + 1;
	}
	public void printStack(){
		for(int i=0;i<this.size();i++){
			System.out.print(a[i] +  " ");
		}
		System.out.println();
	}
}
