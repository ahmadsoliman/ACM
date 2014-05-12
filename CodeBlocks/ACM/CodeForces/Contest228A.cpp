#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int gcd(int n, int m){
    if(n==0) return m;
    return gcd(m%n, n);
}

int main(){
    int t, n, c, i;
    //scanf("%d", &t);
    //while(t--){
    scanf("%d", &n);

    int d=0, x;
    for(i=0; i<n; i++){
        scanf("%d", &x);
        d = gcd(d, x);
    }

    printf("%d\n", d*n);
    return 0;
}
