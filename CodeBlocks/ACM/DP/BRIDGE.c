#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x,y;
}pair1;

int compare (const void * a, const void * b) {
  return ( (*(pair1*)a).y - (*(pair1*)b).y );
}


int n, dp[1002], c[1002];
pair1 pairs[1002];

int binarySearch(int low, int high, int target) {
    while (low <= high) {
        int middle = (low + high)/2;
        if (target < c[middle]){
            if(target>c[middle-1]) return middle-1;
            high = middle ;
        }else if (target > c[middle]){
            if(target<c[middle+1]) return middle+1;
            low = middle + 1;
        }else
            return middle;
    }
    return -1;
}

int main(){
    int t,i,j,v,sz,maxV;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=0; i<n; i++) { scanf("%d", &v); pair1 tmp; tmp.x=v; pairs[i]=tmp;}
        for(i=0; i<n; i++) { scanf("%d", &v); pairs[i].y=v;}
        qsort(pairs, n, sizeof(pair1), compare);

        maxV =0;
        sz = 1;
        c[1] = pairs[0].x;
        dp[0] = 1;
        for(i = 1; i < n; i++) {
           if(pairs[i].x < c[1] ) {
              c[1] = pairs[i].x; /*you have to update the minimum value right now*/
              dp[i] = 1;
           } else if(pairs[i].x >= c[sz]) {
              c[sz+1] = pairs[i].x;
              dp[i] = sz+1;
              sz++;
           } else {
              int k = binarySearch(0, sz, pairs[i].x); /*you want to find k so that c[k-1]<array[i]<c[k]*/
              c[k] = pairs[i].x;
              dp[i] = k;
           }
           if(dp[i]>maxV)
            maxV=dp[i];
        }

        printf("%d\n", maxV);
    }
    return 0;
}
