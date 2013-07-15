#include <stdio.h>

typedef struct{
    int x,y;
}pair1;

int compare (const void * a, const void * b) {
  return ( (*(pair1*)a).y - (*(pair1*)b).y );
}

int binarySearch(int a[], int low, int high, int target) {
    if (high < low)
        return -1;
    int middle = (low + high)/2;
    if (target < a[middle])
        return binary_search(a, low, middle-1, target);
    else if (target > a[middle])
        return binary_search(a, middle+1, high, target);
    else if (target == a[middle])
        return middle;
}

int n, dp[1001], c[1001];
pair1 pairs[1001];

int main(){
    int t,i,j,v,sz;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=0; i<n; i++) { scanf("%d", &v); pair1 tmp; tmp.x=v; pairs[i]=tmp;}
        for(i=0; i<n; i++) { scanf("%d", &v); pairs[i].y=v;}
        qsort(pairs, n, sizeof(pair1), compare);

        sz = 1;
        c[1] = pairs[0].x;
        dp[0] = 1;
        for( int i = 1; i < n; i++) {
           if(pairs[i].x < c[1] ) {
              c[1] = pairs[i].x; /*you have to update the minimum value right now*/
              dp[i] = 1;
           } else if(pairs[i].x > c[sz]) {
              c[sz+1] = pairs[i].x;
              dp[i] = sz+1;
              sz++;
           } else {
              int k = binary_search(c, c+sz, pairs[i].x, myfunction); /*you want to find k so that c[k-1]<array[i]<c[k]*/
              c[k] = pairs[i].x;
              dp[i] = k;
           }
        }

        printf("%d\n", dp[n-1]);
    }
    return 0;
}
