package SPOJ;

public class EASYPROB {
	public static void main(String[] args) {
		
		String[] numbers = new String[15];
		numbers[0] = "2(0)";												//1
		numbers[1] = "2";													//2
		numbers[2] = "2(2)";												//4
		numbers[3] = "2("+numbers[1]+"+"+numbers[0]+")";					//8
		numbers[4] = "2("+numbers[2]+")";									//16
		numbers[5] = "2("+numbers[2]+"+"+numbers[0]+")";
		numbers[6] = "2("+numbers[2]+"+"+numbers[1]+")";
		numbers[7] = "2("+numbers[2]+"+"+numbers[1]+"+"+numbers[0]+")";
		numbers[8] = "2("+numbers[3]+")";
		numbers[9] = "2("+numbers[3]+"+"+numbers[0]+")";
		numbers[10] = "2("+numbers[3]+"+"+numbers[1]+")";
		numbers[11] = "2("+numbers[3]+"+"+numbers[1]+"+"+numbers[0]+")";
		numbers[12] = "2("+numbers[3]+"+"+numbers[2]+")";
		numbers[13] = "2("+numbers[3]+"+"+numbers[2]+"+"+numbers[0]+")";
		numbers[14] = "2("+numbers[3]+"+"+numbers[2]+"+"+numbers[1]+")";
		
		int[] arr = new int[]{137, 1315, 73, 136, 255, 1384, 16385};
		String binary;
		StringBuffer res;
		for (int i = 0; i < arr.length; i++) {
			binary = toBinary(arr[i]);
			res = new StringBuffer();
			for (int j = 0; j < binary.length(); j++) {
				if(binary.charAt(j)=='1'){
					if(res.length()>0)
						res.append("+");
					res.append(numbers[binary.length()-j-1]);
				}
			}
			System.out.println(res);
		}
	}
	public static String toBinary(int i){
		String res = "";
		while(i>0){
			res = i%2 + res;
			i/=2;
		}
		return res;
	}
}
