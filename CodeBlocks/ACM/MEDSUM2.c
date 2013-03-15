#include <stdio.h>

int arr[205][20005], L;

int binarySearch(int i, int j){
    int low=0, high=L-1, mid=-1, median=-1, k;
    while(1){
        if((low+high)/2==mid){
            mid = high;
            if(L-mid-2<0)break;
            if(arr[j][mid]>=arr[i][L-mid-2]){
                if(arr[j][mid]<=arr[i][L-mid-1]){
                    median = arr[j][mid];
                    break;
                }
            }
        }
        mid = (low+high)/2;
        if(arr[j][mid]>=arr[i][L-mid-2]){
            if(arr[j][mid]<=arr[i][L-mid-1]){
                median = arr[j][mid];
                break;
            }else{
                high = mid;
            }
        }else{
            low = mid+1;
        }
    }
    return median;
}

int main(){
    int n, i, j, med;
    long long sum;
    scanf("%d", &n);
    scanf("%d", &L);
    for(i=0; i<n; i++){
        for(j=0; j<L; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    sum = 0LL;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            med = -1;
            if(arr[i][L-1]<=arr[j][0])
                med = arr[i][L-1];
            if(arr[j][L-1]<=arr[i][0])
                med = arr[j][L-1];
            if(med<0) med = binarySearch(i, j);
            if(med<0) med = binarySearch(j, i);
            sum+=med;
            if(sum>1000000000)sum%=1000000000;
        }
    }
    printf("%lld\n", sum);
    return 0;
}
