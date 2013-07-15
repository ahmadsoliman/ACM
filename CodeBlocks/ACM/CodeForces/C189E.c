#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int n, a[100005], b[100005];

long long recur(int last, int i){
    if(last==n)
        return 0;

    long long d = b[last] * (a[n-1]-1);
    long long c = b[last]*(a[i]-1) + recur(i, i+1);

    return (c<d)?c:d;
}

int main(){
    int i , j;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    for(i=0; i<n; i++) scanf("%d", &b[i]);
    printf("%ld\n", b[0]+recur(0,1));
    return 0;
}


