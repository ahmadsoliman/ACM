#include <stdio.h>
#define min(x,y) ((x<y)?x:y)
#define max(x,y) ((x>y)?x:y)

int arr[100005], dp1[100005], dp2[100005];

int main(){
    int n, i, j, a, b, maxAB;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    dp1[n-1] = arr[n-1];
    dp2[n-1] = 0;
    for(i=n-2; i>=0; i--){
        if(arr[i]>dp1[i+1]){
            dp2[i] = dp1[i+1];
            dp1[i] = arr[i];
        }else{
            dp1[i] = dp1[i+1];
            dp2[i] = max(arr[i], dp2[i+1]);
        }
    }
    for(i=0; i<n; i++)
        printf("%d ", dp1[i]);
    printf("\n");
    for(i=0; i<n; i++)
        printf("%d ", dp2[i]);

    maxAB=0;
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            b = dp2[i];
            if(arr[i]==dp1[i]){
                a = dp1[i];
            }else if(dp1[i]==dp1[j]){
                if(arr[j]==dp1[j]){
                    a = dp1[i];
                }else{

                }
            }
        }
    }
    return 0;
}

