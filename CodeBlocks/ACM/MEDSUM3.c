#include <stdio.h>

arr [210][20100], L;

int binarySearch(int i, int j){
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

int main(){
    int n, i, j, med;
    scanf("%d %d", &n, &L);
    for(i=0; i<n; i++){
        for(j=0; j<L; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    long long sum = 0LL;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(arr[i][L-1]<=arr[j][0])
                med = arr[i][L-1];
            else if(arr[j][L-1]<=arr[i][0])
                med = arr[j][L-1];
            else{
                med = binarySearch(j, i);
                if(med<0) med = binarySearch(i, j);
            }
            sum=(sum+med)%1000000000;
        }
    }
    printf("%lld\n", sum);
    return 0;
}
