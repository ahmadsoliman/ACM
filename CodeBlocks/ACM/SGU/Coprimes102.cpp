#include <stdio.h>

int gcd(int n, int m){
    if(n==0) return m;
    return gcd(m%n, n);
}

int main(){
    int n, i, cnt;
    scanf("%d", &n);
    cnt=1;
    for(i=2; i<n; i++){
        if(gcd(i, n)==1) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
