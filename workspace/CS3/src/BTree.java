public class BTree {
	public Node root;

	public BTree() {
		root = null;
	}

	public Node find(Comparable key) {
		Node current = root;

		if (current == null)
			return null;

		else {
			while (key.compareTo(current.data) != 0) {
				if (key.compareTo(current.data) < 0)
					current = current.left;

				else
					current = current.right;

				if (current == null)
					return null;
			}
			return current;
		}
	}

	public Node findRec(Comparable key) {
		return findHelper(key, root);
	}

	private Node findHelper(Comparable key, Node current) {
		if (current == null)
			return null;

		else if (key.compareTo(current.data) == 0)
			return current;

		else if (key.compareTo(current.data) < 0)
			return findHelper(key, current.left);

		else
			return findHelper(key, current.right);
	}

	public void add(Comparable key) {
		Node current = root, parent = null;
		while (current != null) {
			if (key.compareTo(current.data) < 0) {
				parent = current;
				current = current.left;
			}

			else{
				parent = current;
				current = current.right;
			}
		}

		if (parent == null)
			root = new Node(key);

		else {
			if (key.compareTo(parent.data) < 0)
				parent.left = new Node(key);

			else
				parent.right = new Node(key);
		}
	}

	public boolean delete(Comparable key) {
		if (root == null)
			return false;
		Node current = root;
		Node parent = root;
		boolean right = true;
		// searching for the node to be deleted
		while (key.compareTo(parent.data) != 0) {
			if (key.compareTo(parent.data) < 0) {
				right = false;
				parent = current;
				current = current.left;
			} else {
				right = true;
				parent = current;
				current = current.right;
			}
			if (current == null)
				return false;
		}

		Node substitute = null;
		//  case 1: Node to be deleted has no children
		if (current.left == null && current.right == null)
			substitute = null;

		//  case 2: Node to be deleted has one child
		else if (current.left == null)
			substitute = current.right;
		else if (current.right == null)
			substitute = current.left;
		else // case 3: Node to be deleted has two children
		{
			Node successor = current.right;
			Node successorParent = current;
			//  searching for the inorder successor of the node to be deleted
			while (successor.left != null) {
				successorParent = successor;
				successor = successor.left;
			}
			substitute = successor;
			if (successorParent == current) {
				if (successor.right == null)
					successorParent.right = null;
				else
					successorParent.right = successor.right;
			} else {
				if (successor.right == null)
					successorParent.left = null;
				else
					successorParent.left = successor.right;
			}
			successor.right = current.right;
			successor.left = current.left;
			substitute = successor;
		} // case 3 done
		if (current == root) // Replacing the deleted node
			root = substitute;
		else if (right)
			parent.right = substitute;
		else
			parent.left = substitute;
		return true;

	}
	
	public void displayTree()
    {
      java.util.Stack<Node> globalStack = new java.util.Stack<Node>();
      globalStack.push(root);
      int nBlanks = 32;
      boolean isRowEmpty = false;
      System.out.println(
      "......................................................");
      while(isRowEmpty==false)
         {
         java.util.Stack<Node> localStack = new java.util.Stack<Node>();
         isRowEmpty = true;

         for(int j=0; j<nBlanks; j++)
            System.out.print(' ');

         while(globalStack.isEmpty()==false)
            {
            Node temp = globalStack.pop();
            if(temp != null)
               {
               System.out.print(temp.data);
               localStack.push(temp.left);
               localStack.push(temp.right);

               if(temp.left != null ||
                                   temp.right != null)
                  isRowEmpty = false;
               }
            else
               {
               System.out.print("--");
               localStack.push(null);
               localStack.push(null);
               }
            for(int j=0; j<nBlanks*2-2; j++)
               System.out.print(' ');
            }  // end while globalStack not empty
         System.out.println();
         nBlanks /= 2;
         while(localStack.isEmpty()==false)
            globalStack.push( localStack.pop() );
         }  // end while isRowEmpty is false
      System.out.println(
      "......................................................");
      }

	public LinkedList path(Comparable key){
		LinkedList res = new LinkedList();
		Node cur = root;
		while(cur!=null){
			if(cur.data.compareTo(key)==0) break;
			res.insertLast(cur.data);
			if(cur.data.compareTo(key)>0) cur = cur.left;
			else cur = cur.right;
		}
		if(cur==null) return null;
		res.insertLast(cur.data);		
		return res;
	}
	
	public int levelRec(Comparable key){
		return levHelper(root, key, 0);
	}
	
	public int levHelper(Node n, Comparable key, int lev){
		if(n==null) return -1;
		if(n.data.compareTo(key)==0)return lev;
		else {
			int x = levHelper(n.left, key, lev+1);
			if(x!=-1) return x;
			int y = levHelper(n.right, key, lev+1);
			if(y!=-1) return y;
		}
		return -1;
	}
	
	public int size(){
		return size(root)+1;
	}
	public int size(Node n){
		if(n==null) return -1;
		return 2 + size(n.left) + size(n.right);
	}
	
	public int numLeaves(){
		return numLeaves(root, 0);
	}
	public int numLeaves(Node n, int num){
		if(n==null) return num;
		if(n.left==null&&n.right==null) return num+1;
		return numLeaves(n.left , num) + numLeaves(n.right , num);		
	}
	
	public int sum(){
		return sum(root);
	}
	public int sum(Node n){
		if(n==null) return 0;
		return (Integer)n.data + sum(n.left) + sum(n.right);
	}
	
	public boolean isBST(){
		return isBST(root);
	}
	public boolean isBST(Node n){
		if(n==null) return true;
		if(n.left!=null)if(n.left.data.compareTo(n.data)>0) return false; 
		if(n.right!=null)if(n.right.data.compareTo(n.data)<0) return false;
		return isBST(n.left) && isBST(n.right);
	}
	
	public void mirror(){
		mirror(root);
	}
	public void mirror(Node n){
		if(n==null)return;
		Node t = n.left;
		n.left = n.right;
		n.right = t;
		mirror(n.left);
		mirror(n.right);
	
	}
	
	public BTree prefix(String s){
		BTree res = new BTree();
		String[] chars = s.split("");
		StackObj sTemp = new StackObj(chars.length);
		
		res.root = new Node(chars[1]);
		Node cur = res.root;
		sTemp.push(cur);
		
		
		
		for(int i=2; i<chars.length; i++){
			char c = chars[i].charAt(0);
			if(!Character.isDigit(c)){
				cur.left = new Node(chars[i]);
				sTemp.push(cur.left);
				cur = cur.left;
			}
			else{
				while(!sTemp.isEmpty()){
					Node temp = (Node)sTemp.pop();
					c = chars[i].charAt(0);
					if(temp.left==null){
						temp.left = new Node(chars[i]);
						if(!Character.isDigit(c)) sTemp.push(temp.left);
						i++;
					}
					c = chars[i].charAt(0);
					temp.right = new Node(chars[i]);
					i++;
					if(!Character.isDigit(c)) sTemp.push(temp.right);
				}
			}
			
		}
		
		return res;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}