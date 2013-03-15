#include <stdio.h>

int arr[205][20005];

int main(){
    int n, L, i, j, k, r, l;
    long long sum;
    scanf("%d", &n);
    scanf("%d", &L);
    for(i=0; i<n; i++){
        for(j=0; j<L; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    sum = 0ll;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            k=0;r=0;l=0;
            while(1){
                l++;
                if(arr[i][k]<=arr[j][r]){
                    if(l==L){
                        sum+=arr[i][k];
                        break;
                    }
                    k++;
                }else{
                    if(l==L){
                        sum+=arr[j][r];
                        break;
                    }
                    r++;
                }
            }
            if(sum>1000000000)sum%=1000000000;
        }
    }
    printf("%lld\n", sum);
    return 0;
}
