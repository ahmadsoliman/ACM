#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long arr[200005], cumm[200005], pre[200005], preI[200005];

int main(){
    int t, n, k, c, i, j,a,b, maxI;
    long long sum, maxsum;


    scanf("%d %d", &n, &k);

    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        cumm[i]=arr[i];
        if(i>0) cumm[i]+=cumm[i-1];
    }

    maxsum=0;
    maxI=n;
    for(i=n-k; i>=0; i--){
        sum = (cumm[i+k-1]-cumm[i]+arr[i]);
        if(sum>=maxsum) {
            maxsum=sum;
            maxI=i;
        }
        pre[i]=maxsum;
        preI[i]=maxI;
    }

    maxsum=0;
    for(i=0; i<n-k; i++){
        sum = (cumm[i+k-1]-cumm[i]+arr[i]) + pre[i+k];
        if(sum>maxsum) { a=i; b=preI[i+k]; maxsum = sum;}
    }

    printf("%d %d\n", a+1, b+1);
    return 0;
}
