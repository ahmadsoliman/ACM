public class Main {
	public static void main(String[] args) {
		String s = "This is a long string that should be changed";
		System.out.println(change(s));

	}
	
	public static String change(String s){
		if(s==null || s.equals("")) return "";
		String[] words = s.split(" ");
		StringBuffer newS = new StringBuffer();
		for (int i = 0; i < words.length; i++) {
			if ((i+1) % 2 == 0)
				words[i] = "Fizz";
			if ((i+1) % 3 == 0)
				words[i] = "Buzz";
			if ((i+1) % 6 == 0)
				words[i] = "FizzBuzz";
			newS.append(words[i]);
			if(i!=words.length-1)newS.append(" ");
		}
		return newS.toString();
	}
}
