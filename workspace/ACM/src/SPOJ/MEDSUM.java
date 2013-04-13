package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class MEDSUM {
	static int[][] arr;
	static int L;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n=Integer.parseInt(st.nextToken()) , med;
		L=Integer.parseInt(st.nextToken());
		long sum=0;
		arr = new int[n][L];
		
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < L; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if(arr[i][L-1]<=arr[j][0])
	                med = arr[i][L-1];
	            else if(arr[j][L-1]<=arr[i][0])
	                med = arr[j][L-1];
	            else{
	                med = binarySearch(j, i);
	                if(med<0) med = binarySearch(i, j);
	                if(med<0){
	                    //med = arr[i][L-2];
	                }
	            }
	            sum=(sum+med)%1000000000;
			}
		}
		System.out.println(sum);
	}
	public static int binarySearch(int i, int j){
		int mid=-1, median=-1, low=0, high=L-1;
	    while(low<=high){
	        if((low+high)/2==mid){
	            mid=high;
	        }else mid = (low+high)/2;
	        if(L-mid-2<0)low=mid+1;
	        else{
	            if(arr[i][mid]>=arr[j][L-mid-2]){
	                if(arr[i][mid]<=arr[j][L-mid-1]){
	                    median=arr[i][mid];
	                    break;
	                }
	                high = mid;
	            }else{
	                low = mid+1;
	            }
	        }
	    }
	    return median;
	}
}
